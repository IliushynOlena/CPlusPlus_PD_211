#include <iostream>
#include<Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

struct Coord
{
	int x;
	int	y;
};

class MyRectangle
{
private:

	float width;
	float height;
	char symbol;
	float perimeter;
	Coord coord;

public:

	MyRectangle()
	{
		cout << " Constructor :: " << endl;
		width = 1;
		height = 1;
		perimeter = 1;
		symbol = '@';
		coord.x = 0;
		coord.y = 0;
	}
	MyRectangle(float value)
	{
		this->height = value;
		this->width = value;
		symbol = '@';
		coord.x = 0;
		coord.y = 0;
	}
	MyRectangle(float h, float w)
	{
		this->height = h;
		this->width = w;
		symbol = '@';
		coord.x = 0;
		coord.y = 0;
	}


	void InputRectangle()
	{
		cout << " Width :: ";
		cin >> width;
		if (width <= 0)
		{
			cout << " ERROR???.. ";
			system("cls");
			InputRectangle();
		}

		cout << " Height :: ";
		cin >> height;
		if (height <= 0)
		{
			cout << " ERROR???.. ";
			system("cls");
			InputRectangle();
		}

		cout << " Symbol :: ";
		cin >> symbol;//спитать у вчительки, як зробити первірку від тупиш користувачів!!!
		/*if (symbol == ' ')
		{
			cout << " ERROR???.. ";
			system("cls");
			InputRectangle();
		}*/
		cout << " Enter X :: ";
		cin >> coord.x;
		if (coord.x <= -1)
		{
			cout << " ERROR???.. ";
			system("cls");
			InputRectangle();		}

		cout << " Enter Y :: ";
		cin >> coord.y;
		if (coord.y <= -1)
		{
			cout << " ERROR???.. ";
			system("cls");
			InputRectangle();

		}
		cout << endl;
	}

	void PrintRectangle()
	{
		for (int i = 0; i < height; i++) 
		{
		    gotoxy(coord.x, coord.y + i);
			for (int j = 0; j < width; j++) 
			{
				cout << symbol;
			}
			cout << endl;
		}
	}
	void setSize(int newH, int newW)
	{
		this->height = newH;
		this->width = newW;
	}
	void setNewPisition(int x, int y)
	{
		this->coord.x = x;
		this->coord.y = y;
	}

	~MyRectangle()
	{
		cout << "\n Destructor " << endl;
	}
};

int main()
{
	MyRectangle rec(10,15);
	Coord coo;

	//rec.InputRectangle();
	rec.PrintRectangle();
	rec.setNewPisition(10, 15);
	rec.setSize(5, 8);
	rec.PrintRectangle();


}
