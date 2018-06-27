/**********************************************************************************************************************
 * This is the source file for the Game class. Here is where the structure of the game's action will be held.
 *********************************************************************************************************************/

#include "Game.hpp"

/**********************************************************************************************************************
 *                               openingDialogue(), gettingToHouse(), arrivalAtHouse();
 *
 * These functions all serve as a sort of intro to the game. There is only one possible selection that doesn't exit the
 * game so the player is forced to advance the game until they get to the house.
 *********************************************************************************************************************/


void Game::openingDialogue() {
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout << "   This is a game of survival and escape." << endl;
    cout << "You have found yourself stranded on an island and must gather" << endl;
    cout << "the resources that will lead to your escape." << endl << endl;
    cout << "Many before you have come to this island, but none have left..." << endl;
    cout << "You have a limited amount of life and plenty of dangers lay ahead." << endl;
    cout << "If you wish to escape the island, you must act carefully." << endl << endl;
}

int Game::gettingToHouse() {
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout << "   You awaken in a confused state to the sound of crashing waves behind you. As you come to your" << endl ;
    cout << "senses and brush the sand from your face, you look around to see that you are on a beach with" << endl;
    cout << "no signs of civilization around you. You have nothing but the clothes on your back and an" << endl;
    cout << "old backpack." << endl << endl;

    cout << "   As your eyes regain focus, you see what appears to be a path leading into the dense vegetation" << endl;
    cout << "towards the interior of the island. " << endl << endl;

    int beachChoice = menuObj.twoChoicesMenu("Take the Path", "Exit");

    if (beachChoice == 1){

        cout <<"---------------------------------------------------------------------------------------------------";
        cout << endl;
        cout << "   You begin to walk on the path deeper into the island jungle. An uneasy feeling comes over" << endl;
        cout << "you as you get the feeling that there are many unseen pairs of eyes watching you from the" << endl;
        cout << "jungle's shadows." << endl;
        cout << "   The uneasy feeling causes you to quicken your pace and eventually you arrive at a decrepit" << endl;
        cout << "two story house with a faint light coming from a second story window."<< endl<<endl;
        return beachChoice;
    }
    else {
        return beachChoice;

    }
}


int Game::arrivalAtHouse() {

    houseSelection = menuObj.twoChoicesMenu("Enter the House", "Exit");

    if (houseSelection == 1){
        cout <<"---------------------------------------------------------------------------------------------------";
        cout << endl;
        cout << "   You open the heavy wooden door and enter a large foyer. On a table in the middle of the room";
        cout << endl;
        cout << "lays a radio. Enthusiastically, you run up and try to turn it on. However, you notice that it" << endl;
        cout << "is missing batteries, an antenna, and a microphone. You also notice a note on a piece of" << endl;
        cout << "parchment on the table. It reads: " << endl << endl;
        cout << "       Within this house lays the tools for your escape, but beware..." << endl;
        cout << "       those who have come before you don't want to see you leave." << endl;
        cout << endl;
        cout << "                           Good Luck." << endl << endl;

        cout << " [Press Enter to Continue]" << endl;
        cin.ignore();
        cin.ignore();
        cout <<"---------------------------------------------------------------------------------------------------";
        cout << endl << endl;
        return houseSelection;
    }

    else{
        return houseSelection;
    }
}

/**********************************************************************************************************************
 *                                                  performGame()
 *
 * This function will control the entire flow of the game. It is the only function that needs to be called from main()
 * in order to run the game.
 *********************************************************************************************************************/

void Game::performGame() {

    Map mapObj;

    openingDialogue();


    int beginGame = menuObj.twoChoicesMenu("Begin Game", "Exit");

    if(beginGame == 1){

        int goToHouse = gettingToHouse();

        if (goToHouse == 1){

            int enterHouse = arrivalAtHouse();

            if (enterHouse == 2) {
                return;
            }
        }
        else{
            return;
        }
    }
    else{
        return;
    }


    mapObj.initializeMap();
    mapObj.getPlayerLocation()->displayMap();
    mapObj.getPlayerLocation()->displayRoomDialogue();


    int spaceSelection = 0;

    while (!gameWon){

        do{
            spaceSelection = mapObj.getPlayerLocation()->spaceActionMenu();

            if (spaceSelection == 0){
                //player has died.
                return;
            }
            else if (spaceSelection == 1){
            //all actions performed within derived space classes
            }
            else if(spaceSelection == 2){

                mapObj.movePlayer(menuObj.chooseMoveDirection());
                mapObj.getPlayerLocation()->displayMap();
                mapObj.getPlayerLocation()->displayRoomDialogue();
            }
            else{
                //3: Exit, this ends the loop/program.
            }

        }while(spaceSelection != 3); //game continues until player wins/player dies/ or player exits

            return;
        }
    }

