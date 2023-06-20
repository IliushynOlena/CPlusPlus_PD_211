#include "Library.h"

Library::Library()
{
	name = "no name";
	address = "no address";
	books = nullptr;
	bookCount = 0;
}

Library::Library(string name, string address)
{
	this->name = name;
	this->address = address;
	books = nullptr;
	bookCount = 0;
}

void Library::Show() const
{
	cout << "Name : " << name << endl;
	cout << "Address : " << address << endl;
	for (int i = 0; i < bookCount; i++)
	{
		books[i].ShowInfo(); 
		cout << endl;
	}
}

void Library::AddBook(Book b)
{
	Book* newbooks = new Book[bookCount + 1];
	for (int i = 0; i < bookCount; i++)
	{
		newbooks[i] = books[i];
	}
	newbooks[bookCount] = b;
	if (books != nullptr)
		delete[]books;
	books = newbooks;
	bookCount++;
}

Library::Library(const Library& other)
{
	name = other.name;
	address = other.address;
	bookCount = other.bookCount;
	books = new Book[other.bookCount];
	for (int i = 0; i < other.bookCount; i++)
	{
		books[i] = other.books[i];
	}
	cout << "Copy Constructor" << endl;
}

Library::Library(Library&& other)
{
	name = other.name;
	address = other.address;
	books = other.books;
	bookCount = other.bookCount;
	other.books = nullptr;
	cout << "Move c-tor" << endl;
}

Library& Library::operator=(const Library& other)
{
	name = other.name;
	address = other.address;
	bookCount = other.bookCount;
	if (books != nullptr)
		delete[]books;

	books = new Book[other.bookCount];
	for (int i = 0; i < other.bookCount; i++)
	{
		books[i] = other.books[i];
	}
	cout << "Operator [=]" << endl;
	return *this;
}
