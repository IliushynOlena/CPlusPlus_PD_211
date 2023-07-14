#include <iostream>
using namespace std;

class Car
{
public:
    void Drive()const
    {
        cout << "I am a car. I can drive!" << endl;
    }
    void Use()const
    {
        cout << "I am a car. I can drive!" << endl;
    }
};
class Airplane
{
public:
    void Fly()const
    {
        cout << "I am a airplane. I can fly!" << endl;
    }
    void Use()const
    {
        cout << "I am a airplane. I can fly!" << endl;
    }
};
class FlyCar : public Car, public Airplane
{

};


class A
{
public:
    int value;
};
class B :public A
{

};
class C :public A
{

};
class D :public B, public C
{
public:
    int getValue()
    {
        return C::value;
    }
};
class Person
{
    string name;
    string surname;
public:
    Person() :name(""), surname("") {}
    Person(string name, string surname) :name(name), surname(surname) {}
    string getName()const
    {
        return name;
    }
    string getSurName()const
    {
        return surname;
    }
    virtual void Show()const
    {
        cout << "Name : " << name << endl;
        cout << "Surname : " << surname << endl;
    }
};
class Gamer
{
    int score;
public:
    Gamer()
    {
        score = 100;
    }
    virtual void Show()const
    {
        cout << "I have score in this game " << score << endl;       
    }
};
class SimpleGamer: public Person , public Gamer
{
public:
    SimpleGamer() :Person("Ivan", "Oliunuk"), Gamer() {}   
    void Show()const
    {
       Person::Show();
       Gamer::Show();
    }
};
class Student : public Person
{
    int mark;
public:
    Student(string name, string surname):Person(name, surname)
    {
        mark = 12;
        cout << getName() << endl;
    }
    void Show()const
    {
        cout << "I have mark by this subject " << mark << endl;
    }
};
class BadStudent:public Student, public Gamer
{
public:
    void Show()
    {
        cout << getName() << endl;
        cout << Person::getName() << endl;
        cout << Student::Person::getName() << endl;
    }

};
int main()
{
    Gamer* g = new SimpleGamer();
    Person * p = new SimpleGamer();
    SimpleGamer s;
    g->Show();
    p->Show();
    s.Show();


    Car c;
    c.Drive();
    Airplane air;
    air.Fly();
    FlyCar flyCar;
    flyCar.Drive();
    flyCar.Fly();
   (( Car)flyCar).Use();
   ((Airplane)flyCar).Use();
    
}

