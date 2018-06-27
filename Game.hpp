/**********************************************************************************************************************
 * This is the header file for the Game class.
 *********************************************************************************************************************/

#ifndef FINALPROJECT_GAME_HPP
#define FINALPROJECT_GAME_HPP

#include "Space.hpp"
#include "Menu.hpp"
#include "Foyer.hpp"
#include "Player.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"
#include "Library.hpp"
#include "PirateRoom.hpp"
#include "RiddleRoom.hpp"
#include "TreasureRoom.hpp"
#include "Map.hpp"
#include <iostream>
#include <string>
#include <sstream>

using std::stringstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Game {

private:

    Menu menuObj;
    int houseSelection = 0;
    bool gameWon = false;

public:

    void openingDialogue();
    int gettingToHouse();
    int arrivalAtHouse();
    void performGame();

};


#endif //FINALPROJECT_GAME_HPP
