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
	//bool operator<(const Point& other)const
	//{
	//	/*if ((this->x + this->y) < (other.x + other.y))
	//		return true;
	//	else
	//		return false;*/

	//	return (this->x + this->y) < (other.x + other.y);
	//}
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
	Point operator++()//префіксна форма
	{
		++this->x;
		++this->y;
		return *this;
	}
	Point operator--()//префіксна форма
	{
		--this->x;
		--this->y;
		return *this;
	}
	Point operator++(int k)//постфіксна форма
	{
		this->x++;
		this->y++;
		return *this;
	}
	
	int getX()const
	{
		return x;
	}
	int getY()const
	{
		return y;
	}
	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	friend bool operator<(const Point& point1, const Point& point2);
	friend ostream& operator <<(ostream& out, const Point& point);
	friend istream& operator>>(istream& in,  Point& point);

	friend Point operator--(Point& mythis, int);//постфіксна форма
};
bool operator<(const Point& point1, const Point& point2)
{
	return (point1.x + point1.y) < (point2.x + point2.y);
}
ostream& operator <<(ostream& out, const Point& point)
{
	out << "X : " << point.x << " Y: " << point.y << endl;
	return out;
}
//cout << point1 ;
istream& operator>>(istream& in,  Point& point)
{
	//cin >> point;
	//istream cin;
	in >> point.x;
	//in.ignore();
	in >> point.y;
	return in;
}


Point operator--(Point &mythis, int)//постфіксна форма
{
	mythis.x--;
	mythis.y--;
	/*mythis.setX(mythis.getX()-1);
	mythis.setY(mythis.getY()-1);	*/
	return mythis;
}

//bool operator<(const Point& point1 ,const Point& point2)
//{
//	return (point1.getX() + point1.getY()) < (point2.getX() + point2.getY());
//}
int main()
{
	int a = 5;

	//int a = 5;
	//int b = 7;
	//a++;//postfix ->
	//++a;//prefix
	//cout << a++ << endl;//->
	//cout << ++a << endl;//<-
	//cout << a + b << endl;
	//cout << a * b << endl;
	//cout << a / b << endl;
	Point point1(2, 8);
	//ostream cout;
	
	point1--;
	cout << "Point 1 : "; point1.Print();

	Point point2(8, 4);	
	/*--point1;
	++point2;
	point1++;
	point2--;*/
	cout << (point1 < point2) << endl;
	//ostream
		//cin >> a;
	cout << "Enter point : ";
	cin >> point1;
	cout<< point1 <<  point2 << endl;
	
	//cout << point1 + point2 << endl;
	cout << "Point 1 : "; point1.Print();
	cout << "Point 2 : "; point2.Print();
	Point res =  point1.Plus(point2);
	res = point1 + point2;
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

