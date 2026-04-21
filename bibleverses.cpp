#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype> // to use tolower
#include <vector>
#include "bibleverses.h"
using namespace std;

// sets up basic constructor
Menu::Menu() {

}

// user requests rand quote
int Menu::option1() {
    ifstream inFS;
    ifstream file("bibleverses.txt");
    string line;
    vector<BibleVerse> library;
    
    try {
        // attempts to open .txt file
        inFS.open("bibleverses.txt");

        if (!inFS.is_open()) {
            throw runtime_error("File System Error: Unable to locate or open the input data file.");
        }

        while (getline(file, line)) {
            stringstream ss(line);
            string bookName, verseNumber, verseContent;

            if (getline(ss, bookName, '|') && getline(ss, verseNumber) && getline(ss, verseContent)) {
                library.push_back({bookName, verseNumber, verseContent});
            }
        }
    }

    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
        return 1; // signals error to main()
    }
    return 0;
}

// user requests rand quote from specific book
int Menu::option2() {

    return 0;
}

// user requests all quotes from specific book
int Menu::option3() {

    return 0;
}
