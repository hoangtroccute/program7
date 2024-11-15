#ifndef SONG_H
#define SONG_H

#include "Media.h"

class Song : public Media {
private:
    bool top40;

public:
    Song(char t, const std::string& ti, const std::string& kn, int r, const std::string& g, int l, int y, bool top)
        : Media(t, ti, kn, r, g, l, y), top40(top) {}

    void print(std::ostream& os) const override {
        os << "Song: " << title << " (" << yearReleased << ")\n";
        os << "Genre: " << genre << ", Rating: " << rating << "/10, Length: " << length << " min\n";
        os << "Top 40: " << (top40 ? "Yes" : "No") << "\n";
    }
};

#endif
