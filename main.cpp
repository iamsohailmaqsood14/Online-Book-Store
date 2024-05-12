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

// Define the BookManagementSystem class
class BookManagementSystem {
private:
    Book* books[100];
    int bookCount = 0;

public:
    // Function to add book (accessible to admin)
    void addBook(User& user, int id, string title, string author, string genre, string description, int quantity, double price) {
        if (user.isAdmin) {
            books[bookCount++] = new Book(id, title, author, genre, description, quantity, price);
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Insufficient privilege to add book." << endl;
        }
    }

    // Function to display books
    void displayBooks() const {
        cout << "Book List:" << endl;
        for (int i = 0; i < bookCount; ++i) {
            cout << "ID: " << books[i]->getId() << " | Title: " << books[i]->getTitle()
                 << " | Author: " << books[i]->getAuthor()
                 << " | Genre: " << books[i]->getGenre()
                 << " | Quantity: " << books[i]->getQuantity() << " | Price: $" << books[i]->getPrice() << endl;
        }
    }

    // Function to search books by title
    void searchBookByTitle(const string& searchTerm) const {
        bool found = false;
        cout << "Search Results:" << endl;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i]->getTitle().find(searchTerm) != string::npos) {
                cout << "ID: " << books[i]->getId() << " | Title: " << books[i]->getTitle()
                     << " | Author: " << books[i]->getAuthor()
                     << " | Genre: " << books[i]->getGenre()
                     << " | Quantity: " << books[i]->getQuantity() << " | Price: $" << books[i]->getPrice() << endl;
                found = true;
            }
        }
        if (!found)
            cout << "No matching books found." << endl;
    }

    // Function to filter books by price range
    void filterBooksByPrice(double minPrice, double maxPrice) const {
        bool found = false;
        cout << "Filtered Books:" << endl;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i]->getPrice() >= minPrice && books[i]->getPrice() <= maxPrice) {
                cout << "ID: " << books[i]->getId() << " | Title: " << books[i]->getTitle()
                     << " | Author: " << books[i]->getAuthor()
                     << " | Genre: " << books[i]->getGenre()
                     << " | Quantity: " << books[i]->getQuantity() << " | Price: $" << books[i]->getPrice() << endl;
                found = true;
            }
        }
        if (!found)
            cout << "No books found in the specified price range." << endl;
    }

    // Function to get a book by its ID
    Book* getBookById(int bookId) const {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i]->getId() == bookId) {
                return books[i];
            }
        }
        return nullptr; // Book not found
    }
};

// Function to write user data to file (for registration)
void writeUserToFile(const string& username, const string& password) {
    ofstream writefile(username + ".txt");
    if (writefile.is_open()) {
        writefile << password;
        writefile.close();
        cout << "User registered successfully!\n";
    } else {
        cerr << "Error writing to file.\n";
    }
}

// Function to register a new user
void registerUser() {
    string username, password, password2;

    cout << "Please enter your username: ";
    cin >> username;

    cout << "Please enter the password: ";
    cin >> password;

    cout << "Please re-enter your password: ";
    cin >> password2;

    if (password == password2) {
        writeUserToFile(username, password);
    } else {
        cout << "Passwords do not match. Registration failed.\n";
    }
}

// Function to login an existing user
bool loginUser() {
    string username, password;

    cout << "Please enter your username: ";
    cin >> username;

    cout << "Please enter your password: ";
    cin >> password;

    // Logic to verify username and password from stored data
    // For simplicity, we'll assume a successful login here
    return true;
}

// Function to logout
void logout() {
    // For this simple console-based application, logging out just means returning to the login/register screen
    cout << "Logged out successfully.\n";
}

int main() {
    cout << "Welcome to the Online Book Store!" << endl;

    while (true) {
        // Ask user to register or login
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (!loginUser()) {
                    cout << "Login failed. Exiting..." << endl;
                    return 0;
                }
                // After successful registration or login, proceed to online Book Store
                cout << "Welcome to the online Book Store!" << endl;
                {
                    BookManagementSystem bms;

                    // Create an admin user
                    User admin("admin", "adminpassword", true);

                    // Create a shopping cart for the user
                    User currentUser("currentuser", "currentuserpassword");

                    while (true) {
                        cout << "online Book Store|Read your heart out" << endl;
                        cout << "1. Add Book" << endl;
                        cout << "2. Display Books" << endl;
                        cout << "3. Search Book by Title" << endl;
                        cout << "4. Filter Books by Price Range" << endl;
                        cout << "5. Add to Cart" << endl;
                        cout << "6. View Shopping Cart" << endl;
                        cout << "7. Edit Profile" << endl;
                        cout << "8. Place Order" << endl;
                        cout << "9. View Order History" << endl;
                        cout << "10. Track Order" << endl;
                        cout << "11. Add Gift Card" << endl;
                        cout << "12. Add Review and Rating" << endl;
                        cout << "13. Add to Wish List" << endl;
                        cout << "14. Manage Inventory" << endl; // New option for inventory management
                        cout << "15. Logout" << endl;
                        cout << "16. Exit" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice;
                        switch (choice) {
                            case 1: {
                                int id, quantity;
                                string title, author, genre, description;
                                double price;
                                cout << "Enter book ID: ";
                                cin >> id;
                                cout << "Enter book title: ";
                                cin >> title;
                                cout << "Enter book author: ";
                                cin >> author;
                                cout << "Enter book genre: ";
                                cin >> genre;
                                cout << "Enter book description: ";
                                cin.ignore(); // Ignore newline character
                                getline(cin, description); // Read entire line
                                cout << "Enter book quantity: ";
                                cin >> quantity;
                                cout << "Enter book price: ";
                                cin >> price;
                                bms.addBook(admin, id, title, author, genre, description, quantity, price);
                                break;
                            }
                            case 2:
                                bms.displayBooks();
                                break;
                            case 3:
                                // Search book by title
                            {
                                string searchTerm;
                                cout << "Enter book title to search: ";
                                cin.ignore(); // Ignore newline character
                                getline(cin, searchTerm);
                                bms.searchBookByTitle(searchTerm);
                            }
                            break;
                            case 4:
                                // Filter books by price range
                            {
                                double minPrice, maxPrice;
                                cout << "Enter minimum price: ";
                                cin >> minPrice;
                                cout << "Enter maximum price: ";
                                cin >> maxPrice;
                                bms.filterBooksByPrice(minPrice, maxPrice);
                            }
                            break;
                            case 5: {
                                // Add to Cart functionality
                                int bookId;
                                cout << "Enter book ID to add to cart: ";
                                cin >> bookId;
                                Book* bookToAdd = bms.getBookById(bookId);
                                if (bookToAdd != nullptr) {
                                    currentUser.addToCart(bookToAdd);
                                } else {
                                    cout << "Book not found!" << endl;
                                }
                                break;
                            }
                            case 6:
                                currentUser.displayCart();
                                break;
                            case 7:
                                currentUser.editProfile();
                            case 8:
                                currentUser.placeOrder();
                                break;
                            case 9:
                                currentUser;
                                break;
                            case 10: {
                                string orderID;
                                cout << "Enter order ID to track: ";
                                cin >> orderID;
                                currentUser.trackOrder(orderID);
                                break;
                            }
                            case 11: {
                                string giftCard;
                                cout << "Enter gift card details: ";
                                cin.ignore(); // Ignore newline character
                                getline(cin, giftCard);
                                currentUser.addGiftCard(giftCard);
                                break;
                            }
                            case 12: {
                                // Add Review and Rating functionality
                                // Prompt user to enter review text and rating, then call addReview() method on the selected book
                                int bookId;
                                string reviewText;
                                int rating;
                                cout << "Enter book ID to review: ";
                                cin >> bookId;
                                cout << "Enter your review: ";
                                cin.ignore(); // Ignore newline character
                                getline(cin, reviewText);
                                cout << "Enter rating (1 to 5): ";
                                cin >> rating;
                                // getBookById(bookId)->addReview(reviewText, rating); // Implement getBookById function
                                cout << "Review added successfully!" << endl; // Remove this line once implemented getBookById
                                break;
                            }
                            case 13: {
                                // Add to Wish List functionality
                                int bookId;
                                cout << "Enter book ID to add to wish list: ";
                                cin >> bookId;
                                Book* bookToAdd = bms.getBookById(bookId);
                                if (bookToAdd != nullptr) {
                                    currentUser.addToWishList(bookToAdd);
                                } else {
                                    cout << "Book not found!" << endl;
                                }
                                break;
                            }
                             case 14:
                                // Manage Inventory
                                {
                                    int bookId, quantityToAdd, newQuantity;
                                    cout << "Enter book ID to manage inventory: ";
                                    cin >> bookId;
                                    Book* bookToManage = bms.getBookById(bookId);
                                    if (bookToManage != nullptr) {
                                        cout << "Current Stock Level: " << bookToManage->getQuantity() << endl;
                                        cout << "1. Add Stock" << endl;
                                        cout << "2. Update Stock Quantity" << endl;
                                        cout << "Enter your choice: ";
                                        int inventoryChoice;
                                        cin >> inventoryChoice;
                                        switch (inventoryChoice) {
                                            case 1:
                                                cout << "Enter quantity to add: ";
                                                cin >> quantityToAdd;
                                                bookToManage->addStock(quantityToAdd);
                                                break;
                                            case 2:
                                                cout << "Enter new quantity: ";
                                                cin >> newQuantity;
                                                bookToManage->updateStock(newQuantity);
                                                break;
                                            default:
                                                cout << "Invalid choice." << endl;
                                        }
                                    } else {
                                        cout << "Book not found!" << endl;
                                    }
                                    break;
                                }
                            case 15:
                                logout();
                                break;
                            case 16:
                                cout << "Exiting..." << endl;
                                return 0;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
