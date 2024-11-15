#ifndef BOOK_H
#define BOOK_H

#include "Media.h"

class Book : public Media {
private:
    int weeksNYT;

public:
    Book(char t, const std::string& ti, const std::string& kn, int r, const std::string& g, int l, int y, int weeks)
        : Media(t, ti, kn, r, g, l, y), weeksNYT(weeks) {}

    void print(std::ostream& os) const override {
        os << "Book: " << title << " (" << yearReleased << ")\n";
        os << "Genre: " << genre << ", Rating: " << rating << "/10, Length: " << length << " pages\n";
        os << "Weeks on NYT Bestseller List: " << weeksNYT << "\n";
    }
};

#endif
