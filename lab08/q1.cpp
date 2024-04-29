#include <iostream>
using namespace std;

class Book {
    string title;
    string author;
    string publisher;
public:
    Book(const string& t, const string& a, const string& p) : title(t), author(a), publisher(p) {}

    void display() const {
        cout << "Book title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
    }
};

class FictionBook : public Book {
    string genre;
    string protagonist;
public:
    FictionBook(const string& g, const string& p, const string& t, const string& a, const string& pub)
        : genre(g), protagonist(p), Book(t, a, pub) {}

    void displayDetails() const {
        display();
        cout << "Genre: " << genre << endl;
        cout << "Protagonist: " << protagonist << endl;
    }
};

int main() {
    FictionBook fb("Adventure", "Jacck", "Back to the dream time", "Williamson kent", "Oxford");
    fb.displayDetails();
    return 0;
}
