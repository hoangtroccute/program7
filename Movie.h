#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"

class Movie : public Media {
private:
    std::vector<std::string> stars;

public:
    Movie(char t, const std::string& ti, const std::string& kn, int r, const std::string& g, int l, int y, const std::vector<std::string>& s)
        : Media(t, ti, kn, r, g, l, y), stars(s) {}

    void print(std::ostream& os) const override {
        os << "Movie: " << title << " (" << yearReleased << ")\n";
        os << "Genre: " << genre << ", Rating: " << rating << "/10, Length: " << length << " min\n";
        os << "Stars: ";
        for (const auto& star : stars) {
            os << star << " ";
        }
        os << "\n";
    }
};

#endif
