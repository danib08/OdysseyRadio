//
// Created by dani on 29/10/20.
//

#include "ArtistNode.h"

ArtistNode::ArtistNode(string new_data) : next(nullptr), data(new_data) {}

void ArtistNode::setNext(ArtistNode *new_next) {
    next = new_next;
}

ArtistNode *ArtistNode::getNext() {
    return next;
}

string ArtistNode::getData() {
    return data;
}
