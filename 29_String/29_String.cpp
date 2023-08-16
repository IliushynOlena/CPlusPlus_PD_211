#include <iostream>
#include <string>		// library for string
using namespace std;

class Student
{
	string name;
public:
	Student(string name)
	{
		this->name = name;
	}
	void InsertSurname(string surname)
	{
		name += " ";
		name.insert(name.size(), surname);
	}
	Student operator =(string name)
	{
		this->name = name;
		return *this;
	}
	void Print()
	{
		cout << name << endl;
	}

};
int main()
{
	// Using string Constructors
	// —————————————————————————	
	//
	//string name = "Olena";
	//name = "Ivan";
	//Student st = name;
	//st.Print();
	//st.InsertSurname("Iliushyn");
	//st.Print();
	////cout << st;
	//string name = "Olena"; //overloaded =
	//string one = string("Lottery Winner!");		// ctor #1
	//cout << one << endl;						// overloaded <<
	//string two(20, '$');						// ctor #2
	//cout << two << endl;
	//string three(one);							// ctor #3
	//cout << three << endl;
	//one += " Oops!";							// overloaded +=
	//cout << one << endl;
	//two = "Sorry! That was ";
	//three[0] = 'P';								// overloaded []
	//string four;								// ctor #4
	//four = two + three;							// overloaded +, =
	//cout << four << endl;


	//char alls[] = "All's well that ends well";
	//string five(alls, 20);						// ctor #5
	//cout << five << "!\n";
	//string six(alls + 6, alls + 10);			// ctor #6
	//cout << six << ", ";
	//string seven(&five[6], &five[10]);			// ctor #6 again
	//cout << seven << "...\n";
	//string eight(four, 7, 16);					// ctor #7
	//cout << eight << " in motion!" << endl;

	//for (char i : one) // for (auto i = one.begin(); i != one.end(); i++)
	//{
	//	cout << i;
	//}
	//for (auto i = one.begin(); i != one.end(); i++)
	//{
	//	cout << *i << " ";
	//}
	//cout << endl;
	// Using string Functions
	// —————————————————————————

	// Create strings
	const char c_str[] = "Hello";
	string str = "hello, world!";
	string str2 = "world";

	// ----- Capacity -----	

	// Size of allocated storage
	cout << "Capacity: " << str.capacity() << endl;
	// Length of string
	cout << "Size/length: " << str.size() << " = " << str.length() << endl;

	// Clear string
	//str.clear();
	//cout << "Capacity: " << str.capacity() << endl;
	//cout << "Size/length: " << str.size() << " = " << str.length() << endl;

	//Test if string is empty
	if (str.empty())
		cout << "String is empty!" << endl;

	// ----- Element access -----	

	// Get character of string
	str[0] = 'H';//set
	cout << str[0] << endl;//get

	// ----- Modifiers -----	

	// Append to string
	//cout << str << endl;
	//str.append(str.begin() + 3, str.end() - 2);
	//cout << str << endl;
	//str.append(" end.");
	//cout << str << endl;
	//str.append(c_str, 3);
	//cout << str << endl;
	//str.append({ 'g', '5' });
	//cout << str << endl;
	//str += "ferg";
	//cout << str << endl;

	//// Insert into string
	//str.insert(str.begin(), 4, 'H');
	//cout << str << endl;
	//cin.get();

	//str.insert(0, 4, 'O');
	//cout << str << endl;
	//cin.get();

	//str.insert(1, "ello");
	//cout << str << endl;
	//cin.get();

	//str.insert(str.size() - 1, str2);
	//cout << str << endl;
	//cin.get();

	//str.insert(0, c_str);
	//cout << str << endl;
	//cin.get();

	//str.insert(str.end(), { '?', '!' });
	//cout << str << endl;
	//cin.get();

	// Erase characters from string
	/*cin.get();
	cout << str << endl;
	str.erase(1, 3);
	cout << str << endl;
	cin.get();
	str.erase(3);
	cout << str << endl;
	cin.get();
	str.erase();
	cout << str << endl;
	cin.get();*/
	/*cout << str << endl;
	str.erase(str.begin() +4, str.end());
	cout << str << endl;
	cin.get();*/
	// Replace portion of string
	// "yesae ighaeri bla aerhgiuae"
	str.replace(0, 5, "yes");
	cout << str << endl;

	// ----- String operations -----

	// Get C string equivalent
	const char* c_str2 = str.c_str();

	cout << "str: " << str << endl;
	cout << "str2: " << c_str2 << endl;
	// find content in string
	cout << "index of first 'o' = " << str.find('o') << endl;
	cout << "index of first 'o' = " << str.find("hello") << endl;

	if (str.find("hello") == string::npos)
		cout << "not found!" << endl;

	// find last occurrence of content in string
	cout << "index of last 'o' = " << str.rfind('o') << endl;

	// find character in string
	cout << "found index: " << str.find_first_of("abcd") << endl;
	// find character in string from the end
	cout << "found index: " << str.find_last_of("abl") << endl;

	// find absence of character in string
	cout << "found index: " << str.find_first_not_of("hello, world") << endl;
	// find non - matching character in string from the end
	cout << "found index: " << str.find_last_not_of("hello, world") << endl;

	// generate substring
	// "hello, blabla world!"
	cout << "substring: " << str.substr(7, 5) << endl;

	//std::cin.get();
	return 0;
}