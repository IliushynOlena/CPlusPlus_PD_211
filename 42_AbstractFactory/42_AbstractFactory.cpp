
#include <iostream>
using namespace std;

class Toy
{
protected:
    string name;
public:
	Toy(string name) :name(name) {}
    virtual void ShowInfo()const
    {
        cout << "I'm a toy, name : " << name << endl;
    }
};
class Cat : public Toy
{
public:
    Cat(string name) :Toy(name) {}
    virtual void ShowInfo()const override
    {
        cout << "I'm a cat, name : " << name << endl;
    }
};
class Bear : public Toy
{
public:
    Bear(string name) : Toy(name) {}
    virtual void ShowInfo()const override
    {
        cout << "I'm a bear, name : " << name << endl;
    }
};
class TeddyBear : public Bear
{
public:
    TeddyBear() : Bear("TED") {}
    void ShowInfo()const override
    {
        cout << "I'm a teddy bear, name : " << name << endl;
    }
};
class TeddyCat : public Cat
{
public :
    TeddyCat():Cat("TOM"){}
    void ShowInfo()const override
    {
        cout << "I'm a teddy cat, name : " << name << endl;
    }
};
class WoodenBear : public Bear
{
public:
    WoodenBear() :Bear("GRIZLI") {}
    void ShowInfo()const override
    {
        cout << "I'm a wooden bear, name : " << name << endl;
    }
};
class WoodenCat : public Cat
{
public:
    WoodenCat() :Cat("MURKAS") {}
    void ShowInfo()const override
    {
        cout << "I'm a wooden cat, name : " << name << endl;
    }
};

class ToyFactory//abstract
{
public:
    virtual Bear* GetBear() = 0;
    virtual Cat* GetCat() = 0;
};
class TeddyToyFactory : public ToyFactory
{
public:
    Bear* GetBear()override 
    {
        return new TeddyBear();
    }
    Cat* GetCat()override
    {
        return new TeddyCat();
    }
};

class WoodenToyFactory : public ToyFactory
{
public:
    Bear* GetBear()override
    {
        return new WoodenBear();
    }
    Cat* GetCat()override
    {
        return new WoodenCat();
    }
};



int main()
{
    //ToyFactory* factory = new TeddyToyFactory();
    ToyFactory* factory = new WoodenToyFactory();

    Bear * bear = factory->GetBear();
    Cat * cat = factory->GetCat();

    bear->ShowInfo();
    cat->ShowInfo();

    delete factory;
    delete bear;
    delete cat;


}

