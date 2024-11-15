#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Movie.h"
#include "Book.h"
#include "Song.h"

// Function to read media data from a file
void readMediaList(const std::string& filename, std::vector<Media*>& mediaList) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char type;
        std::string title, keyName, genre;
        int rating, length, year;
        iss >> type;
        iss.ignore(); // Skip the delimiter

        std::getline(iss, title, ',');
        std::getline(iss, keyName, ',');
        iss >> rating >> length >> year;
        iss.ignore(); // Skip the delimiter
        std::getline(iss, genre, ',');

        if (type == 'M') {
            std::vector<std::string> stars;
            std::string star;
            while (std::getline(iss, star, ',')) {
                stars.push_back(star);
            }
            mediaList.push_back(new Movie(type, title, keyName, rating, genre, length, year, stars));
        } else if (type == 'B') {
            int weeks;
            iss >> weeks;
            mediaList.push_back(new Book(type, title, keyName, rating, genre, length, year, weeks));
        } else if (type == 'S') {
            bool top40;
            iss >> top40;
            mediaList.push_back(new Song(type, title, keyName, rating, genre, length, year, top40));
        }
    }
}

// Function to handle commands from a file
void handleCommands(const std::string& filename, std::vector<Media*>& mediaList) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << "\n";
        return;
    }

    std::string command;
    while (std::getline(file, command)) {
        if (command == "A") {
            // Print all media
            for (const auto* media : mediaList) {
                media->print(std::cout);
                std::cout << "\n";
            }
        }
        // Additional commands can be handled here
    }
}

int main() {
    std::vector<Media*> mediaList;

    // Read media data from file
    readMediaList("mediaList.txt", mediaList);

    // Handle commands from file
    handleCommands("mediaCommands.txt", mediaList);

    // Clean up dynamically allocated memory
    for (auto* media : mediaList) {
        delete media;
    }

    return 0;
}
