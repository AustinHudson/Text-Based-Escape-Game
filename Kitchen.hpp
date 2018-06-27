/**********************************************************************************************************************
 * This is the header file for the kitchen class. It is a derived class from the base class, Space. It represents a
 * room in the house.
 *********************************************************************************************************************/

#ifndef FINALPROJECT_KITCHEN_HPP
#define FINALPROJECT_KITCHEN_HPP


#include "Space.hpp"
#include "Player.hpp"


class Kitchen : public Space {

private:

    bool hasBatteries = false;

public:

    Kitchen();
    void displayRoomDialogue();
    void displayMap();
    int spaceActionMenu();

};


#endif //FINALPROJECT_KITCHEN_HPP
