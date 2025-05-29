#include <iostream>
#include <cstring>
using namespace std;

// SHALLOW COPY CLASS - This has problems!
class ShallowBook {
private:
    char* title;  // Pointer to book title
    int pages;

public:
    // Constructor
    ShallowBook(const char* t, int p) {
        pages = p;
        title = new char[strlen(t) + 1];  // Allocate memory
        strcpy(title, t);                 // Copy the title
        cout << "Created book: " << title << endl;
    }
    
    // No custom copy constructor - uses default (shallow copy)
    // This means: title pointer is copied, NOT the actual string!
    
    // Destructor
    ~ShallowBook() {
        cout << "Deleting book: " << title << endl;
        delete[] title;  // Free memory
    }
    
    void display() {
        cout << "Title: " << title << ", Pages: " << pages << endl;
    }
    
    void changeTitle(const char* newTitle) {
        delete[] title;
        title = new char[strlen(newTitle) + 1];
        strcpy(title, newTitle);
    }
};

// DEEP COPY CLASS - This is safe!
class DeepBook {
private:
    char* title;  // Pointer to book title
    int pages;

public:
    // Constructor
    DeepBook(const char* t, int p) {
        pages = p;
        title = new char[strlen(t) + 1];  // Allocate memory
        strcpy(title, t);                 // Copy the title
        cout << "Created book: " << title << endl;
    }
    
    // CUSTOM COPY CONSTRUCTOR - Deep Copy
    DeepBook(const DeepBook& other) {
        pages = other.pages;
        // Create NEW memory and copy the string content
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
        cout << "Deep copied book: " << title << endl;
    }
    
    // Destructor
    ~DeepBook() {
        cout << "Deleting book: " << title << endl;
        delete[] title;  // Free memory - safe now!
    }
    
    void display() {
        cout << "Title: " << title << ", Pages: " << pages << endl;
    }
    
    void changeTitle(const char* newTitle) {
        delete[] title;
        title = new char[strlen(newTitle) + 1];
        strcpy(title, newTitle);
    }
};

int main() {
    cout << "=== SHALLOW COPY PROBLEM ===" << endl;
    
    // Create original book
    ShallowBook book1("C++ Programming", 500);
    book1.display();
    
    // Make a copy - this uses shallow copy (default copy constructor)
    ShallowBook book2 = book1;  // PROBLEM: Both point to same memory!
    book2.display();
    
    cout << "\nBoth books share the same memory for title!" << endl;
    cout << "When program ends, both destructors try to delete the same memory" << endl;
    cout << "This causes a CRASH! (We'll see error messages)" << endl;
    
    // Uncomment next line to see the crash:
    // book2.changeTitle("New Title");  // This would crash book1!
    
    cout << "\n=== DEEP COPY SOLUTION ===" << endl;
    
    // Create original book
    DeepBook book3("Java Programming", 400);
    book3.display();
    
    // Make a copy - this uses deep copy (custom copy constructor)
    DeepBook book4 = book3;  // SAFE: Each has its own memory!
    book4.display();
    
    cout << "\nEach book has its own memory - safe to modify!" << endl;
    book4.changeTitle("Advanced Java");
    
    cout << "After modifying book4:" << endl;
    cout << "Book 3: ";
    book3.display();
    cout << "Book 4: ";
    book4.display();
    
    cout << "\nBoth books will be safely destroyed!" << endl;
    
    return 0;
}