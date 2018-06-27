/**********************************************************************************************************************
 * This is the source file for the Base class, Space. The get and set functions are non virtual and are called from
 * here.
 *********************************************************************************************************************/

#include "Space.hpp"



void Space::setForward(Space * ptr) {

    forward = ptr;

}

void Space::setLeft(Space * ptr) {

    left = ptr;
}

void Space::setRight(Space * ptr) {

    right = ptr;
}

void Space::setBack(Space *ptr) {

    back = ptr;

}


Space* Space::getBack() {

    return back;
}

Space* Space::getForward() {

    return forward;
}

Space* Space::getLeft() {

    return left;
}

Space* Space::getRight() {

    return right;
}

string Space::getNameOfSpace() {

    return nameOfSpace;
}

