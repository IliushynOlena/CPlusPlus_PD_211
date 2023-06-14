#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point()
	{
		x = y = 0;
	}
	Point(int value)
	{
		x = y = value;
	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void Print()const
	{
		cout << "X : " << x << " Y: " << y << endl;
	}
	Point Plus(const Point&other)const
	{
		Point res(this->x + other.x, this->y + other.y);
		return res;
	}
	Point Minus(const Point& other)const
	{
		Point res(this->x - other.x, this->y - other.y);
		return res;
	}
	//this - other
	Point operator +(const Point& other)const
	{
		Point res(this->x + other.x, this->y + other.y);
		return res;
	}
	Point operator +(int value)const
	{
		Point res(this->x + value, this->y + value);
		return res;
	}
	Point operator -(const Point& other)const
	{
		Point res(this->x - other.x, this->y - other.y);
		return res;
	}
	Point operator *(const Point& other)const
	{
		Point res(this->x * other.x, this->y * other.y);
		return res;
	}
	Point operator /(const Point& other)const
	{
		Point res(this->x / other.x, this->y / other.y);
		return res;
		
	}
	Point operator +=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	Point operator-()const
	{
	/*	Point res(this->x * -1, this->y * -1);
		return res;*/

		return Point(-x, -y);
	}
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		return *this;
	}
	bool operator<(const Point& other)const
	{
		/*if ((this->x + this->y) < (other.x + other.y))
			return true;
		else
			return false;*/

		return (this->x + this->y) < (other.x + other.y);
	}
	bool operator>(const Point& other)const
	{
		return (this->x + this->y) > (other.x + other.y);
	}
	bool operator>=(const Point& other)const
	{
		return (this->x + this->y) >= (other.x + other.y);
	}
	bool operator<=(const Point& other)const
	{
		return (this->x + this->y) <= (other.x + other.y);
	}
	bool operator==(const Point& other)const
	{
		return (this->x == other.x) && (this->y == other.y);
	}
	bool operator!=(const Point& other)const
	{
		//return (this->x != other.x) || (this->y != other.y);
		return !(*this == other);
	}

};
int main()
{
	/*
	int a = 5;
	int b = 7;
	cout << a + b << endl;
	cout << a * b << endl;
	cout << a / b << endl;*/
	Point point1(2, 8);
	Point point2(8, 4);
	
	//cout << point1 + point2 << endl;
	cout << "Point 1 : "; point1.Print();
	cout << "Point 2 : "; point2.Print();
	Point res =  point1.Plus(point2);

	//point1 = point2;
	//res = point2 = point1;
	//cout << "Point 1 : "; point1.Print();
	//cout << "Point 2 : "; point2.Print();
	//cout << "Res : ";  res.Print();
	res = point2.Minus(point1);
	cout << "Res : ";  res.Print();
	//res = point1.operator+(point2);
	res = point1 + point2;
	cout << "Res : ";  res.Print();
	res = point1 + 15;
	cout << "Res : ";  res.Print();
	res = point1 - point2; //res = point1.operator-(point2);
	cout << "Res : ";  res.Print();
	res = point1 * point2; //res = point1.operator*(point2);
	cout << "Res : ";  res.Print();
	res = point1 / point2; //res = point1.operator/(point2);
	cout << "Res : ";  res.Print();

	point1 += 4;
	cout << "Point 1 : "; point1.Print();
	cout << "Point 2 : "; point2.Print();
	res = point1.operator-();
	cout << "Res : ";  res.Print();

	if (point1 > point2)//point1.operator<(point2)
	{
		cout << "p1 is bigger than p2" << endl;
	}
	else
	{
		cout << "p2 is bigger than p1" << endl;
	}

	if (point1 < point2)//point1.operator<(point2)
	{
		cout << "p1 is smaller than p2" << endl;
	}
	else
	{
		cout << "p2 is smaller than p1" << endl;
	}
	

	if (point1 == point2)//point1.operator<(point2)
	{
		cout << "p1 and  p2 is Equal" << endl;
	}
	else
	{
		cout << "p1 and  p2 is not Equal" << endl;
	}



  






}

