//
// Created by dani on 29/10/20.
//

#ifndef ODYSSEYRADIO_ARTISTLIST_H
#define ODYSSEYRADIO_ARTISTLIST_H

#include "ArtistNode.h"
#include <string>
using namespace std;

/**
 * @brief ArtistList class: stock the artist data
 * @author Daniela Brenes
 * @author Oscar Mendez
 */
class ArtistList {
private:
    int length = 0;
    ArtistNode* head;
    ArtistNode* tail;

public:
    /**
     * @brief Constructor method
     */
    ArtistList();
    /**
     * @brief  append method that add data into the list
     * @param data add the artist data into the list
     */
    void append(string data);
    /**
     * @brief get method tht returns a string data
     * @return the data that are stocked in the list
     */
    std::string get();
    /**
     * @brief exists method that check if any data already exists in the list
     * @param name that will be compared
     * @return boolean if any data are already in the list
     */
    bool exists(string name);
};


#endif //ODYSSEYRADIO_ARTISTLIST_H
