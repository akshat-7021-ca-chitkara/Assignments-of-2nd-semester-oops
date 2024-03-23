#include <iostream>
#include <string>
using namespace std;
/**
 * Represents a book.
 */
class Book
{
public:
    /**
     * Constructs a Book object with the given title, author, publisher, and ISBN.
     * @param title The title of the book.
     * @param author The author of the book.
     * @param publisher The publisher of the book.
     * @param ISBN The ISBN of the book.
     */
    string author;
    string title;
    string publisher;
    int ISBN;

    Book(const string &title, const string &author, const string &publisher, int ISBN)
    {
        this->author = author;
        this->title = title;
        this->publisher = publisher;
        this->ISBN = ISBN;
    }
};
// This class represents a library
class Library
{
    Book *books[100];
    int count;

public:
    // Default constructor
    Library() : count(0) {}
    // Adds a book to the library
    void addBook(const string &title, const string &author, const string &publisher, int ISBN)
    {
        books[count++] = new Book(title, author, publisher, ISBN);
    }
    /**
    Function: findBook

    This function searches for a book in the library based on its ISBN.

    If the book is found, it prints out the book's title, author, and publisher.

    If the book is not found, it prints out a message indicating that the book is not in the library.

    @param ISBN: the ISBN of the book to be searched for
    */
    void findBook(int ISBN)
    {
        for (int i = 0; i < count; i++)
        {
            if (books[i]->ISBN == ISBN)
            {
                cout << "Book found: "
                    << "'" << books[i]->title << "'"
                    << " written by "
                    << "'" << books[i]->author << "'"
                    << " & published by "
                    << "'" << books[i]->publisher << "'" << endl;
                return;
            }
        }
        cout << "Book not found in the library." << endl;
    }
};

int main()
{
    int isbnBook;
    Library library;
    library.addBook("Atomic Habits", "James Clear", "Penguin Random House", 56123);
    library.addBook("Awekening The Giant Within", "Tony Robbins", "Simon & Schuster", 42356);
    library.addBook("The Four Agreements", "Don Miguel Ruiz", "Amber-Allen Publishing", 98789);

    do
    {
        cout << "Enter ISBN of book(or '0' for quit): " << endl;
        cin >> isbnBook;
        library.findBook(isbnBook);
    } while (isbnBook != 0);

    return 0;
}
