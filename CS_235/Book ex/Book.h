#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book();                     // constructor
    Book(string t, string a);   // constructor
    ~Book();                    // decontructor (in lab, suggested to write contents to file)

    // getter
    string getTitle() const;
    string getAuthor() const;

    // setter
    void setTitle(string title);
    void setAuthor(string author);

    string toString() const;
};



#endif