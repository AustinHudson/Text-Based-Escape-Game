/**********************************************************************************************************************
 * This is the source file for the Hallway class. It is a derived class from the base class, Space. It represents a
 * room in the house.
 *********************************************************************************************************************/

#include "Hallway.hpp"
#include "Map.hpp"

Hallway::Hallway() {

    nameOfSpace = "Hallway";

}

void Hallway::displayMap() {

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
    cout << "|                  |         0         |                   |" << endl;
    cout << "|                  |        /|\\        |                   |" << endl;
    cout << "-------------------|        / \\        |--------------------" << endl;
    cout << "                   |                   |                    " << endl;
    cout << "               -----------========-----------               " << endl;
    cout << "               |           ======           |               " << endl;
    cout << "---------------|            ====            |---------------" << endl;
    cout << "|   Kitchen    |                            |    Library   |" << endl;
    cout << "|              |           Foyer            |              |" << endl;
    cout << "|                                                          |" << endl;
    cout << "|                                                          |" << endl;
    cout << "|              |                            |              |" << endl;
    cout << "|              |                            |              |" << endl;
    cout << "------------------------------------------------------------" << endl;
}

void Hallway::displayRoomDialogue() {

    if (!lightOn){

        cout << "You are now in a hallway at the top of the stairs. It is completely dark" << endl;
        cout << "and you are unable to see where the hallway may lead. Above you, you see what" << endl;
        cout << "looks like a string to a light." << endl << endl;
    }

    else{

        cout << "You are now able to clearly see the hallway that you are in. There is a door" << endl;
        cout << "to the front of you as well as to the left and right." << endl;
    }
}

/**********************************************************************************************************************
 *                                      Hallway - spaceActionMenu()
 *
 * @return int that cooresponds with user's selection
 * This function contains all of the avaliable actions that can occur in the Hallway space. The user can turn a light
 * on and move to any of the rooms upstairs.
 *********************************************************************************************************************/

int Hallway::spaceActionMenu() {

    int getSelection = menuObj.threeChoicesMenu("Turn on the light", "Move to a different room", "Exit");


    if(getSelection == 1){

        if (!lightOn){

            cout << "You pull the string and a light flickers on illuminating the hallway in a dim glow." << endl;
            cout << "You can now see that there is a door to the front of you as well as to the left and right."<<endl;

            lightOn = true;
            return getSelection;
        }
        else {

            cout << "The light is still on in the hallway." << endl;
            cout << "You are now able to see the hallway that you are in. There is a door" << endl;
            cout << "to the front of you as well as to the left and right." << endl;

            return getSelection;
        }
    }

    else if (getSelection == 2){

        if (!lightOn){

            cout << "It is too dark to move to another room. You must first turn on the light." << endl;
            getSelection = spaceActionMenu();
            return getSelection;
        } else{

            return getSelection;
        }

    }
    else {
        return getSelection;
    }
}

