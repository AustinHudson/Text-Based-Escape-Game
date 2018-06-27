/**********************************************************************************************************************
 * This is the source file for the RiddleRoom class. It is a derived class from the base class, Space. It represents a
 * room in the house.
 *********************************************************************************************************************/

#include "RiddleRoom.hpp"
#include "Map.hpp"


RiddleRoom::RiddleRoom() {

    nameOfSpace = "Riddle Room";


}

void RiddleRoom::displayRoomDialogue() {

    cout << "You enter a small torch lit room and see four boxes before you and a note attached to the wall." << endl;
}

void RiddleRoom::displayMap() {

    cout << "                   ---------------------                    " << endl;
    cout << "                   |      Riddle       |                    " << endl;
    cout << "                   |       Room        |                    " << endl;
    cout << "                   |        0          |                    " << endl;
    cout << "                   |       /|\\         |                    " << endl;
    cout << "                   |       / \\         |                    " << endl;
    cout << "-------------------|------     --------|--------------------" << endl;
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
    cout << "|                                                          |" << endl;
    cout << "|              |                            |              |" << endl;
    cout << "|              |                            |              |" << endl;
    cout << "------------------------------------------------------------" << endl;
}

/**********************************************************************************************************************
 *                                         RiddleRoom - spaceActionMenu()
 *
 * @return int that cooresponds with user's selection
 * This function controls all of the avaliable actions inside the Riddle Room space. The user first reads a note which
 * starts the process where the correct answer to the riddle must be chosen. If a player chooses the wrong answer,
 * they will take damage.
 *********************************************************************************************************************/

int RiddleRoom::spaceActionMenu() {

    Player playerObj;

    int getSelection = menuObj.threeChoicesMenu("Read the Note", "Move to a different room", "Exit");

    if (getSelection == 1){

        if (riddleSolved){

            cout << "You have already solved the riddle on the note." << endl;
            cout << "There does not appear to be anything else of value in this room." << endl << endl;
            return getSelection;
        }

        //Source for Riddle: https://www.braingle.com/brainteasers/teaser.php?op=2&id=41903&comm=0

        cout << "The note appears to be a riddle. It reads:" << endl << endl;

        cout << "Solving this riddle is a must if you wish to leave the island. Opening the" << endl;
        cout << "correct box will reveal another item to assist you in your escape. But beware, a wrong" << endl;
        cout << "selection will have dire consequences..." << endl << endl;

        cout << "               Shipwrecked we are, once a proud crew," << endl;
        cout << "               Evening finds us, stranded and few;" << endl;
        cout << "               Victory was ours, but now has its cost," << endl;
        cout << "               Even so, we must count the lost." << endl;
        cout << "               Now we see, only several have survived," << endl;
        cout << "               To think our crew, at thirty arrived," << endl;
        cout << "               Everyone at rest, we must ask you," << endl;
        cout << "               Engage in the counting, how many are the few?" << endl;
        cout << "               Now I have given the clue, it's all up to you." << endl << endl;


        cout << "The four boxes in front of you each have a different number etched into them." << endl << endl;

        while (!riddleSolved) {
            int riddleSelection = menuObj.fourChoicesMenu("Open Box labeled \"30\"", "Open Box labeled \"17\"",
                                                          "Open Box labeled \"15\"", "Open Box labeled \"23\"");

            if (riddleSelection == 1) {

                if (firstChestOpened) {
                    cout << "This chest has already been opened and shown to be the incorrect answer." << endl << endl;
                } else {
                    cout << "As you open the chest, you hear the sound of igniting gunpowder before being blown back"
                         << endl;
                    cout << "by a powerful blast. The opening of the wrong box has dealt you significant damage."
                         << endl;
                    firstChestOpened = true;
                    int healthRemaining = playerObj.damageToPlayer();

                    if (healthRemaining == 0) {
                        //player has died
                        return 0;
                    }
                }
            } else if (riddleSelection == 2) {

                cout << "You apprehensively open the chest to find that it contains a small note and the microphone"
                     << endl;
                cout << "for the radio!" << endl;
                cout << "You place the microphone into your backpack and pick up the note. It reads: " << endl << endl;

                cout << "               Did I mention," << endl;
                cout << "               That you take attention," << endl;
                cout << "               To the word I say," << endl;
                cout << "               Concerning the survivors that day?" << endl << endl;

                cout << "               If you did not see seventeen;" << endl;
                cout << "               My words merely distracted you," << endl;
                cout << "               The answer lay in plain view," << endl;
                cout << "               In the form of the first letter of each line." << endl << endl;

                riddleSolved = true;
               playerObj.addItemToBackpack(playerObj.getMicrophone());
                return getSelection;

            } else if (riddleSelection == 3) {

                if (thirdChestOpened) {
                    cout << "This chest has already been opened and shown to be the incorrect answer." << endl << endl;
                } else {
                    cout << "As you open the chest, you hear the sound of igniting gunpowder before being blown back"
                         << endl;
                    cout << "by a powerful blast. The opening of the wrong box has dealt you significant damage."
                         << endl;
                    thirdChestOpened = true;

                    int healthRemaining = playerObj.damageToPlayer();

                    if (healthRemaining == 0) {
                        //player has died
                        return 0;
                    }
                }
            } else { //fourth chest

                if (fourthChestOpened) {
                    cout << "This chest has already been opened and shown to be the incorrect answer." << endl << endl;
                } else {
                    cout << "As you open the chest, you hear the sound of igniting gunpowder before being blown back"
                         << endl;
                    cout << "by a powerful blast. The opening of the wrong box has dealt you significant damage."
                         << endl;
                    fourthChestOpened = true;
                    int healthRemaining =playerObj.damageToPlayer();

                    if (healthRemaining == 0) {
                        //player has died
                        return 0;
                    }
                }
            }
        }
    }
    else{

        return getSelection;
    }
    return 1;
}


