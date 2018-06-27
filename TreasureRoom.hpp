/**********************************************************************************************************************
 * This is the header file for the TreasureRoom class. It is a derived class from the base class, Space. It represents
 * a room in the house.
 *********************************************************************************************************************/

#ifndef FINALPROJECT_TREASUREROOM_HPP
#define FINALPROJECT_TREASUREROOM_HPP


#include "Space.hpp"


class TreasureRoom : public Space{

private:

    bool chestOpened = false;

public:

    TreasureRoom();
    void displayRoomDialogue();
    void displayMap();
    int spaceActionMenu();
};


#endif //FINALPROJECT_TREASUREROOM_HPP
