/**********************************************************************************************************************
 * This is the header file for the Library class. It is a derived class from the base class, Space. It represents a
 * room in the house.
 *********************************************************************************************************************/

#ifndef FINALPROJECT_LIBRARY_HPP
#define FINALPROJECT_LIBRARY_HPP


#include "Space.hpp"
#include "Foyer.hpp"
#include "Map.hpp"

class Library : public Space {


private:

    bool hasBook = false;

public:

    Library();
    void displayRoomDialogue();
    void displayMap();
    int spaceActionMenu();

};


#endif //FINALPROJECT_LIBRARY_HPP
