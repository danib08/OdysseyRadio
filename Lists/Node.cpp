//
// Created by dani on 24/10/20.
//

#include "Node.h"
using namespace std;

Node::Node() : next(nullptr){}

void Node::setNext(Node* new_next) {
    next = new_next;
}

void Node::setArray(string one, string two, string three) {
    data[0] = one;
    data[1] = two;
    data[2] = three;
}

Node *Node::getNext() {
    return next;
}

std::string Node::getIndexArray(int i) {
    return data[i];
}

