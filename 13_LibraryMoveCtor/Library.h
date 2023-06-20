#pragma once
#include"Book.h"

class Library
{
private:
	string name;
	string address;
	Book* books;
	int bookCount;
public:
	Library();
	Library(string name, string address);
	void Show()const;
	void AddBook(Book b);
	Library(const Library& other);	
	Library( Library&& other);
	Library& operator =(const Library& other);
	~Library()
	{
		if (books != nullptr)
			delete[]books;
	}
};

