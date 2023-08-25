#include <iostream>
#include <memory>
using namespace std;

class Animal//abstract class
{
protected:
	float weight;
	string type;
	int speed;
	string name;
	string life_place;
public:
	Animal() :weight(0), type(""), speed(0), name(""), life_place("") {}
	Animal(string name) :weight(0), type(""), speed(0), name(name), life_place("") {}
	Animal(float w, string t, int s, string n, string l) :
		type(t), name(n), life_place(l) 
	{
		//1
		/*if (w < 0)
			this->weight = 0;
		else
			this->weight = w;*/
		//2
		//w > 0 ? this->weight = w : this->weight = 0;
		//3
		this->weight =  (w > 0) ?  w :  0;
		this->speed =  (s > 0) ?  s :  0;
	}
	void Print()const
	{
		cout << "Weight : " << weight << "kg"<< endl;
		cout << "Type : " << type << endl;
		cout << "Speed : " << speed << endl;
		cout << "Name : " << name << endl;
		cout << "Life place : " << life_place << endl;
	}
	virtual void Move()const
	{
		cout << "I am moving......" << endl;
	}
	virtual void MakeSound() const = 0;//pure virtual	
};

class Lion : public Animal
{
	int strenght;
public:
	Lion() : strenght(0), Animal() {}
	Lion(float w, string t, int s, string n, string l, int str) : strenght(str), 
		Animal(w,t,s,n,l) {}
	
	void MakeSound()const override
	{
		cout << "Rrrrr-rrrrrrr-rrrrrrrrrr-rrrrrrrr" << endl;
	}
	void Move()const
	{
		cout << "I am a Lion. A can run with speed " << speed << " km/h" << endl;
	}
};
class Duck: public Animal
{
	float flyHeight;
public:
	Duck() : flyHeight(0), Animal() {}
	Duck(float w, string t, int s, string n, string l, float f) : flyHeight(f), 
		Animal(w,t,s,n,l) {}
	void MakeSound()const override
	{
		cout << "Krya-krya-krya-krya-krya-krya" << endl;
	}	
	void Move()const
	{
		cout << "I am a Duck. A can swimming and flying up to  " << flyHeight << " km" << endl;
	}
};

class Reptile : public Animal // abstract
{
	float swimDeep;
public:
	Reptile() :swimDeep(0), Animal() {}
	Reptile(float w, string t, int s, string n, string l, float swim) :swimDeep(swim), 
		Animal(w,t,s,n,l) {}
	void Move()const
	{
		cout << "I am a Reptile. A can crowling and swimming to deep " << swimDeep << " m" << endl;
	}
};

class Frog : public Reptile
{
	int jumpLenght;
public:
	Frog() :jumpLenght(0), Reptile() {}
	Frog(float w, string t, int s, string n, string l, float swim,int j) :jumpLenght(j),
		Reptile(w,t,s,n,l,swim) {}	
	void MakeSound()const override
	{
		cout << "Kva-kva-kva-kva-kva-kva" << endl;
	}
};

void RollCall(Animal &animal)
{
	animal.MakeSound();
	animal.Move();
	animal.Print();
	cout << "______________________________" << endl;
}

int main()
{
	Frog frog(0.2, "Reptile", 16, "Frog", "Lake", 1, 0.6);

	Lion lion(180,"Predator",74,"King Lion","Africa",45);
	lion.MakeSound();
	lion.Move();
	lion.Print();

	Duck duck(2, "Bird", 160, "Donald MackDack", "Ukraine", 6);
	duck.MakeSound();
	duck.Move();
	duck.Print();
	cout << "---------------------" << endl;
	RollCall(lion);
	RollCall(duck);
	RollCall(frog);

	Animal* zoo[3]
	{
		new Frog(0.2, "Reptile", 16, "Frog", "Lake", 1, 0.6),
		new Lion(180,"Predator",74,"King Lion","Africa",45),
		new Duck(2, "Bird", 160, "Donald MackDack", "Ukraine", 6)
	};
	for (size_t i = 0; i < 3; i++)
	{
		delete zoo[i];
	}


	unique_ptr<Animal> zoo2[3]
	{
		make_unique<Animal>(0.2, "Reptile", 16, "Frog", "Lake", 1, 0.6),
		make_unique<Animal>(180,"Predator",74,"King Lion","Africa",45),
		make_unique<Animal>(2, "Bird", 160, "Donald MackDack", "Ukraine", 6)
	};


	/*Animal animal;
	animal.Print();
	animal.Move();
	animal.MakeSound();*/


}