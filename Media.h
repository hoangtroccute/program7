#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>
#include <vector>

// Base class for all types of media
class Media {
protected:
    char type;
    std::string title;
    std::string keyName;
    int rating;
    std::string genre;
    int length;
    int yearReleased;

public:
    Media(char t, const std::string& ti, const std::string& kn, int r, const std::string& g, int l, int y)
        : type(t), title(ti), keyName(kn), rating(r), genre(g), length(l), yearReleased(y) {}

    virtual ~Media() = default; // Virtual destructor for proper cleanup

    // Pure virtual function to be implemented by derived classes
    virtual void print(std::ostream& os) const = 0;

    // Getters
    char getType() const { return type; }
    std::string getTitle() const { return title; }
    std::string getKeyName() const { return keyName; }
    int getRating() const { return rating; }
    std::string getGenre() const { return genre; }
    int getLength() const { return length; }
    int getYearReleased() const { return yearReleased; }

    // Setters
    void setRating(int r) { rating = r; }
    void setLength(int l) { length = l; }
    void setYearReleased(int y) { yearReleased = y; }
};

#endif
