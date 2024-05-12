#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Define the Review class
class Review {
private:
    string text;
    int rating; // Rating on a scale of 1 to 5

public:
    // Default constructor
    Review() : text(""), rating(0) {}

    // Constructor with parameters
    Review(const string& _text, int _rating) : text(_text), rating(_rating) {}

    // Getter functions
    string getText() const { return text; }
    int getRating() const { return rating; }
};
