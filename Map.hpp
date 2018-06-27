/**********************************************************************************************************************
 * This is the header file for the map class. It will create the spaces of the house as well as track movement of the
 * player through the house.
 *********************************************************************************************************************/

#ifndef FINALPROJECT_MAP_HPP
#define FINALPROJECT_MAP_HPP

#include "Space.hpp"
#include "Game.hpp"
#include "Foyer.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"
#include "Library.hpp"
#include "PirateRoom.hpp"
#include "RiddleRoom.hpp"
#include "TreasureRoom.hpp"


#include <vector>

class Map {

private:

    Space* foyerPtr;
    Space* hallwayPtr;
    Space* kitchenPtr;
    Space* libraryPtr;
    Space* pirateRoomPtr;
    Space* riddleRoomPtr;
    Space* treasureRoomPtr;
    Space* playersLocation;

    bool validMove = false;

public:

    Map();
    ~Map();
    void initializeMap();
    Space* getPlayerLocation();
    void movePlayer(int);

};


#endif //FINALPROJECT_MAP_HPP
