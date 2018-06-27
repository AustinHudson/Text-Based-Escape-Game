/**********************************************************************************************************************
 * This is the source file for the Foyer class. It is a derived class from the base class, Space. It is one of the
 * rooms in the house.
 *********************************************************************************************************************/

#include "Foyer.hpp"
#include "Player.hpp"


Foyer::Foyer() {

    nameOfSpace = "Foyer";
}

void Foyer::displayRoomDialogue() {

    cout << "You are now in the foyer. There is a radio on a table that could be the means to your escape." << endl;
    cout << "To the front of you are stairs leading up to the second story. To the left is a door leading to" << endl;
    cout << "the kitchen. To the right of you is a door leading to the library." << endl << endl;

}

void Foyer::displayMap() {

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
    cout << "|                            o                             |" << endl;
    cout << "|              |            /|\\             |              |" << endl;
    cout << "|              |            / \\             |              |" << endl;
    cout << "---------------|----------------------------|---------------" << endl;
}

/**********************************************************************************************************************
 *                                          Foyer- spaceActionMenu()
 *
 * @return int based on players selection
 * This function will handle the possible actions in the Foyer space. The radio will only turn on if the player has
 * all of the required items. This is the way to win the game and escape the island.
 *********************************************************************************************************************/

int Foyer::spaceActionMenu() {

    int getSelection = menuObj.threeChoicesMenu("Attempt to turn on the radio", "Move to a different room", "Exit");

    if(getSelection == 1){

        radioBuilt = checkForBuiltRadio();

        if (!radioBuilt){ // pieces to build the radio have not all been acquired.

            cout << "The radio needs batteries, an antenna, and a microphone to be operational. Keep looking" << endl;
            cout << "throughout the house to find these items." << endl;

            return getSelection;
        }
        else {

            cout << "You insert the batteries, attach the antenna, and plug the microphone into the radio." << endl;
            cout << "In desperation you call out for help over the radio. The silence is suddenly broken as" << endl;
            cout << "a voice answers saying that they are heading to your location."<< endl << endl;

            cout << "You have avoided the doomed fate of those who came before you. The captain will" << endl;
            cout << "have to wait for the next unfortunate lost sailor to add to his cursed crew." << endl << endl;

            cout << "Congratulations! You have successfully escaped the island." << endl << endl;

            return 0;
        }
    }

    else if (getSelection == 2){

        return getSelection;

    } else{

        return getSelection;
    }
}

bool Foyer::checkForBuiltRadio() {

    Player playerObj;

    if(playerObj.searchBackpack(playerObj.getAntenna()) && playerObj.searchBackpack(playerObj.getMicrophone())
            &&playerObj.searchBackpack(playerObj.getBatteries())){

        return true;
    }
    else{

        return false;
    }
}