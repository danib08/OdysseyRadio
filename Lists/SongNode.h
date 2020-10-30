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
class SongNode {
private:
    std::string data[3];
    SongNode* next;

public:
    /**
     * @brief Constructor for the SongNode class.
     * It sets "next" to nullptr.
     */
    SongNode();


    /**
     * @brief Setter for the "next" pointer type attribute.
     * @param new_next The new value that'll be assigned to the "next" attribute.
     */
    void setNext(SongNode* new_next);

    SongNode* getNext();

    void setArray(string one, string two, string three);

    std::string getIndexArray(int i);
};


#endif //PRUEBAQT_NODE_H
