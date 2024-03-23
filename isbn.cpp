#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string publisher;
    int year;
    string isbn; 
public:
   
    Book(string _title, string _author, string _publisher, int _year, string _isbn)
        : title(_title), author(_author), publisher(_publisher), year(_year), isbn(_isbn) {}

   
    void displayDetails() const { 
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Year: " << year << endl;
    }

    string getISBN() const {
        return isbn;
    }
};

int main() {
    Book books[] = {
        Book("Clean Code", "Robert C. Martin", "Prentice Hall", 2008, "978-0132350884"),
        Book("Effective C++", "Scott Meyers", "Addison-Wesley", 2005, "978-0321125217"),
        Book("Design Patterns", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides", "Addison-Wesley", 1994, "978-0201633610")
    };

    string inputISBN;
    cout << "Enter ISBN: ";
    cin >> inputISBN;

    bool bookFound = false;

    for (const Book& book : books) {
        if (book.getISBN() == inputISBN) {
            cout << "Book found:" << endl;
            book.displayDetails();
            bookFound = true;
            break;
        }
    }

    if (!bookFound) {
        cout << "Book not available in the library." << endl;
    }

    return 0;
}