#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

private slots:
    void on_openB_clicked();

    void on_playB_clicked();

    void on_pauseB_clicked();

    void on_stopB_clicked();

    void on_muteB_clicked();

    void on_volumeBar_valueChanged(int value);

<<<<<<< Updated upstream
private:
    Ui::Widget *ui;
    QMediaPlayer *mMediaPlayer;
=======
    void on_songsLIst_doubleClicked(const QModelIndex &index);

    void on_artistList_doubleClicked(const QModelIndex &index);

    void playSong();


private:
    Ui::Widget *ui;
    QMediaPlayer *mMediaPlayer;
    Reader* reader;
    QSlider* slider;
>>>>>>> Stashed changes
};
#endif // WIDGET_H
