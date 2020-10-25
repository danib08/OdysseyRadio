//
// Created by dani on 24/10/20.
//

#include "LinkedList.h"
#include <string>
using namespace std;

LinkedList::LinkedList()
        : head(nullptr), tail(nullptr) {}

void LinkedList::append(string one, string two, string three, string four, string five, string six, string seven) {
    Node* node = new Node();
    node->setArray(one, two, three, four, five, six, seven);

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

void LinkedList::clear() {
    head = tail = nullptr;
}
