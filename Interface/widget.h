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
/**
 * @brief Widget class is the main interface class
 * @author Oscar Mendez
 * @author Daniela Brenes
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor method
     * @param parent QWidget
     */
    Widget(QWidget *parent = nullptr);

    /***
     * @brief Destructor method
     */
    ~Widget();

private:
    //instances
    Ui::Widget *ui;
    QMediaPlayer *mMediaPlayer;
    Reader* reader;
    QSlider* slider;
    QScrollBar* scroll_bar;
    bool just_changed = false;
    bool pagination = true;
    /**
    * @brief showSongs method that show the songs in the listview
    * @param song_list string that has the data that will be shown in the song list widget
    */
    void showSongs(string song_list);
    /**
     * @brief showArtist method that show the artist int the listview
     * @param artist_list string that has the data that will be shown in the artist list widget
     */
    void showArtists(string artist_list);
    /**
     * @brief setMemoryValue method that calculate the memory usage
     * @param vm_usage double
     * @param resident_set double
     */
    void setMemoryValue(double& vm_usage, double& resident_set);

private slots:
    /**
     * @brief on_playB_clicked method that play the song and take control of the play button
     */
    void on_playB_clicked();
    /**
     * @brief on_pauseB_clicked method that pause the song and take control of the pause button
     */
    void on_pauseB_clicked();
    /**
     * @brief on_stopB_clicked method that stop the song and take control of the stop button
     */
    void on_stopB_clicked();
    /**
     * @brief on_muteB_clicked method that mute and unmute the song and take control of the mute button
     */
    void on_muteB_clicked();
    /**
     * @brief on_volumeBar_valueChanged method that take the value of the volume bar slider
     * @param int value that has the value of the volume slider
     */
    void on_volumeBar_valueChanged(int value);
    /**
     * @brief onPaginateClick method that paginate and the song list and take control of the paginate button
     */
    void onPaginateClick();
    /**
     * @brief playSong method that take the data of a song and play it.
     */
    void playSong();
    /**
     * @brief showArtistSong method that show the songs by artist
     */
    void showArtistSong();
    /**
     * @brief detectScroll method tha detect if the user is scrolling
     */
    void detectScroll();

};
#endif // WIDGET_H
