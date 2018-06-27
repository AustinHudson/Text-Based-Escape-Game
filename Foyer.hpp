/**********************************************************************************************************************
 * This is the header file for the Foyer class. It is a derived class from the base class, Space. It is one of the
 * rooms in the house.
 *********************************************************************************************************************/

#ifndef FINALPROJECT_FOYER_HPP
#define FINALPROJECT_FOYER_HPP


#include "Space.hpp"


class Foyer : public Space{

private:

    bool radioBuilt = false;

public:

    Foyer();
    void displayRoomDialogue();
    void displayMap();
    int spaceActionMenu();
    bool checkForBuiltRadio();

};


#endif //FINALPROJECT_FOYER_HPP
