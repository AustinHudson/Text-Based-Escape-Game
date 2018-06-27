/**********************************************************************************************************************
 * This is the source file for the map class. It will create the spaces of the house as well as track movement of the
 * player through the house.
 *********************************************************************************************************************/

#include "Map.hpp"
#include "Menu.hpp"

/**********************************************************************************************************************
 * Map constructor
 * The constructor will create addresses for the different space derived classes.
 *********************************************************************************************************************/


Map::Map() {


    foyerPtr = new Foyer;
    hallwayPtr = new Hallway;
    kitchenPtr = new Kitchen;
    libraryPtr = new Library;
    pirateRoomPtr = new PirateRoom;
    riddleRoomPtr = new RiddleRoom;
    treasureRoomPtr = new TreasureRoom;


}

/**********************************************************************************************************************
 * Map destructor
 * The destructor will delete the dynamically allocated pointers created for the rooms of the house.
 *********************************************************************************************************************/

Map::~Map() {

    delete foyerPtr;
    delete hallwayPtr;
    delete kitchenPtr;
    delete libraryPtr;
    delete pirateRoomPtr;
    delete riddleRoomPtr;
    delete treasureRoomPtr;
}

/**********************************************************************************************************************
 * initializeMap()
 * This function sets up the pointers for forward, left, right, and back for each room. This is needed as the player
 * moves about the house by selecting one of these directions.
 *********************************************************************************************************************/

void Map::initializeMap() {

    foyerPtr->setForward(hallwayPtr);
    foyerPtr->setLeft(kitchenPtr);
    foyerPtr->setRight(libraryPtr);
    foyerPtr->setBack(nullptr);

    libraryPtr->setForward(nullptr);
    libraryPtr->setLeft(foyerPtr);
    libraryPtr->setRight(nullptr);
    libraryPtr->setBack(nullptr);

    kitchenPtr->setForward(nullptr);
    kitchenPtr->setLeft(nullptr);
    kitchenPtr->setRight(foyerPtr);
    kitchenPtr->setBack(nullptr);

    hallwayPtr->setForward(riddleRoomPtr);
    hallwayPtr->setLeft(pirateRoomPtr);
    hallwayPtr->setRight(treasureRoomPtr);
    hallwayPtr->setBack(foyerPtr);

    pirateRoomPtr->setForward(nullptr);
    pirateRoomPtr->setLeft(nullptr);
    pirateRoomPtr->setRight(hallwayPtr);
    pirateRoomPtr->setBack(nullptr);

    riddleRoomPtr->setForward(nullptr);
    riddleRoomPtr->setLeft(nullptr);
    riddleRoomPtr->setRight(nullptr);
    riddleRoomPtr->setBack(hallwayPtr);

    treasureRoomPtr->setForward(nullptr);
    treasureRoomPtr->setLeft(hallwayPtr);
    treasureRoomPtr->setRight(nullptr);
    treasureRoomPtr->setBack(nullptr);

    playersLocation = foyerPtr;
}

/**********************************************************************************************************************
 * movePlayer()
 * @param dir user inputted direction
 * This function uses the direction that the user selects to first check to see if it is a valid selection. It then
 * moves the player to the new space if so.
 *********************************************************************************************************************/

void Map::movePlayer(int dir) {

    Menu menuObj;
    validMove = false;

    while (validMove == false) {

        if (dir == 1) {

            if (playersLocation->getForward() == nullptr) {
                cout << "There are no passages leading forward. Please choose a different move." << endl;

            } else {
                validMove = true;
                playersLocation = playersLocation->getForward();
                cout << "You are now in the " << playersLocation->getNameOfSpace() << endl;
                return;
            }
        }
        else if (dir == 2) {

            if (playersLocation->getLeft() == nullptr) {
                cout << "There are no passages leading to the left. Choose a different move." << endl;

            } else {
                validMove = true;
                playersLocation = playersLocation->getLeft();
                cout << "You are now in the " << playersLocation->getNameOfSpace() << endl;
                return;
            }

        }
        else if (dir == 3) {

            if (playersLocation->getRight() == nullptr) {
                cout << "There are no passages leading to the right. Choose a different move." << endl;

            } else {
                validMove = true;
                playersLocation = playersLocation->getRight();
                cout << "You are now in the " << playersLocation->getNameOfSpace() << endl;
                return;
            }
        }
        else {

            if (playersLocation->getBack() == nullptr) {
                cout << "There are no passages leading behind you. Choose a different move." << endl;


            } else {
                validMove = true;
                playersLocation = playersLocation->getBack();
                cout << "You are now in the " << playersLocation->getNameOfSpace() << endl;;
                return;
            }
        }
        movePlayer(menuObj.chooseMoveDirection());
    }
}

Space* Map::getPlayerLocation() {

    return playersLocation;
}

