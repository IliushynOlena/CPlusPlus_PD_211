#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <clocale>
using namespace std;

/* Функциональный объект, содержащий два поля :
1. для хранения значения приращения(delta)
2. для текущего значения генерируемого числа(current) */
class ValueGenerator
{
	int start;
	int step;
public:
	/*
	Конструктор класса инициализирует значение приращения и текущее значение.
	Последнее может быть опущено, и тогда оно будет считаться равным 0
	*/
	ValueGenerator(int start = 1, int step = 3) : start(start), step(step) {}
	/*
	Основа функтора — перегруженный оператор вызова функции — прибавляет значение
	приращения
	к текущему генерируемому числу
	*/
	int operator()()//6,2
	{
		int temp = start;
		start += step;
		return temp;
	}
	bool operator()(int num)
	{
		return num % 2 == 0;
	}

};

//предикат
bool IsEven(int num)
{
	return num % 2 == 0;
}

int cur = 0;

int GetRandomValue()
{
	return rand() % 100;
}

void Show(int num)
{
	cout << num << " ";
}

class Student
{
public:
	string name;
	int age;
};
void Show1(Student num)
{
	//cout << num << " ";
}
bool CompareStudentByName(const Student& b1, const Student& b2)
{
	return b1.name < b2.name;
}
class MyClass
{
public:
	int operator ()(int num) { return num; }
};


void main()
{
	MyClass m;
	m(5);
	srand(static_cast<unsigned int>(time(nullptr)));

	list<int> l = { 1, 5, 3, 6, 7, 3,5, 2, 7 };
	vector<int> v = { 5, 3, 8, 9, 4, 4, 7, 1 };
	vector<Student> v1;
	//cout << '\u2664' << endl;
	//v.resize(10);
	//ValueGenerator gen;

	/*void Show(int num)
	{
		cout << num << " ";
	}*/
	Show(5);
	//ValueGenerator gen(6, 2);
	//generate(v.begin(), v.end(), gen);//functor
	//generate(v.begin(), v.end(), ValueGenerator(6, 3));//functor
	//generate(v.begin(), v.end(), GetRandomValue);//delegat	
	cout << Show << endl;
	for_each(v.begin(), v.end(), Show);//delegate
	cout << endl << endl;
	//int arr[] = { 5,9,7,3,4,8,5,2,13,6 };
	//int* last = &arr[10];
	//sort(arr, last);
	/*cout << "Arr : ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}*/

	//sort(v.begin(), v.end());
	//sort(v.end()-1, v.begin());error
	//sort(v1.begin(), v1.end(), [](Student& a, Student& b) { return a.name >  b.name; });
	//sort(v1.begin(), v1.end(), CompareStudentByName);//delegat
	//sort(v.rbegin(), v.rend()); // by descending

	//for_each(v.begin(), v.end(), Show);//delegat
	//for_each(v1.begin(), v1.end(), Show1);//delegat
	//for_each(l.begin(), l.end(), Show);//delegat
	//cout << endl << endl;



	/*int number = 3;
	isEven(number);
	ValueGenerator functor;
	functor(number);*/


	cout << "---------------------" << endl;
	//auto res  = find_if(v.rbegin(), v.rend(), IsEven);//preducat
	//cout << "Found - " << *res << endl;
	//auto res = find_if(v.begin(), v.end(), ValueGenerator());//functor
	//if (res != v.end())
	//	cout << "Found - " << *res << endl;
	//else
	//	cout << "Not found" << endl;


	//random_shuffle(v.begin(), v.end());

	//for_each(v.begin(), v.end(), Show); cout << endl << endl;

	//generate(l.begin(), l.end(), GetRandomValue);//deledate
	//generate(l.begin(), l.end(), ValueGenerator(3));//functor
	//sort(l.begin(), l.end()); // error with sorting list
	//for_each(l.begin(), l.end(), Show); //delegate
	//cout << endl << endl;

	//cout << "\nEven count: " << count_if(l.begin(), l.end(), IsEven) << endl;//preducat
	//for_each(l.begin(), l.end(), Show);
	//cout << endl;
	//replace(l.begin(), l.end(), 7, 3);

	//for_each(l.begin(), l.end(), Show);
	//cout << endl << endl;

	//cout << endl << endl;
	//cout << *(min_element(v.begin(), v.end()));
	system("pause");

}

//1. Немодифицирующие операции :
//■ for_each() — выполняет операции для каждого элемента последовательности;
//■ find() — находит первое вхождение значения в последовательность;
//■ find_if() — находит первое соответствие предикату в последовательности;
//■ count() — подсчитывает количество вхождений значения в последовательность;
//■ count_if() — подсчитывает количество выполнений предиката в последовательности;
//■ search() — находит первое вхождение последовательности как подпоследовательности;
//■ search_n() — находит в последовательности подпоследовательность, состоящую из n 
// повторений и //возвращает её первое вхождение.
//
//Модифицирующие операции :
//■ copy() — копирует последовательность, начиная с первого элемента;
//■ swap() — меняет местами два элемента;
//■ replace() — заменяет элементы с указанным значением;
//■ replace_if() — заменяет элементы при выполнении //предиката;
//■ replace_copy() — копирует последовательность, заменяя элементы с указанным значением;
//■ replace_copy_if() — копирует последовательность, заменяя элементы при выполнении предиката;
//■ fill() — заменяет все элементы данным значением;
//■ remove() — удаляет элементы с данным значением;
//■ remove_if()  — удаляет элементы при выполнении
//предиката;
//■ remove_copy() — копирует последовательность, удаляя
//элементы с указанным значением;
//■ remove_copy_if()  — копирует последовательность,
//удаляя элементы при выполнении предиката;
//■ reverse() — меняет порядок следования элементов на обратный;
//■ random_shuffle()  — перемещает элементы согласно
//случайному равномерному распределению("тасует" последовательность);
//■ transform()  — выполняет заданную операцию над
//каждым элементом последовательности;
//■ unique() — удаляет равные соседние элементы;
//■ unique_copy() — копирует последовательность, удаляя
//равные соседние элементы.
//
//Сортировка:
//■ sort() — сортирует последовательность с хорошей
//средней эффективностью;
//■ partial_sort() — сортирует часть последовательности;
//■ stable_sort() — сортирует последовательность, сохраняя порядок следования равных элементов;
//■ lower_bound() — находит первый элемент, меньший
//чем заданное значение;
//■ upper_bound() — находит первый элемент, больший
//чем заданное значение;
//■ sределяет, есть ли данный элемент
//в отсортированной последовательности;
//■ merge() — сливает две отсортированные последовательности.
//4. Работа с множествами :
//■ includes() — проверка на вхождение;
//■ set_union() — объединение множеств;
//■ set_intersection() — пересечение множеств;
//■ set_difference() — разность множеств.
//5. Минимумы и максимумы :
//■ min() — меньшее из двух;
//■ max() — большее из двух;
//■ min_element() — наименьшее значение в последовательности;
//■ max_element() — наибольшее значение в последовательности.
//6. Перестановки:
//■ next_permutation() — следующая перестановка в лексикографическом порядке;
//■ prev_permutation() — предыдущая перестановка в лексикографическом порядке.