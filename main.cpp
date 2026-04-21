#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <random> // for outputting random quotes
#include "bibleverses.h"
using namespace std;

int main() {
    int selection = 0;

    cout << "Enter number for test output." << endl;
    cin >> selection;

    while (selection != 3) {
        if (selection == 1) {
            cout << "Test" << endl;
            cin >> selection;
        }
        if (selection == 2) {
        cout << "Test 2" << endl;
        cin >> selection;
        }
    }

    return 0;
}
