/**********************************************************************************************************************
 * This is the header file for the base class. Space. It is an abstract class with two pure virtual functions.
 *********************************************************************************************************************/

#ifndef FINALPROJECT_SPACE_HPP
#define FINALPROJECT_SPACE_HPP

#include <iostream>
#include <string>
#include "Menu.hpp"



using std::cout;
using std::endl;
using std::string;


class Space {

protected:

    string nameOfSpace;

    Space *forward;
    Space *right;
    Space *left;
    Space *back;

    Menu menuObj;


public:

    virtual ~Space(){};

    virtual void displayRoomDialogue()=0;

    void setForward(Space*);
    void setLeft(Space*);
    void setRight(Space*);
    void setBack(Space*);

    Space* getLeft();
    Space* getRight();
    Space* getForward();
    Space* getBack();

    virtual string getNameOfSpace();
    virtual void displayMap()=0;
    virtual int spaceActionMenu()=0;

};

#endif //FINALPROJECT_SPACE_HPP
