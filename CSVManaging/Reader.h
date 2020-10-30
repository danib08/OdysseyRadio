//
// Created by dani on 16/10/20.
//

#ifndef ODYSSEYRADIO_READER_H
#define ODYSSEYRADIO_READER_H

#include <iostream>
#include <Lists/SongList.h>
#include <Lists/ArtistList.h>

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
    Reader();
    void readDown(string last_id);
    void readUp(string first_id);
    void readAll();
    void firstRead();
    int getPosition(string id);
    void splitLine(string line, int flag);
    void readArtists();
    void readArtSongs(string name);
    string getNowPage();
    string getAfterPage();
    string getBeforePage();
    string getAllSongs();
    string getArtists();
    string getArtSongs();
};


#endif //ODYSSEYRADIO_READER_H
