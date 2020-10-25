//
// Created by dani on 24/10/20.
//

#ifndef PRUEBAQT_NODE_H
#define PRUEBAQT_NODE_H

#include <string>
using namespace std;

/**
* @brief A class that represents a node used in linked lists.
*/
class Node {
private:
    std::string data[8];
    Node* next;

public:
    /**
     * @brief Constructor for the Node class.
     * It sets "next" to nullptr.
     */
    Node();

    /**
     * @brief Getter for the "next" attribute.
     * @return The "next" pointer type attribute.
     */
    Node* getNext();

    /**
     * @brief Setter for the "next" pointer type attribute.
     * @param new_next The new value that'll be assigned to the "next" attribute.
     */
    void setNext(Node* new_next);

    /**
     * Assigns a value to an index of the data array
     * @param item The string item to be added
     * @param i The index of interest
     */
    void assign(std::string item, int i);

    void setArray(string one, string two, string three, string four, string five, string six, string seven);
};


#endif //PRUEBAQT_NODE_H
