/**********************************************************************************************************************
 * This is the source file for the Player class. This class is where the players items, and damage are tracked/updated.
 *********************************************************************************************************************/

#include "Player.hpp"

int Player::health = 3; //static variable so health is kept over course of entire game.

int Player::backpack[] = {0}; // static int array so the contents of the backpack are tracked over entire game.

/**********************************************************************************************************************
 *                                              addItemToBackpack()
 * @param item the int that cooresponds to the item to add
 * This function is used to add items to the backpack container as the user acquires items throughout the game.
 *********************************************************************************************************************/

void Player::addItemToBackpack(int item) {


    for (int i = 0; i < 5; i++){

        if (backpack[i] == 0){

            backpack[i] = item;
            return;
        }
    }
}
/**********************************************************************************************************************
 *                                               searchBackpack()
 * @param item item to be searched for in backpack container
 * @return bool true if the item is found, false if not.
 * This function checks to see if a specific item has been added to the users backpack.
 *********************************************************************************************************************/


bool Player::searchBackpack(int item) {

    bool itemFound = false;

    for (int i = 0; i < 5; i++){

        if (backpack[i] == item){
            return true;
        }
    }
    return itemFound;

}

/**********************************************************************************************************************
 *                                               damageToPlayer()
 * @return the amount of healthpoints the player still has.
 * This funcitno is called whenever the player takes damage in the game. It lowers their health points by 1. If the
 * player has no health remaining, a message is printed saying that they lost the game.
 *********************************************************************************************************************/


int Player::damageToPlayer() {

    health = health - 1;

    if (health == 0){

        cout << "You have lost all of your available health points." << endl << endl;
        cout <<"---------------------------------------------------------------------------------------------------";
        cout << endl << endl;
        cout << "You have become doomed to the same fate as those who have come before you." << endl;
        cout << "The island is now your eternal home where you will spend the rest of time" << endl;
        cout << "waiting for the next potential victim to join you among the Captain's crew" << endl;
        cout << "of undead sailors." << endl << endl;
        cout <<"---------------------------------------------------------------------------------------------------";
        return health;
    }

    else {
        cout << "You have lost one of your health points." << endl;
        cout <<"Health Points Remaining: " << health << "." << endl;
        cout << "You must act more carefully if you wish to escape from the island alive." << endl << endl;
        return health;
    }
}

int Player::getBatteries() {

    return batteries;
}

int Player::getAntenna() {

    return antenna;
}

int Player::getFightingBook() {

    return fightingBook;
}

int Player::getMicrophone() {

    return microphone;
}

int Player::getJokeBook() {

    return jokeBook;
}

int Player::getKey() {

    return key;
}
