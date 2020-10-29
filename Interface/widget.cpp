#include "widget.h"
#include <QMediaPlayer>
#include <sstream>
#include <fstream>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QScrollBar>
#include "CSVManaging/Reader.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);
    reader = new Reader();
    reader->firstRead();
    showSongs(reader->getNowPage());
    showSongs(reader->getAfterPage());

    connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 position){
        ui->progress->setValue(position);
    });
    connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 duration){
        ui->progress->setMaximum(duration);
    });

    connect(ui->songsLIst, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(playSong()));

    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    ui->verticalLayout->addWidget(slider);
    connect(mMediaPlayer,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(mMediaPlayer,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,mMediaPlayer,&QMediaPlayer::setPosition);

    scroll_bar = ui->songsLIst->verticalScrollBar();
    connect(scroll_bar, SIGNAL(valueChanged(int)), this, SLOT(detectScroll()));
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

void Widget::on_artistList_doubleClicked(const QModelIndex &index)
{

}

void Widget::playSong() {
    string path = "/home/oscarmg310/Documents/fma_small/";
  
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
        double vm, rss;
        setMemoryValue(vm,rss);
    }

}

void Widget::detectScroll() {
    if (scroll_bar->value() == scroll_bar->maximum()) {
        int count = ui->songsLIst->count();
        string item_text;
        QListWidgetItem* item;
        bool search = false;

        if (count == 40 || count == 61 || count == 63 || count == 64 || count == 69 || count == 75 || count == 67) {
            item = ui->songsLIst->item(count - 1);
            search = true;
        }
        if (count == 62) {
            item = ui->songsLIst->item(count - 2);
            search = true;
        }

        if (search) {
            item_text = item->text().toStdString();

            stringstream check1(item_text);
            string id;
            getline(check1, id, ' ');

            reader->read(id);
            ui->songsLIst->clear();
            showSongs(reader->getBeforePage());
            showSongs(reader->getNowPage());
            showSongs(reader->getAfterPage());
            ui->songsLIst->scrollToItem(ui->songsLIst->item(0));

        }
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setMemoryValue(double& vm_usage, double& resident_set) {
    vm_usage     = 0.0;
    resident_set = 0.0;

    // the two fields we want
    unsigned long vsize;
    long rss;
    {
        std::string ignore;
        std::ifstream ifs("/proc/self/stat", std::ios_base::in);
        ifs >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
            >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
            >> ignore >> ignore >> vsize >> rss;
    }

    long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
    vm_usage = vsize / 1024.0;
    resident_set = rss * page_size_kb;

    int memVal = (800000-resident_set)/100000;
    ui->memoryBar->setValue(memVal);


}
