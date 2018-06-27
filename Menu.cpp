/**********************************************************************************************************************
 * This is the source file for the Menu Class.
 *********************************************************************************************************************/

#include "Menu.hpp"

/**********************************************************************************************************************
 * chooseMoveDirection()
 * @return the direction the player would like to move.
 * This function is outputted to the user anytime they would like to move to a different room in the house.
 *********************************************************************************************************************/


int Menu::chooseMoveDirection() {

    string strMoveDirection;
    int intMoveDirection = 0;

    while (intMoveDirection < 1 || intMoveDirection > 4) {
        cout <<"---------------------------------------------------------------------------------------------------";
        cout << endl;
        cout << "Which direction would you like to go?" << endl << endl;
        cout << "[1]: Forward" << endl << "[2]: Left" << endl << "[3]: Right" << endl << "[4]: Backwards" << endl;
        cout <<"---------------------------------------------------------------------------------------------------";
        cout << endl;
        cin >> strMoveDirection;

        if (strMoveDirection.size() == 1) {

            std::stringstream strStream; //http://www.learncpp.com/cpp-tutorial/185-stream-states-and-input-validation/
            strStream << strMoveDirection;
            strStream >> intMoveDirection;

            if (intMoveDirection == 1) {
                return intMoveDirection;

            } else if (intMoveDirection == 2) {
                return intMoveDirection;
            }
            else if (intMoveDirection == 3) {
                return intMoveDirection;
            }
            else if(intMoveDirection == 4) {
                return intMoveDirection;
            }
            else {
                cout << "Invalid input. Please enter a valid selection." << endl;
            }
        }
        else{
            cout << "Invalid input. Please enter a valid selection." << endl;
        }
    }
    return 0;
}

/**********************************************************************************************************************
 * 2,3,4 choices menus
 * @param  each parameter is the string for a menu option.
 * @return the int that cooresponds to the users choice.
 * The following three menu functions all work the same way. Depending on how many options you would like the menu to
 * have, call that function and input the same number of strings as arguments which will coorespond to the avaliable
 * menu choices.
 *********************************************************************************************************************/

int Menu::twoChoicesMenu(string op1, string op2) {


    string str2ChoiceSelection;
    int int2ChoiceSelection = 0;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout << "What would you like to do?" << endl << endl;

    while (int2ChoiceSelection < 1 || int2ChoiceSelection > 2) {

        cout << "[1]: " << op1 <<  endl << "[2]: " << op2 << endl;
        cout <<"---------------------------------------------------------------------------------------------------";
        cout << endl;
        cin >> str2ChoiceSelection;

        if (str2ChoiceSelection.size() == 1) {

            std::stringstream strStream; //http://www.learncpp.com/cpp-tutorial/185-stream-states-and-input-validation/
            strStream << str2ChoiceSelection;
            strStream >> int2ChoiceSelection;

            if (int2ChoiceSelection == 1) {
                return int2ChoiceSelection;

            } else if (int2ChoiceSelection == 2) {
                return int2ChoiceSelection;

            } else {
                cout << "Invalid input. Please enter a valid selection." << endl;
            }
        }
        else{
            cout << "Invalid input. Please enter a valid selection." << endl;
        }
    }
    return 4;
}

int Menu::threeChoicesMenu(string option1, string option2, string option3) {


        string str3ChoiceSelection;
        int int3ChoiceSelection = 0;
        cout <<"---------------------------------------------------------------------------------------------------";
        cout << endl;
        cout << "What would you like to do?" << endl << endl;

        while (int3ChoiceSelection < 1 || int3ChoiceSelection > 3) {

            cout << "[1]: " << option1 <<  endl << "[2]: " << option2 << endl << "[3]: " << option3 << endl;
            cout <<"--------------------------------------------------------------------------------------------------";
            cout << endl;
            cin >> str3ChoiceSelection;

            if (str3ChoiceSelection.size() == 1) {

                std::stringstream strStream;
                //http://www.learncpp.com/cpp-tutorial/185-stream-states-and-input-validation/
                strStream << str3ChoiceSelection;
                strStream >> int3ChoiceSelection;

                if (int3ChoiceSelection == 1) {
                    return int3ChoiceSelection;

                } else if (int3ChoiceSelection == 2) {
                    return int3ChoiceSelection;

                } else if(int3ChoiceSelection == 3){

                    return int3ChoiceSelection;
                }
                else {
                    cout << "Invalid input. Please enter a valid selection." << endl;
                }
            }
            else{
                cout << "Invalid input. Please enter a valid selection." << endl;
            }
        }
        return 4;
}

int Menu::fourChoicesMenu(string option1, string option2, string option3, string option4) {

    string str4ChoiceSelection;
    int int4ChoiceSelection = 0;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout << "What would you like to do?" << endl << endl;

    while (int4ChoiceSelection < 1 || int4ChoiceSelection > 4) {

        cout << "[1]: " << option1 <<  endl << "[2]: " << option2 << endl << "[3]: " << option3 << endl;
        cout << "[4]: " << option4 << endl;
        cout <<"---------------------------------------------------------------------------------------------------";
        cout << endl;
        cin >> str4ChoiceSelection;

        if (str4ChoiceSelection.size() == 1) {

            std::stringstream strStream; //http://www.learncpp.com/cpp-tutorial/185-stream-states-and-input-validation/
            strStream << str4ChoiceSelection;
            strStream >> int4ChoiceSelection;

            if (int4ChoiceSelection == 1) {
                return int4ChoiceSelection;

            } else if (int4ChoiceSelection == 2) {
                return int4ChoiceSelection;

            } else if(int4ChoiceSelection == 3){
                return int4ChoiceSelection;

            } else if (int4ChoiceSelection == 4){
                return int4ChoiceSelection;
            }
            else {
                cout << "Invalid input. Please enter a valid selection." << endl;
            }
        }
        else{
            cout << "Invalid input. Please enter a valid selection." << endl;
        }
    }
    return 5;

}

