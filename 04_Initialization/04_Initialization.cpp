#include <iostream>
using namespace std;
class Point
{
    int x;
    int y;
public:
    Point() :x(0), y(0) { cout << "Default c-tor" << endl; }
    /*{
        this->x = 0;
        this->y = 0;
    }*/
    Point(int x, int y) :x{ x }, y{ y } {}
  /*  {
        this->x = x;
        this->y = y;
    }*/
    void Print()
    {
        cout << "X : " << x << " Y :" << y << endl;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};
class Rectangle
{
    Point leftUpCorner;
    int width;
    int height;
public:
    Rectangle()
    {
        leftUpCorner.setX(0);
        leftUpCorner.setY(0);
        width = 0;
        height = 0;
        cout << "Default constructor" << endl;
    }
    Rectangle(int x, int y, int w, int h):width(w), height(h)
    {
        leftUpCorner.setX(x);
        leftUpCorner.setY(y);
       // width = w;
        //height = h;
        cout << "Rectangle parametrized constructor" << endl;
    }
    void Print()
    {
        cout << leftUpCorner.getX() << " " << leftUpCorner.getY() << " " << width << " " << height << endl;
    }

};
int main()
{
    Point p;
    //cout << Print << endl;
    //Print();
    p.Print();
    Point p2(10, 15);
    p2.Print();
    Point p3{ 5,7 };
    p3.Print();

    
    /*
    int answer{ 42 };
    const float goodTemp{ 36.6 };
    int grades[4]{ 11,10,8,9};
    int mass[2][2]{ {1,2},{3,4} };
    
    int* pointer{ nullptr };
    //char* ch = new char[15];
    char* ch{ new char[15] {"Hello world"}};
    //Point point{ 10,6 };
    */


}
