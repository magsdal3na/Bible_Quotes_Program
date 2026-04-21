#ifndef BIBLE_VERSES_H_
#define BIBLE_VERSES_H_

#include <string> // might not need
#include <vector>

// defining struct accessible by all files
struct BibleVerse {
    std::string book;
    std::string verse;
    std::string text;
};

class Menu {
    public:
        // default constructor
        Menu();

        int option1();
        int option2();
        int option3();
        void menuDisplay();

    private:

};

#endif // BIBLE_VERSES_H_
