#include <iostream>
#include <map>
using namespace std;

map<string, int>::iterator FindByValue(map<string, int>& m, int value)
{
	for (map<string, int>::iterator i = m.begin(); i != m.end(); i++)
	{
		if (i->second == value)return i;
	}
	return m.end();
}

struct ID
{
	int id;
	string name;

	ID() {}
	ID(int id, string name) : id(id), name(name){}

	void Show() const
	{
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
	}
	bool operator < (const ID& other)const
	{
		return this->name < other.name;
	}

};

int main()
{
	map<ID, int> newMap;

	ID first(1, "Taras");
	pair<ID, int> pair2(first, 78);

	newMap.insert(pair2);
	newMap.insert(make_pair(ID(2,"Anna"),97));
	newMap.insert(make_pair(ID(3,"Hanna"),88));
	for (auto i : newMap)
	{
		i.first.Show();
		cout << "Value : " << i.second << endl;
		cout << "___________________________" << endl;
	}
	cout << "******************************" << endl;
	newMap[ID(7, "Anna")] = 40;
	cout << "Anna : " << newMap[ID(7, "Anna")] << endl;

	for (auto i: newMap)
	{
		i.first.Show();
		cout << "Value : " << i.second << endl;
		cout << "___________________________" << endl;
	}
	/*





	map<string, int> m;
	pair<string, int> newpair("Vasia", 33);
	m.insert(newpair);

	m.insert(pair<string, int>("Ivan", 7));
	m.insert(make_pair("Olga", 4));

	for (auto i : m)
	{
		cout << "Key : "<<  i.first << "  Value : "<< i.second << endl;
	}
	cout << "------------------------------------------" << endl;
	auto res = m.insert(make_pair("Olga", 12));
	pair<map<string,int>::iterator, bool> res2= m.insert(make_pair("Petro", 2));
	pair<map<string,int>::iterator, bool> res3= m.insert(make_pair("Aron", 5));
	pair<map<string,int>::iterator, bool> res4= m.insert(make_pair("Aaron", 7));

	if (res.second)
	{
		cout << "Olga, 12 - was added to map" << endl;
	}
	else
	{
		cout << "Olga, 12 - was not added to map" << endl;
	}
	if (res2.second)
	{
		cout << "Petro, 2 - was added to map" << endl;
	}
	else
	{
		cout << "Petro, 2 - was not added to map" << endl;
	}

	for (auto i : m)
	{
		cout << "Key : " << i.first << "  Value : " << i.second << endl;
	}

	cout << "Value : " << m["Olga"] << endl;
	cout << "Value : " << m["Petro"] << endl;
	//cout << "Value : " << m["Mukola"] << endl;

	map<string,int>::iterator it =  m.find("Olga");
	if (it == m.end())
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "Found !!!"<< endl;
		cout << "Key : " << it->first << "  Value : " << it->second << endl;
		//it->first = "Ira";//Error
		it->second = 150;
		cout << "Key : " << it->first << "  Value : " << it->second << endl;
	}

	it = FindByValue(m, 150);

	if(it != m.end())
		cout << "Find Key : " << it->first << "  Value : " << it->second << endl;

	if (it != m.end())
		m.erase(it);
	cout << "------------------------------------------" << endl;

	for (auto i : m)
	{
		cout << "Key : " << i.first << "  Value : " << i.second << endl;
	}

	m["Mukola"] = 100500;
	m["Aron"] = 55;
	cout << "------------------------------------------" << endl;

	for (auto i : m)
	{
		cout << "Key : " << i.first << "  Value : " << i.second << endl;
	}
	*/


   
}