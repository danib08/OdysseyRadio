#include "widget.h"
#include <QMediaPlayer>
#include <sstream>
#include <fstream>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QScrollBar>
#include "CSVManaging/Reader.h"
#include <iostream>
#include <unistd.h>
#include <sys/resource.h>
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);

    reader = new Reader();
    reader->firstRead();
    reader->readArtists();

    showSongs(reader->getNowPage());
    showSongs(reader->getAfterPage());
    showArtists(reader->getArtists());

    connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 position){
        ui->progress->setValue(position);
    });
    connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 duration){
        ui->progress->setMaximum(duration);
    });

    connect(ui->songsLIst, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(playSong()));
    connect(ui->artistList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(showArtistSong()));

    ui->openB->setFixedSize(115, 25);
    ui->openB->setText("Don't Paginate");
    connect(ui->openB, SIGNAL(released()), this, SLOT(onPaginateClick()));

    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    ui->verticalLayout->addWidget(slider);
    connect(mMediaPlayer,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(mMediaPlayer,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,mMediaPlayer,&QMediaPlayer::setPosition);

    scroll_bar = ui->songsLIst->verticalScrollBar();
    connect(scroll_bar, SIGNAL(valueChanged(int)), this, SLOT(detectScroll()));

    memoryLabel = new QLabel("Memory:", this);
}

void Widget::playSong() {
    string path = "/home/dani/Documents/fma_small/";
  
    QString text = ui->songsLIst->selectedItems()[0]->text();

    string song_text = text.toStdString();

    stringstream check1(song_text);
    string id;

    getline(check1, id, ' ');

    string folder;
    string file;

    switch (id.length()) {
        case 6:
            folder = id.substr(0, 3);
            file = id;
            break;
        case 5:
            folder = id.substr(0, 2);
            folder = "0" + folder;
            file = "0" + id;
            break;
        case 4:
            folder = id.substr(0, 1);
            folder = "00" + folder;
            file = "00" + id;
            break;
        case 3:
            folder = "000";
            file = "000" + id;
            break;
        case 2:
            folder = "000";
            file = "0000" + id;
            break;
        default:
            folder = "000";
            file = "00000" + id;
            break;
    }

    string filename = folder + "/" + file + ".mp3";
    bool file_found = false;

    ifstream check;
    check.open("../Metadata/checksums");

    while (check.good()) {
        string line;
        getline(check, line, '\n');
        line = line.substr(42, line.length() - 2);

        if (line == filename) {
            file_found = true;
            break;
        }
    }

    if (file_found) {
        path += filename;
        QString qstr = QString::fromStdString(path);

        mMediaPlayer->setMedia(QUrl::fromLocalFile(qstr));
        mMediaPlayer->setVolume(ui->volumeBar->value());
        on_playB_clicked();
    }
    else {
        QMessageBox* box = new QMessageBox("Song not found", "The selected song is not included in the zip file.",
                                           QMessageBox::Warning, 0, 0, 0);
        box->show();
    }
}

void Widget::showSongs(string song_list) {
    stringstream check1(song_list);
    string intermediate;

    while(getline(check1, intermediate, '$')) {
        QString qstr = QString::fromStdString(intermediate);
        ui->songsLIst->addItem(qstr);
    }
}

void Widget::showArtists(string artist_list) {
    stringstream check1(artist_list);
    string intermediate;

    while(getline(check1, intermediate, '$')) {
        QString qstr = QString::fromStdString(intermediate);
        ui->artistList->addItem(qstr);
    }
}

void Widget::detectScroll() {
    setMemoryValue();
    if (pagination) {
        if (scroll_bar->value() > scroll_bar->minimum() && scroll_bar->value() < scroll_bar->maximum()) {
            just_changed = false;
        }
        if (scroll_bar->value() == scroll_bar->maximum() && !just_changed) {
            int count = ui->songsLIst->count();
            string item_text;
            QListWidgetItem* item;

            if (count == 62) {
                item = ui->songsLIst->item(count - 2);
            }
            else {
                item = ui->songsLIst->item(count - 1);
            }
            item_text = item->text().toStdString();

            stringstream check1(item_text);
            string id;
            getline(check1, id, ' ');

            reader->readDown(id);
            just_changed = true;
            ui->songsLIst->clear();
            showSongs(reader->getBeforePage());
            showSongs(reader->getNowPage());
            showSongs(reader->getAfterPage());
            ui->songsLIst->scrollToItem(ui->songsLIst->item(0));
        }
        if (scroll_bar->value() == scroll_bar->minimum() && !just_changed) {
            string first_text = ui->songsLIst->item(0)->text().toStdString();
            stringstream check1(first_text);
            string first_id;
            getline(check1, first_id, ' ');

            if (first_id != "2") {
                reader->readUp(first_id);
                just_changed = true;
                ui->songsLIst->clear();
                showSongs(reader->getBeforePage());
                showSongs(reader->getNowPage());
                showSongs(reader->getAfterPage());
                ui->songsLIst->scrollToItem(ui->songsLIst->item(ui->songsLIst->count() - 1));
            }
        }
    }
}

void Widget::onPaginateClick() {
    if (pagination) {
        mMediaPlayer->stop();
        ui->openB->setText("Paginate");
        pagination = false;
        reader->readAll();
        ui->songsLIst->clear();
        showSongs(reader->getAllSongs());
        ui->songsLIst->scrollToItem(ui->songsLIst->item(0));
    }
    else {
        mMediaPlayer->stop();
        ui->openB->setText("Don't Paginate");
        pagination = true;
        reader->firstRead();
        just_changed = true;
        ui->songsLIst->clear();
        showSongs(reader->getNowPage());
        showSongs(reader->getAfterPage());
        ui->songsLIst->scrollToItem(ui->songsLIst->item(0));
    }
}

void Widget::showArtistSong() {
    QString qtext = ui->artistList->selectedItems()[0]->text();
    string text = qtext.toStdString();

    mMediaPlayer->stop();
    ui->openB->setText("Paginate");
    pagination = false;
    reader->readArtSongs(text);
    just_changed = true;
    ui->songsLIst->clear();
    showSongs(reader->getArtSongs());
    ui->songsLIst->scrollToItem(ui->songsLIst->item(0));

}

void Widget::setMemoryValue() {
    struct rusage usoMem;
    int ret = getrusage(RUSAGE_SELF,&usoMem);
    int memVal = (usoMem.ru_maxrss*100)/8000000;

    string memory = to_string(usoMem.ru_maxrss);
    memoryLabel->setText(QString::fromStdString(memory) + QString::fromStdString(" kb"));
    ui->memoryBar->setValue(memVal);
}

void Widget::on_playB_clicked()
{
    mMediaPlayer->play();
}

void Widget::on_pauseB_clicked()
{
    mMediaPlayer->pause();
}

void Widget::on_stopB_clicked()
{
    mMediaPlayer->stop();
}

void Widget::on_muteB_clicked()
{
    if (ui->muteB->text()=="MUTE"){
        mMediaPlayer->setMuted(true);
        ui->muteB->setText("UNMUTE");
    }else{
        mMediaPlayer->setMuted(false);
        ui->muteB->setText("MUTE");
    }
}

void Widget::on_volumeBar_valueChanged(int value)
{
    mMediaPlayer->setVolume(value);
}

Widget::~Widget() {
    delete ui;
}
