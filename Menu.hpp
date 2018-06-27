/**********************************************************************************************************************
 * This is the header file for the Menu class.
 *********************************************************************************************************************/

#ifndef FINALPROJECT_MENU_HPP
#define FINALPROJECT_MENU_HPP

#include <iostream>
#include <string>
#include <sstream>

using std::stringstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;


class Menu {

public:

    int chooseMoveDirection();
    int twoChoicesMenu(string, string);
    int threeChoicesMenu(string, string, string);
    int fourChoicesMenu(string, string, string, string);

};


#endif //FINALPROJECT_MENU_HPP
