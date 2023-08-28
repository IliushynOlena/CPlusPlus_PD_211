#include <iostream>
#include <string>
using namespace std;

int foo()
{
    return 2;
}
int& foo(int& a)
{
    a = 200;
    return a;
}
class A
{
public:
    virtual string getName() 
    { return "A"; }
};
class B final : public A
{
    virtual string getName() override final
    {
        return "B";
    }
    virtual string getSurName()
    {
        return "BB";
    }
};
class C //: public B
{
    //error
  /*  virtual string getName() override
    {
        return "C";
    }*/
    virtual string getSurName()
    {
        return "CC";
    }
};

class FriendClass
{
    //some
};
class SomeClass
{
    //FriendClass f;
    //some code
    friend FriendClass;
};
class MyRectangle;
class Point
{
    int x;
    int y;
public:
    Point() = default;
    Point(int pX, int pY) :x(pX), y(pY) {}
    void SetX(int x)
    {
        this->x = x;
    }
    void SetY(int y)
    {
        this->y = y;
    }
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
    void Show()const
    {
        cout << "X : " << x << " Y : " << y << endl;
    }
    friend MyRectangle;
};
class MyRectangle
{
    Point leftUpCorner;
    Point rightDownCorner;
public:
    MyRectangle() = default;
    MyRectangle(Point leftCorner, int sideA, int sideB) :leftUpCorner(leftCorner)
    {
        //rightDownCorner = Point(leftUpCorner.x + sideA, leftUpCorner.y + sideB);
        rightDownCorner = Point(leftUpCorner.GetX() + sideA, leftUpCorner.GetY() + sideB);
    }
    int getSideA()
    {
        return this->rightDownCorner.x - this->leftUpCorner.x;
    }
    int getSideB()
    {
        return this->rightDownCorner.y - this->leftUpCorner.y;
    }
    void Show()
    {
        leftUpCorner.Show();
        rightDownCorner.Show();
    }

};

class Image
{
public:
    class Pixel
    {
        int r, g, b;
    public:
        Pixel(int r, int g, int b) :r(r), g(g), b(b) {}
        string getInfo()
        {
            cout << "Lenght = " << lenght << endl;
            return "Pixel : r = " + to_string(r) + " g = " + to_string(g) + " b = " 
                + to_string(b) ;
        }
    };
private:
    static const int lenght = 5;
    Pixel pixel[lenght]
    {
        Pixel(0,4,64),
        Pixel(110,43,120),
        Pixel(25,48,225),
        Pixel(18,255,112),
        Pixel(77,22,99)
    };
public:
    void GetImage()
    {
        for (int i = 0; i < lenght; i++)
        {
            cout << pixel[i].getInfo() << endl;
            cout << endl;
        }
    }

};
int A = 10;
int main()
{
    int A = 100;
    cout << A << endl;
    cout << ::A << endl;
    Image::Pixel pixel(255, 255, 255);
    cout << pixel.getInfo() << endl;;
    cout << "---------------------------" << endl;

    Image img;
    img.GetImage();

    //cout<< foo();
    ////foo() = 22;
    //int a = 10;
    //foo(a) = 100;
    //cout << foo(a);

    //int var;
    //var = 4;
    ////4 = var;//error
    ////(var + 1) = 4;//error

    //int a;
    //a = 10;
    //var = a;
    //int b = 2;
    //int c = a + b;


}

