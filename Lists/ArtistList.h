//
// Created by dani on 29/10/20.
//

#ifndef ODYSSEYRADIO_ARTISTLIST_H
#define ODYSSEYRADIO_ARTISTLIST_H

#include "ArtistNode.h"
#include <string>
using namespace std;

class ArtistList {
private:
    int length = 0;
    ArtistNode* head;
    ArtistNode* tail;

public:
    ArtistList();

    void append(string data);

    void clear();

    std::string get();
};


#endif //ODYSSEYRADIO_ARTISTLIST_H
