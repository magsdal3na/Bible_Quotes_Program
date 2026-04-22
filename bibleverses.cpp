#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype> // to use tolower
#include <vector>
#include <random>
#include "bibleverses.h"
using namespace std;

// sets up basic constructor
Menu::Menu() {
    string line = "";
}

// user requests rand quote
int Menu::option1() {
    ifstream inFS("bibleverses.txt");
    string line;
    vector<BibleVerse> library;
    
    try {
        // attempts to open .txt file

        if (!inFS.is_open()) {
            cout << "Failed to open file." << endl;
            throw runtime_error("File System Error: Unable to locate or open the input data file.");
        }

        while (getline(inFS, line)) {
            if (line.empty()) continue; // skips empty lines
            stringstream ss(line);
            string bookName, verseNumber, verseContent;

            if (getline(ss, bookName, '|') && getline(ss, verseNumber, '|') && getline(ss, verseContent)) {
                    library.push_back({bookName, verseNumber, verseContent});
                    }
                }

        // attempting random quote output
        if (library.empty()) {
            cout << "Library is empty! Load some verses and try again." << endl;
            return 1;
        }

        // initializing random number generator
        random_device rd;
        mt19937 gen(rd());

        // defining range of vector
        uniform_int_distribution<> distr(0, library.size() -1);

        // picks random index
        int randomIndex = distr(gen);

        // access struct at that index and print
        BibleVerse selected = library[randomIndex];
        cout << endl;
        cout << "Random Verse: " << endl;
        cout << setfill('-') << setw(15) << " " << endl;
        cout << setfill(' ') << selected.book << " " << selected.verse << endl << selected.text << endl;
    }

    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
        return 1; // signals error to main()
    }
    return 0;
}

// user requests rand quote from specific book
int Menu::option2() {
    ifstream inFS("bibleverses.txt");
    string line;
    string bookSearch;
    vector<BibleVerse> library;
    
    try {
        // attempts to open .txt file

        if (!inFS.is_open()) {
            cout << "Failed to open file." << endl;
            throw runtime_error("File System Error: Unable to locate or open the input data file.");
        }

        while (getline(inFS, line)) {
            if (line.empty()) continue; // skips empty lines
            stringstream ss(line);
            string bookName, verseNumber, verseContent;

            if (getline(ss, bookName, '|') && getline(ss, verseNumber, '|') && getline(ss, verseContent)) {
                    library.push_back({bookName, verseNumber, verseContent});
                    }
                }

        // attempting random quote output
        if (library.empty()) {
            cout << "Library is empty! Load some verses and try again." << endl;
            return 1;
        }
        
        // clearing previous input to use getline() properly
        cin.ignore();

        cout << "Please enter the book you'd like a verse from: " << endl;
        getline(cin, bookSearch);

        string bookSearchLower = bookSearch;
        for (auto &c : bookSearchLower) c = tolower(c);

        // filter the library for user's book
        vector<BibleVerse> matches;
        for (const auto& v : library) {
            string libraryBookLower = v.book;
            for (auto &c : libraryBookLower) c = tolower(c);

            if (libraryBookLower == bookSearchLower) {
                matches.push_back(v);
            }
        }

        // handles results
        if (matches.empty()) {
            cout << "No verses found for " << bookSearch << ". Check your spelling or check back later!" << endl;
            return 1;
        }

        // pick random verse from matches
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, matches.size() - 1);

        BibleVerse selected = matches[distr(gen)];
        cout << endl;
        cout << "Random verse from " << bookSearch << ":" << endl;
        cout << setfill('-') << setw(35) << " " << endl;
        cout << setfill(' ') << selected.verse << " " << selected.text << endl;
    }

    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
        return 1; // signals error to main()
    }
    return 0;
}

// user requests all quotes from specific book
int Menu::option3() {

    return 0;
}
