#include <iostream>
using namespace std;

class Abonent
{
	string name;
	string surname;
	string last_name;
	string home_phone;
	string work_phone;
	string mobi_phone;
	string info;
public:
	Abonent():name(""), surname(""), last_name(""),
		home_phone(""), work_phone(""), mobi_phone(""), info(""){}
	Abonent(string n, string s, string l, string h, string w, string m, string i) :name(n),
		surname(s), last_name(l),
		home_phone(h), work_phone(w), mobi_phone(m), info(i) {}
	void Print()
	{
		cout << "Name : " << name << endl;
		cout << "SurName : " << surname << endl;
		cout << "Last name : " << last_name << endl;
		cout << "home_phone : " << home_phone << endl;
		cout << "work_phone : " << work_phone << endl;
		cout << "mobi_phone : " << mobi_phone << endl;
		cout << "info : " << info << endl;
	}
};
class PhoneBook
{
private:
	Abonent* Abonents;
	int count_of_abonent;
public:
	PhoneBook() :Abonents(nullptr), count_of_abonent(0) {}
	void print_Workers()
	{
		for (size_t i = 0; i < count_of_abonent; i++)
		{
			if (count_of_abonent != 0) {
				cout << "Worker of firm : ";
				Abonents[i].Print();
				cout << endl;
			}
			else {
				cout << "U firmi nema pracivnukiv :(";
			}
		}
	}
	void add_workers(Abonent a)
	{
		count_of_abonent++;
		Abonent * temp = new Abonent[count_of_abonent];
		for (size_t i = 0; i < count_of_abonent - 1; i++)
		{
			temp[i] = Abonents[i];
		}
		temp[count_of_abonent - 1] = a;
		if (Abonents != nullptr)
		{
			delete[]Abonents;
		}
		Abonents = temp;
	}

	void delete_workers() {
		if (Abonents != nullptr) {
			delete[]Abonents;
		}
	}
	~PhoneBook()
	{
		delete_workers();
		cout << "Destructor" << endl;
	}
};
int main()
{
	PhoneBook firma;
	firma.add_workers(Abonent("N1", "S1", "L1", "H1", "M1", "W1", "info"));
	firma.add_workers(Abonent("N2", "S1", "L1", "H1", "M1", "W1", "info"));
	firma.add_workers(Abonent("N3", "S1", "L1", "H1", "M1", "W1", "info"));
	firma.add_workers(Abonent("N4", "S1", "L1", "H1", "M1", "W1", "info"));
	int choise = -1;
	while (choise != 0)
	{
		cout << "\n\t1 - Print workers\n\t2 - Add workers\n\t3 - Delete workers\n\t0 - EXIT"; cout << "\nEnter choise:"; cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "1" << endl;
			firma.print_Workers();
			break;
		case 2:
			cout << "2" << endl;
			firma.add_workers(Abonent("N1","S1","L1","H1","M1","W1","info"));
			break;
		case 3:
			cout << "3" << endl;
			break;
		default:
			cout << "Ne ta cufra:(" << endl;
			break;
		}
	}
}
