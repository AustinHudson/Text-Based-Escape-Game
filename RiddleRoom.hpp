/**********************************************************************************************************************
 * This is the header file for the RiddleRoom class. It is a derived class from the base class, Space. It represents a
 * room in the house.
 *********************************************************************************************************************/

#ifndef FINALPROJECT_RIDDLEROOM_HPP
#define FINALPROJECT_RIDDLEROOM_HPP


#include "Space.hpp"


class RiddleRoom : public Space{


private:

    bool riddleSolved = false;
    bool firstChestOpened = false;
    bool thirdChestOpened = false;
    bool fourthChestOpened = false;

public:

    RiddleRoom();
    void displayRoomDialogue();
    void displayMap();
    int spaceActionMenu();

};


#endif //FINALPROJECT_RIDDLEROOM_HPP
