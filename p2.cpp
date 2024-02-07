#include <iostream>
#include <string>
using namespace std;

enum UserRole {
  ADMIN,
  STUDENT
};

struct User {
  string username;
  string password;
  UserRole role;
};

struct Book {
  string title;
  string author;
  int quantity;
  string borrower;
  bool isAvailable;
  UserRole requiredRole; // The role required to borrow or return the book
};

// Arrays to store users and their credentials
const int MAX_USERS = 100;
User users[MAX_USERS];
int userCount = 0;

// Array to store books
const int MAX_BOOKS = 100;
Book books[MAX_BOOKS];
int bookCount = 0;

// Current user's role
UserRole currentUserRole = ADMIN; // Initially set to ADMIN for testing

// Function to register a new user
void registerUser() {
  string username, password;

  cout << "Enter username: ";
  cin >> username;

  for (int i = 0; i < userCount; ++i) {
    if (users[i].username == username) {
      cout << "Username already exists. Please choose a different username." << endl;
      return;
    }
  }

  cout << "Enter password: ";
  cin >> password;

  User newUser = {username, password, STUDENT};
  users[userCount++] = newUser;

  cout << "Registration successful." << endl;
}

// Function to find a user by username
int findUserByUsername(const string& username) {
  for (int i = 0; i < userCount; ++i) {
    if (users[i].username == username) {
      return i;
    }
  }
  return -1; // User not found
}

// Function to log in a user
void loginUser(User& currentUser) {
  string username, password;

  cout << "Enter username: ";
  cin >> username;

  int index = findUserByUsername(username);
  if (index == -1) {
    cout << "Invalid username." << endl;
    return;
  }

  User user = users[index];

  cout << "Enter password: ";
  cin >> password;

  if (password != user.password) {
    cout << "Incorrect password." << endl;
    return;
  }

  cout << "Login successful." << endl;

  currentUser = user; // Update currentUser
}

// Function to add a book
void addBook() {
  if (currentUserRole != ADMIN) {
    cout << "Unauthorized access. Only admins can add books." << endl;
    return;
  }

  Book book;
  cout << "Enter book title: ";
  cin.ignore();  // Ignore any leftover newline character in the input buffer
  getline(cin, book.title);
  cout << "Enter book author: ";
  getline(cin, book.author);
  cout << "Enter book quantity: ";
  cin >> book.quantity;
  book.isAvailable = true;
  book.borrower = "";

  cout << "Enter required role for borrowing or returning this book (ADMIN/STUDENT): ";
  string roleString;
  cin >> roleString;

  if (roleString.compare("ADMIN") == 0) {
    book.requiredRole = ADMIN;
  } else if (roleString.compare("STUDENT") == 0) {
    book.requiredRole = STUDENT;
  } else {
    cout << "Invalid role. Please enter ADMIN or STUDENT." << endl;
    return;
  }

  books[bookCount++] = book;
  cout << "Book added successfully." << endl;
}

// Function to search for books
void searchBooks() {
  string searchTerm;
  cout << "Enter search term: ";
  cin.ignore();  // Ignore any leftover newline character in the input buffer
  getline(cin, searchTerm);

  for (int i = 0; i < bookCount; ++i) {
    if (books[i].title.find(searchTerm) != string::npos || books[i].author.find(searchTerm) != string::npos) {
      cout << "Book title: " << books[i].title << endl;
      cout << "Book author: " << books[i].author << endl;
      cout << "Quantity: " << books[i].quantity << endl;
      cout << "Available: " << (books[i].isAvailable ? "Yes" : "No") << endl;
      cout << "Required role: " << (books[i].requiredRole == ADMIN ? "ADMIN" : "STUDENT") << endl;
      cout << endl;
    }
  }
}

void borrowBook() {
  string bookTitle;
  cout << "Enter book title to borrow: ";
  cin >> bookTitle;

  for (Book& book : books) {
    if (bookTitle == book.title && book.isAvailable) {
      string borrowerName;
      cout << "Enter borrower name: ";
      cin >> borrowerName;

      book.isAvailable = false;
      book.borrower = borrowerName;

      cout << book.title << " is borrowed by " << borrowerName << "." << endl;
      return;
    }
  }

  cout << "Book not found or not available for borrowing." << endl;
}


void returnBook() {
  string bookTitle;
  cout << "Enter book title to return: ";
  cin >> bookTitle;

  for (Book& book : books) {
    if (bookTitle == book.title && !book.isAvailable) {
      book.isAvailable = true;
      book.borrower = "";

      cout << book.title << " is returned." << endl;
      return;
    }
  }

  cout << "Book not found or not currently borrowed." << endl;
}


void displayBooks() {
  for (const Book& book : books) {
    cout << "Book title: " << book.title << endl;
    cout << "Book author: " << book.author << endl;
    cout << "Quantity: " << book.quantity << endl;
    cout << "Available: " << (book.isAvailable ? "Yes" : "No") << endl;
    cout << "Required role: " << (book.requiredRole == ADMIN ? "ADMIN" : "STUDENT") << endl;
    cout << endl;
  }
}

void checkBorrowedBooks(const User& currentUser) {
  if (currentUser.role != STUDENT) {
    cout << "Unauthorized access. Only students can check borrowed books." << endl;
    return;
  }

  cout << "Books borrowed by you:" << endl;

  for (const Book& book : books) {
    if (book.borrower == currentUser.username) {
      cout << "Book title: " << book.title << endl;
      cout << "Book author: " << book.author << endl;
      cout << endl;
    }
  }

  cout << "End of list." << endl;
}


int main() {
  // Initialize books with some data
  Book book1 = {"The Lord of the Rings", "J.R.R. Tolkien", 2, "", true, STUDENT};
  books[bookCount++] = book1;

  Book book2 = {"The Hobbit", "J.R.R. Tolkien", 3, "", true, ADMIN};
  books[bookCount++] = book2;

  // Main menu loop
  int choice;
  User currentUser;

  do {
    cout << "--------------------------------------------" << endl;
    cout << "Book Management System" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1. Register User" << endl;
    cout << "2. Login" << endl;
    cout << "3. Add Book" << endl;
    cout << "4. Search Books" << endl;
    cout << "5. Borrow Book" << endl;
    cout << "6. Return Book" << endl;
    cout << "7. Display Books" << endl;
    cout << "8. Check Borrowed Books" << endl;
    cout << "9. Exit" << endl;
    cout << "\nPlease enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        registerUser();
        break;
      case 2:
        loginUser(currentUser); // Pass currentUser as a parameter to loginUser
        break;
      case 3:
        addBook();
        break;
      case 4:
        searchBooks();
        break;
      case 5:
        borrowBook();
        break;
      case 6:
        returnBook();
        break;
      case 7:
        displayBooks();
        break;
      case 8:
        checkBorrowedBooks(currentUser); // Pass currentUser as a parameter to checkBorrowedBooks
        break;
      case 9:
        cout << "\nExiting Book Management System.\n";
        break;
      default:
        cout << "\nInvalid choice. Please enter a valid option (1-9).\n";
    }
  } while (choice != 9);

  return 0;
}
