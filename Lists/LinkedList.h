//
// Created by dani on 24/10/20.
//

#ifndef PRUEBAQT_LINKEDLIST_H
#define PRUEBAQT_LINKEDLIST_H

#include "Node.h"
#include_next <string>
using namespace std;

class Node; // This forward declaration is used because without it, the program doesn't compile. This way, the
// the compiler knows about the class Node before it's declaration as a pointer below.

/**
 * @brief A class that represents a singly linked list.
 */
class LinkedList {
private:
    int length = 0;
    Node* head;
    Node* tail;

public:
    /**
     * @brief Constructor for the LinkedList class.
     * It sets the values of "head" and "tail" to nullptr.
     */
    LinkedList();

    /**
     * @brief Adds a new node at the back of the linked list with the value entered as a parameter.
     * @param data The value that the new node will contain.
     */
    void append(string one, string two, string three, string four, string five, string six, string seven);

    void clear();

};

#endif //PRUEBAQT_LINKEDLIST_H
