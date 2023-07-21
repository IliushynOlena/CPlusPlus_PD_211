#include <iostream>
using namespace std;

inline void Hello()
{
    cout << "Hello world" << endl;
}

class Human
{
private:
    string name;
    int age;
    int weight;
    static int count_human;
public:
    Human():name(""), age(0),weight(0)
    {
        this->name = "Ivan";
        count_human++;
       /* name = "";
        age = 0;
        weight = 0;*/
    }
    Human(string name):Human()
    {
        this->name = name;
        //age = 0;
        //weight = 0;
    }
    Human(string name, int age):Human(name)
    {
        //this->name = name;
        this->age = age;
        //weight = 0;
    }
    Human(string name, int age, int weight):Human(name, age)
    {
       // this->name = name;
        //this->age = age;
        this->weight = weight;
    }
    static int getCountOfHuman()
    {
        return count_human;
    }
    void Show()const
    {
        //this->name = "Ivan";
        cout << "Name : " << this->name << endl;
        cout << "Age : " << age << endl;
        cout << "Weight : " << weight << endl;
        cout << "Count of human : " << count_human << endl;
    }
    ~Human()
    {
        count_human--;
    }
};

int Human::count_human = 0;
int main()
{
    Human h;
    Human h2("Petro");
    Human h3("Danulo", 15);
    if (true) {
      Human h4("Sergiy", 22, 250);
      h4.Show();

    }

    h.Show();
    h2.Show();
    h3.Show();

    cout << "Count of humans " << h.getCountOfHuman() << endl;
    cout << "Count of humans " << h2.getCountOfHuman() << endl;
    cout << "Count of humans " << h3.getCountOfHuman() << endl;
    cout << "Count of humans " << Human::getCountOfHuman() << endl;
    //Hello();
}
