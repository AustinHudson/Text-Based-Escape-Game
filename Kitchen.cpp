/**********************************************************************************************************************
 * This is the source file for the kitchen class. It is a derived class from the base class, Space. It represents a
 * room in the house.
 *********************************************************************************************************************/

#include "Kitchen.hpp"
#include "Map.hpp"

Kitchen::Kitchen() {

    nameOfSpace = "Kitchen";

}

void Kitchen::displayMap() {

    cout << "                   ---------------------                    " << endl;
    cout << "                   |      Riddle       |                    " << endl;
    cout << "                   |       Room        |                    " << endl;
    cout << "                   |                   |                    " << endl;
    cout << "                   |                   |                    " << endl;
    cout << "                   |                   |                    " << endl;
    cout << "-------------------|------      -------|--------------------" << endl;
    cout << "|      Pirate      |                   |      Treasure     |" << endl;
    cout << "|       Room       |     Upstairs      |        Room       |" << endl;
    cout << "|                  |     Hallway       |                   |" << endl;
    cout << "|                                                          |" << endl;
    cout << "|                                                          |" << endl;
    cout << "|                  |                   |                   |" << endl;
    cout << "|                  |                   |                   |" << endl;
    cout << "-------------------|                   |--------------------" << endl;
    cout << "                   |                   |                    " << endl;
    cout << "               -----------========-----------               " << endl;
    cout << "               |           ======           |               " << endl;
    cout << "---------------|            ====            |---------------" << endl;
    cout << "|   Kitchen    |                            |    Library   |" << endl;
    cout << "|              |           Foyer            |              |" << endl;
    cout << "|                                                          |" << endl;
    cout << "|      o                                                   |" << endl;
    cout << "|     /|\\      |                            |              |" << endl;
    cout << "|     / \\      |                            |              |" << endl;
    cout << "------------------------------------------------------------" << endl;
}

/**********************************************************************************************************************
 *                                       Kitchen - spaceActionMenu()
 *
 * @return int that cooresponds to the users selection
 * This function controls all of the avaliable actions in the kitchen space. The user can search the kitchen to find
 * batteries for the radio or select to move to another room.
 *********************************************************************************************************************/

int Kitchen::spaceActionMenu() {

    Player playerObj;

    int getSelection = menuObj.threeChoicesMenu("Search the Kitchen", "Move to a different room ", "Exit");

    if (getSelection == 1){

        if(!hasBatteries){
            cout << "You begin to rummage through the kitchen to see if there is anything useful." << endl;
            cout << "As you open a drawer, you hear something roll around." << endl;
            cout << "Batteries! You add them to your backpack." << endl << endl;

            cout << "You hear the sounds of footsteps coming from the room directly above you..." << endl << endl;

            playerObj.addItemToBackpack(playerObj.getBatteries());
            hasBatteries = true;
            return getSelection;
        }
        else{
            cout << "You look through the kitchen again but do not find anything of value." << endl << endl;
        }
    }
    else{

        return getSelection;
    }
    return getSelection;
}

void Kitchen::displayRoomDialogue() {

    cout << "You are now in the kitchen. It looks like it hasn't been used in a century." << endl;
    cout << "Dust covers every surface as boxes and other items are haphazardly laying around." << endl;
}