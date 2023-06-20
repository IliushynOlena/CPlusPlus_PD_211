#include"Book.h"
#include "Library.h"


int main()
{
    Book book;
    Book book1("Harry Potter", 1997, "J.K.Rowling", 800, Fantasy);
    Book book2("Sherlock Holmes", 1887,"Arthur Conan Doyle",2000, Detective);
    Book book3("Java for kids",2015, "Morgan Nick", 408,Programming);
    Book book4("Mowgli", 1893, "Pantera", 500, Adventure);
    Book book5("Financier", 1911, "Dreiser Theodore", 377, Genre::Classic);
    book1.ShowInfo();

    Library lib("Happy Library", "Soborna 16");
    lib.AddBook(Book("Harry Potter", 1997, "J.K.Rowling", 800, Fantasy));
    lib.AddBook(book2);
    lib.AddBook(book3);
    lib.AddBook(book4);
    lib.AddBook(book5);
    lib.Show();
}

