/**********************************************************************************************************************
 * This is the header file for the kitchen class. It is a derived class from the base class, Space. It represents a
 * room in the house.
 *********************************************************************************************************************/

#ifndef FINALPROJECT_PIRATEROOM_HPP
#define FINALPROJECT_PIRATEROOM_HPP

#include "Space.hpp"


class PirateRoom : public Space{

private:

    bool hasKey = false;

public:

    PirateRoom();
    void displayRoomDialogue();
    void displayMap();
    int spaceActionMenu();

};


#endif //FINALPROJECT_PIRATEROOM_HPP
