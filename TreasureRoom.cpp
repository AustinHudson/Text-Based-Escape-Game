/**********************************************************************************************************************
 * This is the source file for the TreasureRoom class. It is a derived class from the base class, Space. It represents
 * a room in the house.
 *********************************************************************************************************************/

#include "TreasureRoom.hpp"
#include "Map.hpp"

TreasureRoom::TreasureRoom() {

    nameOfSpace = "Treasure Room";

}


void TreasureRoom::displayMap() {

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
    cout << "|                                                 0        |" << endl;
    cout << "|                  |                   |         /|\\       |" << endl;
    cout << "|                  |                   |         / \\       |" << endl;
    cout << "-------------------|                   |--------------------" << endl;
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

void TreasureRoom::displayRoomDialogue() {

    cout << "You enter the large open room and take a look around." << endl;
    cout << "There is a single chest sitting against the back wall next to a pile of" << endl;
    cout << "rocky debris from the crumbling wall. " << endl;

}

/**********************************************************************************************************************
 *                                         TreasureRoom - spaceActionMenu()
 *
 * @return int that cooresponds with user's selection
 * This function controls the actions that can be performed in the Treasure room space. The user can inspect the chest
 * and if they have the Captain's key, they can use that to open the chest and receive the antenna. If they choose to
 * force the lock open, they will be dealt damage.
 *********************************************************************************************************************/

int TreasureRoom::spaceActionMenu() {

    Player playerObj;

    int getSelection = menuObj.threeChoicesMenu("Inspect the chest", "Move to a different room", "Exit");

    if (getSelection == 1){

        if (chestOpened){

            cout << "There is nothing else in the chest." << endl;
            return getSelection;
        }
        else{
            cout << "The dark wooden chest looks as if it has been untouched for years." << endl;
            cout << "As you brush your hand over the top, the thick layer of dust is kicked up to" << endl;
            cout << "reveal a locked latch. It looks as if an old key will fit the lock." << endl << endl;


            if (playerObj.searchBackpack(playerObj.getKey())){

                int openChestSelection = menuObj.threeChoicesMenu("Use the Captain's key to open the chest",
                                                                 "Try to force the lock open", "Leave the chest alone");

                if (openChestSelection == 1){

                    cout << "You insert the Captain's key into the lock and give it a turn. You can hear the" << endl;
                    cout << "inner mechanisms turn and then a loud click." << endl;
                    cout << "You lift the lid of the chest to find the antenna for the radio!" << endl;
                    cout << "You place it in your backpack and close the chest." << endl << endl;

                    playerObj.addItemToBackpack(playerObj.getAntenna());
                    chestOpened = true;
                    return openChestSelection;
                }
                else if (openChestSelection == 2){

                    cout << "You attempt to bash open the lock with a rock from the crumbling wall." << endl;
                    cout << "As you make contact with the lock a ghostly pirate emerges through the" << endl;
                    cout << "wall and strikes you with a cutlass. Just as suddenly as he appeared," << endl;
                    cout << "the ghostly figure steps back through the wall out of sight." << endl << endl;

                    int healthRemaining = playerObj.damageToPlayer();

                    if (healthRemaining == 0){
                        return 0;
                    }
                    return 1;

                } else{

                    return 1;


                }

            }
            else{

                int openChestSelection = menuObj.twoChoicesMenu("Try to force the lock open", "Leave the chest alone");

                if(openChestSelection == 1){

                    cout << "You attempt to bash open the lock with a rock from the crumbling wall" << endl;
                    cout << "As you make contact with the lock a ghostly pirate emerges through the" << endl;
                    cout << "wall and strikes you with a cutlass. Just as suddenly as he appeared," << endl;
                    cout << "The ghostly figure steps back through the wall out of sight." << endl << endl;


                    int healthRemaining = playerObj.damageToPlayer();

                    if (healthRemaining == 0){
                        return 0;
                    }

                    return getSelection;

                }
                else{

                    return getSelection;
                }

            }
        }

    }
    else{

        return getSelection;
    }
}
