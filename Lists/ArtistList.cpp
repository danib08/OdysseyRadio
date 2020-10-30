//
// Created by dani on 29/10/20.
//

#include "ArtistList.h"

ArtistList::ArtistList() : head(nullptr), tail(nullptr) {}

void ArtistList::append(string data) {
    ArtistNode* node = new ArtistNode(data);

    if (length == 0) {
        head = node;
        tail = node;
    }
    else {
        tail->setNext(node);
        tail = node;
    }
    length++;
}

void ArtistList::clear() {
    head = tail = nullptr;
    length = 0;
}

std::string ArtistList::get() {
    ArtistNode* node = head;
    string output;
    for (int j = 0; j < length; ++j) {
        output += node->getData();
        if (j != length - 1) {
            output += "$";
        }
        node = node->getNext();
    }
    return output;
}
