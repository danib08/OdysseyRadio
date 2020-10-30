//
// Created by dani on 24/10/20.
//

#include "SongNode.h"
using namespace std;

SongNode::SongNode() : next(nullptr){}

void SongNode::setNext(SongNode* new_next) {
    next = new_next;
}

void SongNode::setArray(string one, string two, string three) {
    data[0] = one;
    data[1] = two;
    data[2] = three;
}

SongNode *SongNode::getNext() {
    return next;
}

std::string SongNode::getIndexArray(int i) {
    return data[i];
}

