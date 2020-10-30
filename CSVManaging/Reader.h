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
    std::string file_name = "raw_tracks-edited.csv";
    SongList* page_now;
    SongList* page_before;
    SongList* page_after;
    SongList* all_songs;
    ArtistList* artist_list;

public:
    Reader();
    void readDown(string last_id);
    void readUp(string first_id);
    void readAll();
    void firstRead();
    int getPosition(string id);
    void splitLine(std::string line, int flag);
    void readArtists();
    std::string getNowPage();
    std::string getAfterPage();
    std::string getBeforePage();
    std::string getAllSongs();
    std::string getArtists();
};


#endif //ODYSSEYRADIO_READER_H
