#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <CSVManaging/Reader.h>
#include <QtWidgets/QListWidgetItem>
#include "ui_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
class QMediaPlayer;
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void showSongs(string song_list);
    void setMemoryValue(double& vm_usage, double& resident_set);
private:
    Ui::Widget *ui;
    QMediaPlayer *mMediaPlayer;
    Reader* reader;
    QSlider* slider;
    QScrollBar* scroll_bar;

    void on_artistList_doubleClicked(const QModelIndex &index);

private slots:
    void on_playB_clicked();

    void on_pauseB_clicked();

    void on_stopB_clicked();

    void on_muteB_clicked();

    void on_volumeBar_valueChanged(int value);

    void playSong();

    void detectScroll();

};
#endif // WIDGET_H
