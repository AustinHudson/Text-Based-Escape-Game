/**********************************************************************************************************************
 * This is the header file for the Hallway class. It is a derived class from the base class, Space. It represents a
 * room in the house.
 *********************************************************************************************************************/

#ifndef FINALPROJECT_HALLWAY_HPP
#define FINALPROJECT_HALLWAY_HPP


#include "Space.hpp"

class Hallway : public Space{

private:

    bool lightOn = false;

public:

    Hallway();
    void displayRoomDialogue();
    void displayMap();
    int spaceActionMenu();

};


#endif //FINALPROJECT_HALLWAY_HPP
