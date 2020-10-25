//
// Created by dani on 24/10/20.
//

#include "Node.h"
using namespace std;

Node::Node() : next(nullptr){}

void Node::setNext(Node* new_next) {
    next = new_next;
}

void Node::setArray(string one, string two, string three, string four, string five, string six, string seven) {
    data[0] = one;
    data[1] = two;
    data[2] = three;
    data[3] = four;
    data[4] = five;
    data[5] = six;
    data[6] = seven;
}

