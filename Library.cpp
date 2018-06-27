/**********************************************************************************************************************
 * This is the source file for the Library class. It is a derived class from the base class, Space. It represents a
 * room in the house.
 *********************************************************************************************************************/

#include "Library.hpp"


Library::Library() {

    nameOfSpace = "Library";

}

void Library::displayMap() {

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
    cout << "|                                                  o       |" << endl;
    cout << "|              |                            |     /|\\      |" << endl;
    cout << "|              |                            |     / \\      |" << endl;
    cout << "------------------------------------------------------------" << endl;
}

void Library::displayRoomDialogue() {

    cout << "You enter the library. The smell of mildew is overwhelming as you see many books" << endl;
    cout << "have begun to fall apart in the moist tropical air of the island." << endl << endl;

    cout << "Two books lay on a small desk in the center of the room." << endl;
}

/**********************************************************************************************************************
 *                                          Library -spaceActionMenu()
 *
 * @return int that cooresponds with user's selection
 * This function controls all of the avaliable actions in the Library space. The user is able to inspect the desk
 * where they will add one of two books to their inventory.
 *********************************************************************************************************************/

int Library::spaceActionMenu() {

    Player playerObj;

    int getSelection = menuObj.threeChoicesMenu("Inspect the desk", "Move to a different room", "Exit");

    if (getSelection == 1){

        if (hasBook){

            cout << "There is nothing else of use on the desk." << endl << endl;
            return getSelection;
        }

        cout << "You approach the desk and see two books."<< endl;
        cout << "One book is titled: \"Hand to Hand Combat on the High Seas\"." << endl;
        cout << "The other book is titled: \"The Essential Sailors Joke Book\"." << endl << endl;

        int bookSelection = menuObj.twoChoicesMenu("Pick up \"Hand to Hand Combat on the High Seas\"",
                                                       "Pick up \"The Essential Sailors Joke Book\"");

        if (bookSelection == 1){

            cout << "As you pick up the book and flip through the pages, you notice the other book" << endl;
            cout << "disintegrates into a pile of debris on the desk. You study the book for a little" << endl;
            cout << "longer before putting it into your backpack." << endl;
            playerObj.addItemToBackpack(playerObj.getFightingBook());
            hasBook = true;
            return getSelection;
        }
        else{
            cout << "As you pick up the book and flip through the pages, you notice the other book" << endl;
            cout << "disintegrates into a pile of debris on the desk. You study the book for a little" << endl;
            cout << "longer before putting it into your backpack." << endl;
            playerObj.addItemToBackpack(playerObj.getJokeBook());
            hasBook = true;
            return getSelection;
        }


    }
    else{

        return getSelection;
    }
}

