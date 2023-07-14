#include <iostream>
using namespace std;

class Person//abstract
{
	string name;
public:
	Person() :name("") {}
	Person(string name) :name(name) {}
	
	virtual void Print()const
	{
		cout << "\nName : " << name << endl;
		cout << "\n_____________________________" << endl;
	}
	virtual ~Person() = 0 {}
	
};

class Aspirant : public Person
{
	string* subjects;
	int countSubjects;
public:
	Aspirant(string name,initializer_list<string> sub) ://8
		Person(name)
	{
		this->countSubjects = sub.size();
		subjects = new string[countSubjects];
		int i = 0;
		for (string subj : sub)
		{
			subjects[i] = subj;
			i++;
		}
	}
	void Print()const override
	{
		Person::Print();
		cout << "Subject :  ";
		for (int i = 0; i < countSubjects; i++)
		{
			cout << subjects[i] << " ";
		}
	}
	~Aspirant() override
	{
		if (subjects != nullptr)
			delete[]subjects;
	}
};
int main()
{
	srand(time(0));
	/*Student student("Danulo","Programmer");
	student.Print();

	Aspirant aspirant("Daniel", "Designer", { "UI/UX","Main page", "Defense Earth"});
	aspirant.Print();*/
	cout << "\n*******************************" << endl;
	Person* groups[2]{
		//new Person("Danulo"),
		new Aspirant("Daniel", { "UI/UX","Main page", "Defense Earth"}),
		new Aspirant("Olya", { "Audut","Finance"})
	};
	for (int i = 0; i < 2; i++)
	{
		groups[i]->Print();
		delete groups[i];
	}

}