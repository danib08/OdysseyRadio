//
// Created by dani on 29/10/20.
//

#ifndef ODYSSEYRADIO_ARTISTNODE_H
#define ODYSSEYRADIO_ARTISTNODE_H


#include <string>
using namespace std;

class ArtistNode {
private:
    std::string data;
    ArtistNode* next;

public:
    explicit ArtistNode(string new_data);

    void setNext(ArtistNode* new_next);

    ArtistNode* getNext();

    string getData();
};


#endif //ODYSSEYRADIO_ARTISTNODE_H
