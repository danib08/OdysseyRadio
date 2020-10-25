#include "widget.h"
#include "ui_widget.h"
#include <QMediaPlayer>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);

    connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 position){
        ui->progress->setValue(position);
    });
    connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 duration){
        ui->progress->setMaximum(duration);
    });

    ui->songsLIst->addItem("a");
    ui->songsLIst->addItem("b");
    ui->songsLIst->addItem("c");
    ui->songsLIst->addItem("d");
    ui->songsLIst->addItem("e");
    ui->songsLIst->addItem("f");
    ui->songsLIst->addItem("g");
    ui->songsLIst->addItem("h");
    ui->songsLIst->addItem("i");
    ui->songsLIst->addItem("j");
    ui->songsLIst->addItem("k");
    ui->songsLIst->addItem("l");
    ui->songsLIst->addItem("m");
    ui->songsLIst->addItem("n");
    ui->songsLIst->addItem("o");
    ui->songsLIst->addItem("p");
    ui->songsLIst->addItem("q");
    ui->songsLIst->addItem("r");
    ui->songsLIst->addItem("s");
    ui->songsLIst->addItem("t");
    ui->songsLIst->addItem("u");
    ui->songsLIst->addItem("v");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_openB_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open");
    if (filename.isEmpty()){
        return;
    }
    mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    mMediaPlayer->setVolume(ui->volumeBar->value());
    on_playB_clicked();
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
