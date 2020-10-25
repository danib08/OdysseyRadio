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
    std::string data[7];
    Node* next;

public:
    /**
     * @brief Constructor for the Node class.
     * It sets "next" to nullptr.
     */
    Node();


    /**
     * @brief Setter for the "next" pointer type attribute.
     * @param new_next The new value that'll be assigned to the "next" attribute.
     */
    void setNext(Node* new_next);

    void setArray(string one, string two, string three, string four, string five, string six, string seven);
};


#endif //PRUEBAQT_NODE_H
