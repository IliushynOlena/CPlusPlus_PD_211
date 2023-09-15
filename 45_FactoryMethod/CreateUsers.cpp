#include <iostream>
#include <vector>
using namespace std;

enum Warrior_ID { Infantryman_ID = 0, Archer_ID, Horseman_ID };

// Иерархия классов игровых персонажей
class Warrior
{
public:
	virtual void info() = 0;
	virtual ~Warrior() {}
	// Параметризированный статический фабричный метод
	static Warrior* createWarrior(Warrior_ID id);
};

class Infantryman : public Warrior
{
public:
	void info() {
		cout << "Infantryman" << endl;
	}
};

class Archer : public Warrior
{
public:
	void info() {
		cout << "Archer" << endl;
	}
};

class Horseman : public Warrior
{
public:
	void info() {
		cout << "Horseman" << endl;
	}
};


// Реализация параметризированного фабричного метода
Warrior* Warrior::createWarrior(Warrior_ID id)
{
	Warrior* p;
	switch (id)
	{
	case Infantryman_ID:
		p = new Infantryman();
		break;
	case Archer_ID:
		p = new Archer();
		break;
	case Horseman_ID:
		p = new Horseman();
		break;
	default:
		abort();
	}
	return p;
};


// Создание объектов при помощи параметризированного фабричного метода
int main()
{

	int a = 5;
	int b = a;

	vector<Warrior*> v;
	v.push_back(Warrior::createWarrior(Infantryman_ID));
	v.push_back(Warrior::createWarrior(Archer_ID));
	v.push_back(Warrior::createWarrior(Horseman_ID));

	for (int i = 0; i < v.size(); i++)
		v[i]->info();

	system("pause");
}