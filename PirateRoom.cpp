/**********************************************************************************************************************
 * This is the source file for the PirateRoom class. It is a derived class from the base class, Space. It represents a
 * room in the house.
 *********************************************************************************************************************/

#include "PirateRoom.hpp"
#include "Map.hpp"

PirateRoom::PirateRoom() {


    nameOfSpace = "Pirate's Room";

}


void PirateRoom::displayMap() {

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
    cout << "|        0                                                 |" << endl;
    cout << "|       /|\\        |                   |                   |" << endl;
    cout << "|       / \\        |                   |                   |" << endl;
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

void PirateRoom::displayRoomDialogue() {

    if (!hasKey) {

        cout << "You enter what appears to be a bedroom. There is nothing more than a small bed and desk in the"
             << endl;
        cout << "room. As soon as you walk towards the center of the room, you hear the door slam shut behind you."
             << endl;
        cout << "Startled, you turn around to see a large menacing pirate standing between you and the door." << endl;
        cout << "You notice a glimmer from a golden key siting in his front pocket." << endl << endl;

        cout << "               Arrrrrgh, who dares intrude into my private quarters?!!" << endl << endl;
    }
    else {

        cout << "The room appears quiet. There are no signs of the captain or his ghostly crew." << endl << endl;

    }

}

/**********************************************************************************************************************
 *                                          PirateRoom - spaceActionMenu()
 *
 * @return int that cooresponds with user's selection
 * This function controls the avaliable actions that can occur in the PirateRoom Space. The user is confronted by the
 * Captain where they can then ask him a question before attacking him or telling him a joke. After defeating the
 * Captain, the player acquires the key.
 *********************************************************************************************************************/

int PirateRoom::spaceActionMenu() {

    Player playerObj;

    if (!hasKey) {

        int getSelection = menuObj.threeChoicesMenu("Ask the pirate why he is on the island",
                                                    "Move to a different room", "Exit");

        if (getSelection == 1) {

            cout << "You ask the pirate who he is and what is he doing here. He replies, " << endl << endl;

            cout << "               I am Captain Jack Timbers. Me and what was left of my crew " << endl;
            cout << "               washed up on this island 300 years ago after a treacherous" << endl;
            cout << "               storm destroyed my ship. This island is cursed though I tell ya." << endl;
            cout << "               We are doomed to inhabit this island for an eternity. Lost" << endl;
            cout << "               sailors like yourself make a fine addition to my crew of undead." << endl;
            cout << "               No one has ever made it off the island before, I don't think you'll" << endl;
            cout << "               be the first." << endl << endl;

            cout << "It is clear that the pirate has no intention of helping you off the island. You must act " << endl;
            cout << "quickly." << endl << endl;

            int combatSelection = menuObj.threeChoicesMenu("Attack the Captain", "Tell the Captain a joke",
                                                           "Flee the room");

            if (combatSelection == 1){

                if(playerObj.searchBackpack(playerObj.getFightingBook())){

                    cout << "You quickly reach for the Captain's cutlass and remove it before he can react." << endl;
                    cout << "A quick fight ensues, but you soon strike the Captain down. He fades away into a" << endl;
                    cout << "cloud of black smoke and in the place he once stood lays the golden key." << endl << endl;
                    cout << "The knowledge that you gained from reading the book on combat on the high seas" << endl;
                    cout << "has paid off!" << endl << endl;
                    cout << "You place the key in your backpack." << endl << endl;

                    playerObj.addItemToBackpack(playerObj.getKey());
                    hasKey = true;
                    return combatSelection;

                }
                else {

                    cout << "You lunge at the pirate, but he is quick to react. He quickly steps aside and " << endl;
                    cout << "deals a damaging blow with his cutlass." << endl << endl;

                    int healthRemaining = playerObj.damageToPlayer();

                    if (healthRemaining == 0){
                        return 0;
                    }

                    return getSelection;
                }
            }
            else if(combatSelection == 2){

                if (playerObj.searchBackpack(playerObj.getJokeBook())){

                    cout << "You quickly remember back to the Joke book that you recovered from the library." << endl;
                    cout << "You tell the captain one of the jokes," << endl << endl;

                    cout << "Three pirates, stranded on a desert island, find a magic lantern containing a genie"<<endl;
                    cout << "who grants them each one wish." << endl;
                    cout << "The first pirate wishes he was off the island and back home." << endl;
                    cout << "The second pirate wishes the same." << endl;
                    cout << "The third pirate says I'm lonely." << endl;
                    cout << "I wish my friends were back here." << endl << endl << endl;

                    cout << "The Captain roars with laughter after hearing your joke. He is laughing so hard" << endl;
                    cout << "that he doesn't notice the key from his pocket slip to the floor." << endl << endl;

                    cout << "The ghostly image of the captain begins to fade away and suddenly you are alone" << endl;
                    cout << "in the room. You pick up the key and place it in your backpack." << endl << endl;

                    playerObj.addItemToBackpack(playerObj.getKey());
                    hasKey = true;

                    return getSelection;
                }
                else{

                    cout << "You try to quickly think of a joke off the top of your head but it fails to " << endl;
                    cout << "impress the Captain. He angrily lashes out at you with his cutlass," << endl;
                    cout << "dealing significant damage to you." << endl << endl;

                    int healthRemaining = playerObj.damageToPlayer();

                    if (healthRemaining == 0){
                        return 0;
                    }

                    return getSelection;
                }

            }
            else{

                return 2;
            }


        } else {

            return getSelection;
        }
    }

    else {

        int getSelection = menuObj.threeChoicesMenu("Inspect the room",
                                                    "Move to a different room", "Exit");

        if (getSelection == 1){

            cout << "The room is quiet and no sign of the Captain remains." << endl << endl;
            return getSelection;
        }
        else{
            return getSelection;
        }
    }
}
