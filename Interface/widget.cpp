#include "widget.h"
#include "ui_widget.h"
#include <QMediaPlayer>
#include <QFileDialog>
#include <sstream>
#include <fstream>
#include <QtWidgets/QMessageBox>
#include "CSVManaging/Reader.h"
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
}

Widget::~Widget()
{
    delete ui;
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

void Widget::on_songsLIst_doubleClicked(const QModelIndex &index)
{

}

void Widget::on_artistList_doubleClicked(const QModelIndex &index)
{

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

    int counter = 0;
    while (check.good()) {
        if (counter == 3) {
            break;
        }
        string line;
        getline(check, line, '\n');
        line = line.substr(42, line.length() - 2);

        if (line == filename) {
            file_found = true;
            break;
        }
        counter ++;
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
//    string list_of_songs = reader->getNowPage();
    stringstream check1(song_list);
    string intermediate;

    while(getline(check1, intermediate, '$')) {
        QString qstr = QString::fromStdString(intermediate);
        ui->songsLIst->addItem(qstr);
    }

//    list_of_songs = reader->getAfterPage();
//    stringstream check2(list_of_songs);
//
//    while(getline(check2, intermediate, '$')) {
//        QString qstr = QString::fromStdString(intermediate);
//        ui->songsLIst->addItem(qstr);
//    }
}
