//
// Created by dani on 24/10/20.
//

#ifndef PRUEBAQT_LINKEDLIST_H
#define PRUEBAQT_LINKEDLIST_H

#include "SongNode.h"
#include <string>
using namespace std;

class SongNode; // This forward declaration is used because without it, the program doesn't compile. This way, the
// the compiler knows about the class SongNode before it's declaration as a pointer below.

/**
 * @brief A class that represents a singly linked list.
 */
class SongList {
private:
    int length = 0;
    SongNode* head;
    SongNode* tail;

public:
    /**
     * @brief Constructor for the SongList class.
     * It sets the values of "head" and "tail" to nullptr.
     */
    SongList();

    /**
     * @brief Adds a new node at the back of the linked list with the value entered as a parameter.
     * @param data The value that the new node will contain.
     */
    void append(string one, string two, string three);

    void clear();

    std::string get();

};

#endif //PRUEBAQT_LINKEDLIST_H
