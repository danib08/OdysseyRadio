#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <CSVManaging/Reader.h>


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
    void showSongs();

private slots:
    void on_openB_clicked();

    void on_playB_clicked();

    void on_pauseB_clicked();

    void on_stopB_clicked();

    void on_muteB_clicked();

    void on_volumeBar_valueChanged(int value);

    void on_songsLIst_doubleClicked(const QModelIndex &index);

    void on_artistList_doubleClicked(const QModelIndex &index);

private:
    Ui::Widget *ui;
    QMediaPlayer *mMediaPlayer;
    Reader* reader;
};
#endif // WIDGET_H
