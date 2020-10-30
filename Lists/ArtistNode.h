//
// Created by dani on 29/10/20.
//

#ifndef ODYSSEYRADIO_ARTISTNODE_H
#define ODYSSEYRADIO_ARTISTNODE_H


#include <string>
using namespace std;
/**
 * @brief ArtistNode class that stock a singular data of the list
 */
class ArtistNode {
private:
    std::string data;
    ArtistNode* next;

public:
    /**
     * @brief stock the data of the artist
     * @param new_data string
     */
    explicit ArtistNode(string new_data);
    /**
     * @brief stock the next node reference
     * @param new_next ArtistNode
     */
    void setNext(ArtistNode* new_next);
    /**
     * @brief return the next node
     * @return ArtistNode
     */
    ArtistNode* getNext();
    /**
     * @brief return the data that are stocked in the node
     * @return string
     */
    string getData();
};


#endif //ODYSSEYRADIO_ARTISTNODE_H
