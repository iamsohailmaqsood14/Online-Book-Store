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

class Book {
private:
    int id;
    string title;
    string author;
    string genre;
    string description;
    int quantity; // Current stock quantity
    double price;
    Review reviews[100]; // Collection of reviews
    int reviewCount;

public:
    // Constructor with description parameter
    Book(int _id, string _title, string _author, string _genre, string _description, int _quantity, double _price) 
        : id(_id), title(_title), author(_author), genre(_genre), description(_description), 
          quantity(_quantity), price(_price), reviewCount(0) {}

    // Getter functions
    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }
    string getDescription() const { return description; }
    int getQuantity() const { return quantity; } // Get current stock quantity
    double getPrice() const { return price; }

    // Function to add stock
    void addStock(int quantityToAdd) {
        quantity += quantityToAdd;
        cout << "Stock added successfully. New quantity: " << quantity << endl;
    }

    // Function to update stock quantity
    void updateStock(int newQuantity) {
        quantity = newQuantity;
        cout << "Stock quantity updated successfully. New quantity: " << quantity << endl;
    }

    // Function to display current stock level
    void displayStock() const {
        cout << "Current Stock Level for " << title << ": " << quantity << endl;
    }

    // Function to add a review
    void addReview(const string& reviewText, int rating) {
        if (reviewCount < 100) {
            reviews[reviewCount++] = Review(reviewText, rating);
            cout << "Review added successfully!" << endl;
        } else {
            cout << "Maximum review limit reached." << endl;
        }
    }

    // Function to display reviews and ratings
    void displayReviews() const {
        if (reviewCount == 0) {
            cout << "No reviews available for this book." << endl;
        } else {
            cout << "Book Reviews:" << endl;
            for (int i = 0; i < reviewCount; ++i) {
                cout << "Rating: " << reviews[i].getRating() << " | Review: " << reviews[i].getText() << endl;
            }
        }
    }
};
