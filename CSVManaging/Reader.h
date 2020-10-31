//
// Created by dani on 16/10/20.
//

#ifndef ODYSSEYRADIO_READER_H
#define ODYSSEYRADIO_READER_H

#include <iostream>
#include <Lists/SongList.h>
#include <Lists/ArtistList.h>

/**
 * This class reads the csv archives and parses the data.
 */
class Reader {
private:
    int pagination;
    string file_name = "raw_tracks-edited.csv";
    SongList* page_now;
    SongList* page_before;
    SongList* page_after;
    SongList* all_songs;
    SongList* artist_songs;
    ArtistList* artist_list;

public:
    /**
     * Constructor for the Rader class. It instantiates all of the linked lists that are attributes of the class, and
     * sets the pagination attribute to 20.
     */
    Reader();

    /**
     * This method reads the first 40 songs in the csv and parses the data to be displayed on the interface.
     * It adds the songs to the page_now and page_after SongList attributes.
     */
    void firstRead();

    /**
     * Reads and parses 60 songs downwards on the csv from a specific point.
     * The songs then are added to the page_now, page_before and page_after SongList attributes.
     * @param last_id The id of the song that will serve as the starting point.
     */
    void readDown(string last_id);

    /**
     * Reads and parses 60 songs upwards on the csv from a specific point.
     * The songs then are added to the page_now, page_before and page_after SongList attributes.
     * @param last_id The id of the song that will serve as the starting point.
     */
    void readUp(string first_id);

    /**
     * Reads all of the songs on the csv. This is used when the no-pagination mode is chosen by the user.
     * The songs are added to the all_songs SongList attribute.
     */
    void readAll();

    /**
     * This method parses the lines read from the csv. It splits the line using a comma delimitator and then adds the
     * new song to a SongList linked list.
     * @param line The line read from the csv to be parsed.
     * @param flag An integer used in a switch statement. It determines the linked list attribute where the song will
     * be added.
     */
    void splitLine(string line, int flag);

    /**
     * Gets the position (row) of a specific song on the csv file.
     * @param id The id of the song that will be searched.
     * @return An integer: the position of the entered song.
     */
    int getPosition(string id);

    /**
     * Reads all of artists the csv and adds them to the artist_list ArtistList linked list attribute.
     */
    void readArtists();

    /**
     * Searches all of the songs from a specific artist on the csv.
     * @param name The name of the desired artist.
     */
    void readArtSongs(string name);

    /**
     * Returns all of the information on the page_now attribute.
     * @return A string that concatenates all of the info on the page_now attribute.
     */
    string getNowPage();

    /**
     * Returns all of the information on the page_after attribute.
     * @return A string that concatenates all of the info on the page_after attribute.
     */
    string getAfterPage();

    /**
     * Returns all of the information on the page_before attribute.
     * @return A string that concatenates all of the info on the page_before attribute.
     */
    string getBeforePage();

    /**
     * Returns all of the information on the all_songs attribute.
     * @return A string that concatenates all of the info on the all_songs attribute.
     */
    string getAllSongs();

    /**
     * Returns all of the information on the artist_list attribute.
     * @return A string that concatenates all of the info on the artist_list attribute.
     */
    string getArtists();

    /**
     * Returns all of the information on the artist_songs attribute.
     * @return A string that concatenates all of the info on the artist_songs attribute.
     */
    string getArtSongs();
};


#endif //ODYSSEYRADIO_READER_H
