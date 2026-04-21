#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <random> // for outputting random quotes
#include "bibleverses.h"
using namespace std;

int main() {
    Menu myVerses;
    int selection = 0;

    cout << "Welcome to the \"Verse of the Day\" Program!" << endl;
    cout << "Please enter 1 - 4 to continue: " << endl;

    cin >> selection;

    while (selection != 4) {
        while (selection == 1) {
            myVerses.option1();
            cout << endl;
            cout << "Enter 1 - 3 to continue. Enter 4 to quit: " << endl;
            cin >> selection;
        }
        while (selection == 2) {
            cout << "placeholder text" << endl;
            cin >> selection;
        }
    }
    return 0;
}
