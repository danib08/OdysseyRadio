//
// Created by dani on 24/10/20.
//

#include "LinkedList.h"
#include <string>
using namespace std;

LinkedList::LinkedList()
        : head(nullptr), tail(nullptr) {}

void LinkedList::append(string one, string two, string three) {
    Node* node = new Node();
    node->setArray(one, two, three);

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
    length = 0;
}

string LinkedList::get() {
    Node* node = head;
    string output;
    for (int j = 0; j < length; ++j) {
        output += node->getIndexArray(0) + " - " + node->getIndexArray(1) + " - " + node->getIndexArray(2);
        if (j != length - 1) {
            output += "$";
        }
        node = node->getNext();
    }
    return output;
}
