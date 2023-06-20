#include "Book.h"

Book::Book()
{
	title = "no title";
	year = 0;
	author = "no author";
	pages = 0;
	genre = None;
}

void Book::ShowInfo() const
{
	cout << "Title : " << title << endl;
	cout << "Year : " << year << endl;
	cout << "Author : " << author << endl;
	cout << "Pages : " << pages << endl;
	cout << "Genre : " << genre << " : ";
	
	switch (genre)
	{
	case None:cout << "None" << endl;break;
	case Horor:cout << "Horor" << endl;	break;
	case Adventure:cout << "Adventure" << endl;	break;
	case Classic:cout << "Classic" << endl;	break;
	case History:cout << "History" << endl;	break;
	case Novel:cout << "Novel" << endl;	break;
	case Programming:cout << "Programming" << endl;	break;
	case Detective:cout << "Detective" << endl;	break;
	case Comedy:cout << "Comedy" << endl;break;
	case Fantasy:cout << "Fantasy" << endl;	break;
	}	
}

