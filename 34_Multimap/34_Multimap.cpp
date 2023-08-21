
#include <iostream>
#include<algorithm>
#include <map> //map,multimap -- 
#include <string> 
using namespace std;


template<class container>
void show(container col)
{
	for (auto i = col.begin(); i != col.end(); ++i)
	{
		cout << i->first << '\t' << i->second << endl;
	}
	cout << endl << endl;
}

class Student
{
	string name;
	int age;
	string surname;
	int mark;
	string address;
	int number;

public:
	Student()
	{
		name = "";
		age = 0;
	}
	Student(string name, int age) : name(name), age(age) {}

	void Show() const
	{
		cout << "Name: " << name << "\nAge: " << age << "\n";
	}

	bool operator < (const Student& other) const
	{
		return this->name < other.name;
	}
	friend ostream& operator << (ostream& out, const Student& s);
};
ostream& operator << (ostream& out, const Student& s)
{
	out << "Name: " << s.name << "\nAge: " << s.age << "\n";
	return out;
}


void main()
{
	cout << "map\n\n";
	//Создаем пустой контейнер (отображение) 
	map<string, int> cont;
	//Создаем пустой контейнер (мультиотображение) 
	multimap<string, int> multicont;

	multimap<Student, int> group;

	group.insert(make_pair(Student("Bob", 19), 12));

	multimap<Student, int>::iterator iter1 = group.find(Student("Bob", 19));
	cout << "Key : " << iter1->first << "Value : " << iter1->second << endl;
	show(group);
	//добавляем две пары в отображение 
	cont.insert(pair<string, int>("Ivanov", 10));
	cont.insert(pair<string, int>("Petrov", 20));
	cont.insert(pair<string, int>("Ivanov", 10));
	cont.insert(pair<string, int>("Petrov", 20));
	cont.insert(pair<string, int>("Ivanov", 10));
	cont.insert(pair<string, int>("Petrov", 20));
	//добавится пара "Sidorov, 30" 
	cont["Sidorov"] = 30;
	show(cont);
	//заменится значение в паре с ключем "Ivanov" 
	cont["Ivanov"] = 50;
	show(cont);

	//Элемент не добавится, т.к. пара
	//с ключем "Ivanov" уже существует 
	pair<map<string, int>::iterator, bool> res = cont.insert(pair<string, int>("Ivanov", 100));
	if (!res.second)
		cout << "Is already exists!\n";

	show(cont);

	///////////////////////////////////////////////// 
	cout << "------------------------\nmultimap\n\n";
	multicont.insert(pair<string, int>("Ivanov", 10));
	multicont.insert(pair<string, int>("Petrov", 20));
	multicont.insert(pair<string, int>("Sidorov", 20));
	multicont.insert(pair<string, int>("Ivanov", 10));
	multicont.insert(pair<string, int>("Petrov", 20));
	multicont.insert(pair<string, int>("Sidorov", 20));
	multicont.insert(pair<string, int>("Ivanov", 10));
	multicont.insert(pair<string, int>("Petrov", 20));
	multicont.insert(pair<string, int>("Sidorov", 20));
	//Для мульти отображения не определен оператор "[]" 
	//multicont["Sidorov"] = 30; //Error
	show(multicont);
	//Добавляем пару ("Ivanov",100)
	multicont.insert(pair<string, int>("Ivanov", 100));
	show(multicont);
	//Ишем первое вхождение элемента с ключем "Petrov" 
	multimap<string, int>::iterator iter = multicont.find("Petrov");
	cout << iter->first << '\t' << iter->second << endl << endl;
	cout << "Count of key \"Ivanov\" in multimap = " << multicont.count("Ivanov") << endl;
	//возвращает итератор, указывающий на первое включение 
	//данного ключа или на конец отображения
	//в случае отсутствия
	iter = multicont.lower_bound("Ivanov");
	for (; iter != multicont.upper_bound("Ivanov") && iter != multicont.end(); iter++)
	{
		cout << iter->first << '\t' << iter->second << endl;
	}
	cout << endl << endl;

	system("pause");
}