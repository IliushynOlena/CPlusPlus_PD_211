//Приклад: Принцип роботи зі списками:
//створення, заповнення, сортування,
//вивід списка на екран.
//Принцип роботи з ітераторами.

#include <iostream>
#include <list>
#include <string>
using namespace std;

struct Book
{
	string name;
	string author;
	int pages;
};

//функція порівняння елементів списку
bool comparator(const int& a, const int& b);
bool CompareBookByName(const Book& b1, const Book& b2);
bool CompareBookByAuthor(const Book& b1, const Book& b2);
bool CompareBookByPages(const Book& b1, const Book& b2);

void ShowLists(list<int>& l1, list<int>& l2)
{
	//створюємо ітератор 
	list<int>::iterator i;
	list<int>::iterator iter;
	cout << "list1: ";
	for (iter = l1.begin(); iter != l1.end(); ++iter)
	{
		//виводимо елемент на який вказує ітератор
		cout << *iter << " ";
	}

	cout << endl << "list2: ";
	for (auto iter = l2.begin(); iter != l2.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;
}

void main()
{
	
	
	//створення двох пустих списків
	list<int> list1, list2;
	//заповнення обох списків
	for (int i = 0; i < 6; ++i)
	{
		list1.push_back(i);//AddToTail
		list2.push_front(i);//AddToHead
	}
	//--------- Print Lists ---------------
	ShowLists(list1, list2);
	cin.get();
	//-------------------------------------

	list1.assign({ 1, 2, 3 });	// заповнення списка значеннями (очищаючи перед цим існуючі елементи)
	int& a = ++(list1.front());	// повернення посилання на останній елемент / front()
	a++;
	//--------- Print Lists ---------------
	ShowLists(list1, list2);
	cin.get();
	//-------------------------------------

	list1.erase(list1.begin()); // очищення першого елемента
	ShowLists(list1, list2);
	list1.push_back(2);
	ShowLists(list1, list2);
	list1.remove(2);			// видаленя елементів зі значенням 2
	//--------- Print Lists ---------------
	ShowLists(list1, list2);
	cin.get();
	//-------------------------------------

	list1.insert(list1.begin(), 9);			// вставка елемента на початок
	list1.insert(list1.end(), { 7, 7, 7 });	// вставка колекції елементів вкінець
	list1.insert(list1.end(), 4, 15);		// вставка вкінець 4-ох елементів зі значенням 15
	list<int>::iterator it;
	it = list1.begin();
	it++;
	list1.insert(it, 10);
	//--------- Print Lists ---------------
	ShowLists(list1, list2);
	cin.get();
	//-------------------------------------
	list1.resize(20);	// зміна кількості елементів на 20, нові елементи набудуть значення 1
	//--------- Print Lists ---------------
	ShowLists(list1, list2);
	cin.get();
	//-------------------------------------

	//переміщення елемента(ів) з іншого списка
	list1.splice(list1.end(),
		list2,          //джерело даних
		list2.begin()); //позиція елемента
	//--------- Print Lists ---------------
	ShowLists(list1, list2);
	cin.get();
	//-------------------------------------

	//"перевертаємо" список
	list1.reverse();
	//--------- Print Lists ---------------
	ShowLists(list1, list2);
	cin.get();
	//-------------------------------------

	//сортуємо список
	//list1.sort();
	//list2.sort();

	//list1.sort(comparator);
	//--------- Print Lists ---------------
	ShowLists(list1, list2);
	cin.get();
	//-------------------------------------

	//"зливаємо" два списка, другий до першого
	list1.merge(list2);
	//--------- Print Lists ---------------
	ShowLists(list1, list2);
	cin.get();
	//-------------------------------------

	//видаляємо дубляжі зі списка
	list1.unique();
	//--------- Print Lists ---------------
	ShowLists(list1, list2);
	cin.get();
	//-------------------------------------

	//мереміщаємо значення двох списків
	list1.swap(list2);
	//--------- Print Lists ---------------
	ShowLists(list1, list2);
	cin.get();
	//-------------------------------------

	////////////////////// Predicates
	list<Book> library;//ctor - default
	library.assign( {
		Book { "Night", "Gogol", 786},
		Book{ "Day", "Taras", 344 },
		Book{ "Evening", "Franko", 545 }
		});

	cout << "\t---------Original list: -----------\n";
	for (Book b : library)
	{
		cout << b.name << " " << b.author << " " << b.pages << endl;
	}

	cout << CompareBookByName << endl;
	//library.sort();
	//CompareBookByName(b1, b2);
	library.sort(CompareBookByName);
	cout << "\t---------Sorted by Name: -----------\n";
	for (Book b : library)
	{
		cout << b.name << " " << b.author << " " << b.pages << endl;
	}

	library.sort(CompareBookByAuthor);
	cout << "\t---------Sorted by Author: -----------\n";
	for (Book b : library)
	{
		cout << b.name << " " << b.author << " " << b.pages << endl;
	}

	library.sort(CompareBookByPages);
	cout << "\t---------Sorted by Pages: -----------\n";
	for (Book b : library)
	{
		cout << b.name << " " << b.author << " " << b.pages << endl;
	}
	library.reverse();
	for (Book b : library)
	{
		cout << b.name << " " << b.author << " " << b.pages << endl;
	}

	system("pause");
}

bool CompareBookByName(const Book& b1, const Book& b2)
{
	return b1.name < b2.name;
}
bool CompareBookByAuthor(const Book& b1, const Book& b2)
{
	return b1.author < b2.author;
}
bool CompareBookByPages(const Book& b1, const Book& b2)
{
	return b1.pages < b2.pages;
}

bool comparator(const int& a, const int& b)
{
	return a > b;
}