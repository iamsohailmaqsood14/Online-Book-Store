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

// Define the User class
class User {
public:
    string username;
    string password;
    bool isAdmin;
    double balance;
    Book* shoppingCart[100];
    Book* orderHistory[100];
    Book* wishList[100]; // User's wish list
    string address[100]; // User's address
    string paymentMethods[100]; // User's payment methods
    string deliveryOptions[100]; // User's delivery options
    string orderTracking[100]; // User's order tracking information
    string giftCards[100]; // User's gift cards
    int cartSize = 0;
    int orderHistorySize = 0;
    int wishListSize = 0; // Size of the wish list
    int addressSize = 0;
    int paymentMethodsSize = 0;
    int deliveryOptionsSize = 0;
    int orderTrackingSize = 0;
    int giftCardsSize = 0;

    // Constructor
    User(const string& _username, const string& _password, bool _isAdmin = false, double _balance = 0.0) 
        : username(_username), password(_password), isAdmin(_isAdmin), balance(_balance) {}

    // Function to add a book to the shopping cart
    void addToCart(Book* book) {
        shoppingCart[cartSize++] = book;
        cout << "Book added to cart successfully!" << endl;
    }

    // Function to display shopping cart contents
    void displayCart() const {
        if (cartSize == 0) {
            cout << "Shopping cart is empty." << endl;
        } else {
            cout << "Shopping Cart:" << endl;
            for (int i = 0; i < cartSize; ++i) {
                cout << "Title: " << shoppingCart[i]->getTitle()
                     << " | Price: $" << shoppingCart[i]->getPrice() << endl;
            }
        }
    }

    // Function to add a book to the wish list
    void addToWishList(Book* book) {
        wishList[wishListSize++] = book;
        cout << "Book added to wish list successfully!" << endl;
    }

    // Function to display wish list contents
    void displayWishList() const {
        if (wishListSize == 0) {
            cout << "Wish list is empty." << endl;
        } else {
            cout << "Wish List:" << endl;
            for (int i = 0; i < wishListSize; ++i) {
                cout << "Title: " << wishList[i]->getTitle()
                     << " | Price: $" << wishList[i]->getPrice() << endl;
            }
        }
    }

    // Function to place order
    void placeOrder() {
        if (cartSize == 0) {
            cout << "Cannot place order. Shopping cart is empty." << endl;
        } else {
            // Move books from shopping cart to order history
            for (int i = 0; i < cartSize; ++i) {
                orderHistory[orderHistorySize++] = shoppingCart[i];
            }
            // Clear the shopping cart
            cartSize = 0;
            cout << "Order placed successfully!" << endl;
        }
    }

    // Function to view order history
    void viewOrderHistory() const {
        if (orderHistorySize == 0) {
            cout << "Order history is empty." << endl;
        } else {
            cout << "Order History:" << endl;
            for (int i = 0; i < orderHistorySize; ++i) {
                cout << "Title: " << orderHistory[i]->getTitle()
                     << " | Price: $" << orderHistory[i]->getPrice() << endl;
            }
        }
    }

    // Function to edit profile information
    void editProfile() {
        int choice;
        cout << "Edit Profile:" << endl;
        cout << "1. Update Address" << endl;
        cout << "2. Add Payment Method" << endl;
        cout << "3. Add Delivery Option" << endl;
        cout << "4. Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string newAddress;
                cout << "Enter new address: ";
                cin.ignore(); // Ignore newline character
                getline(cin, newAddress);
                addAddress(newAddress);
                break;
            }
            case 2: {
                int paymentChoice;
                cout << "Choose payment method:" << endl;
                cout << "1. Card" << endl;
                cout << "2. Cash" << endl;
                cout << "Enter your choice: ";
                cin >> paymentChoice;
                if (paymentChoice == 1) {
                    string cardNumber;
                    cout << "Enter card number: ";
                    cin >> cardNumber;
                    addPaymentMethod("Card: " + cardNumber);
                } else if (paymentChoice == 2) {
                    addPaymentMethod("Cash");
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
                break;
            }
            case 3: {
                string deliveryOption;
                cout << "Enter delivery option: ";
                cin.ignore(); // Ignore newline character
                getline(cin, deliveryOption);
                addDeliveryOption(deliveryOption);
                break;
            }
            case 4:
                cout << "Going back to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    // Function to add an address
    void addAddress(const string& newAddress) {
        address[addressSize++] = newAddress;
        cout << "Address added successfully!" << endl;
    }

    // Function to add a payment method
    void addPaymentMethod(const string& paymentMethod) {
        paymentMethods[paymentMethodsSize++] = paymentMethod;
        cout << "Payment method added successfully!" << endl;
    }

    // Function to add a delivery option
    void addDeliveryOption(const string& deliveryOption) {
        deliveryOptions[deliveryOptionsSize++] = deliveryOption;
        cout << "Delivery option added successfully!" << endl;
    }

    // Function to track orders
    void trackOrder(const string& orderID) {
        // Implement order tracking functionality here
        cout << "Order tracked successfully!" << endl;
    }

    // Function to add a gift card
    void addGiftCard(const string& giftCard) {
        giftCards[giftCardsSize++] = giftCard;
        cout << "Gift card added successfully!" << endl;
    }
};
