#include <iostream>
using namespace std;

class Enemy
{
protected:
    string name;
    int health;
    float strength;
    static const int maxHealth = 100;
public:
    Enemy(string name) :name(name), health(maxHealth), strength(0) {}
    Enemy(string n, float s): name(n),health(maxHealth), strength(s){}
    void Print()const
    {
        cout << "Name : " << name << endl;
        cout << "Health : " << health << "%" << endl;
        cout << "Strength : " << strength << endl;
    }
    bool IsAlive()const
    {
        return health > 0;
    }
    void DecreaseHealth(int value)
    {
        if (health - value < 0)
            health = 0;
        else
            health -= value;
    }
};
//Inheritance
//class Child : [spetificator] Parent
class Dragon : public Enemy
{
    float armor;
public:
    Dragon() :armor(0), Enemy("Dragon") {}
    Dragon(float a, float s) :armor(a), Enemy("Dragon",s) {}
    Dragon(string name, float a, float s) :armor(a), Enemy(name,s) {}
   
    void Fight(int damage)
    {
        cout << "Getting " << damage << " damage....." << endl;
        DecreaseHealth(damage - armor);
        cout << "Health after punch " << health << " %" << endl;
    }
    float Attack()
    {
        cout << "Attacking with strength " << strength << endl;
        return strength;
    }
    void Print()
    {
        cout << "------------ Dragon ---------------" << endl;
        Enemy::Print();
        cout << "Armor : " << armor << endl;
    }

};
class NinjaTurtle : public Enemy
{
    float runSpeed;
public:
    NinjaTurtle() :runSpeed(0), Enemy("NinjaTurtle") {}
    NinjaTurtle(string name, float run, float s) :runSpeed(run), Enemy(name, s) {}
    void Run()
    {
        cout << "Running with speed " << runSpeed << " km/h " << endl;
    }
    void Print()
    {
        cout << "------------ NinjaTurtle ---------------" << endl;
        Enemy::Print();
        cout << "Run Speed : " << runSpeed << " km/h " << endl;
    }
};
int main()
{
    Dragon boss("Veldora",5,7);
    Dragon dragon("Viverna",4,6);
    boss.Print();
    dragon.Print();
    int i = 1;
    do
    {
        cout << " -------- Round " << i << " ------------" << endl;
        boss.Fight(dragon.Attack());
        dragon.Fight(boss.Attack());

        boss.Print();
        dragon.Print();
        i++;
    } while (boss.IsAlive() && dragon.IsAlive());

    NinjaTurtle turtle("Raff", 120, 6);
    turtle.Run();
    turtle.Print();
   
}

