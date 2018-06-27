/**********************************************************************************************************************
* This is the header file for the player class. 
 *********************************************************************************************************************/

#ifndef FINALPROJECT_PLAYER_HPP
#define FINALPROJECT_PLAYER_HPP

#include <vector>
#include "Map.hpp"
#include "Menu.hpp"
class Player {

private:

    static int backpack[5];
    static int health;
    int batteries = 1;
    int microphone = 2;
    int antenna = 3;
    int fightingBook = 4;
    int jokeBook = 5;
    int key = 5;

public:

    void addItemToBackpack(int);
    bool searchBackpack(int);
    int damageToPlayer();
    int getBatteries();
    int getMicrophone();
    int getAntenna();
    int getFightingBook();
    int getJokeBook();
    int getKey();
};


#endif //FINALPROJECT_PLAYER_HPP
