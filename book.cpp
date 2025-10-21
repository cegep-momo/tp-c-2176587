#include "book.h"
#include <sstream>
#include <iostream>

Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerName("") {
}

Book::Book(const string& title, const string& author, const string& isbn) :
     title(title), author(author), isbn(isbn), isAvailable(true), borrowerName("") {
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return isbn;
}

bool Book::getAvailability() const {
    return isAvailable;
}

std::string Book::getBorrowerName() const {
    return borrowerName;
}

void Book::setTitle(const std::string& title) {
    this->title = title;
}

void Book::setAuthor(const std::string& author) {
    this->author = author;
}

void Book::setISBN(const std::string& isbn) {
    this->isbn = isbn;
}

void Book::setAvailability(bool isAvailable) {
    this->isAvailable = isAvailable;
}

void Book::setBorrowerName(const std::string& borrowerName) {
    this->borrowerName = borrowerName;
}

void Book::checkOut(const string& borrower) {
    if(isAvailable){
        setAvailability(false);
        setBorrowerName(borrower);
    } else {
        cout << "Ce livre n'est pas disponible." << endl;
    }
}
void Book::returnBook(){
    setAvailability(true);
    setBorrowerName("");
}

std::string Book::toString() const {
    return "Titre: " + title + "\n Auteur: " + author + "\n ISBN: " + isbn +
           "\n Disponible: " + (isAvailable ? "Oui" : "Non") +
           (isAvailable ? "" : "\n Emprunteur: " + borrowerName);
}

std::string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn +
           "|" + (isAvailable ? "1" : "0") + "|" +
           (isAvailable ? "" : borrowerName);
}

std::string Book::toCSVFormat() const {
    return title + ";" + author + ";" + isbn +
           ";" + (isAvailable ? "1" : "0") + ";" +
           (isAvailable ? "" : borrowerName);
}

void Book::fromFileFormat(const string& line){
    stringstream ss(line);
    
    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');

    string availability;
    getline(ss, availability, '|');
    isAvailable = (availability == "1");
    
    if (isAvailable)
        borrowerName = "";
    else
        getline(ss, borrowerName, '|');
}