#include <iostream>
using namespace std;

class Square;

class Rectangle
{
private:
    int h;
    int w;
public:
    Rectangle():h(0),w(0){ }
    Rectangle(int value):h(value),w(value){ }
    Rectangle(int h, int w):h(h),w(w){ }
    void Print()const
    {
        cout << "Height : " << h << " ";
        cout << "Width : " << w << endl;
    }
    Rectangle operator+(const Rectangle& other) {}
    //operator typename(){}//1
    //operator typename()const{}//2
    //explicit operator typename()const{}//3
    operator int()
    {
        return h * w;
    }
    operator Square();   
};

class Square
{
private:
    int side;
public:
    Square():side(0){}
    Square(int side):side(side){}
    void Print()const
    {
        cout << "Side : " << side <<" ";
        cout << "Side : " << side << endl;
    }
    explicit operator Rectangle()
    {
        Rectangle rect(side, side+10);
        return rect;
    }
};

Rectangle::operator Square()
{
    return Square(h + w);
}

int main()
{
    int a = 3.33;//implicit standart to stadrart
    int value = 9;
    double valueDob = value;//9.000000000000 standart to stadrart
    Rectangle rect(5, 10);//standart to abstract 
    Square sq(7);//standart to abstract 
    rect.Print();
    sq.Print();

    value = rect;//implicit //abstract to standart   
    cout << "Rect : " << value << endl;

    rect =(Rectangle) sq;//abstract to abstract 
    rect.Print();

    sq = rect;//abstract to abstract 
    sq.Print();



    /*
    cout << "Hello World!\n";

    int a = 3.33;
    
 */
}

