//
// Created by dani on 16/10/20.
//

#ifndef ODYSSEYRADIO_READER_H
#define ODYSSEYRADIO_READER_H

#include <iostream>
#include <Lists/LinkedList.h>

class Reader {
private:
    int pagination;
    std::string file_name = "raw_tracks-edited.csv";
    LinkedList* page_now;
    LinkedList* page_before;
    LinkedList* page_after;
    LinkedList* all_songs;
    LinkedList* artists;

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
};


#endif //ODYSSEYRADIO_READER_H
