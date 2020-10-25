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
    int last_row;
    std::string file_name = "raw_tracks-edited.csv";
    bool first_read = true;
    LinkedList* page_now;
    LinkedList* page_before;
    LinkedList* page_after;
    bool scroll_down;

public:
    Reader();
    void Read();
};


#endif //ODYSSEYRADIO_READER_H
