#include <iostream>
using namespace std;
/*
int GetMax(int* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
long GetMax(long* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
short GetMax(short* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
*/
template<typename T_arr>
T_arr GetMax(T_arr* arr, int size)
{
	T_arr max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
template<typename T_coord>
class Point
{
private:
	T_coord x;
	T_coord y;
public:
	Point()
	{
		x = y = 0;
	}
	Point(T_coord value)
	{
		x = y = value;
	}
	Point(T_coord x, T_coord y)
	{
		this->x = x;
		this->y = y;
	}
	void SetCoords(T_coord x, T_coord y)
	{
		this->x = x;
		this->y = y;
	}
	void Print()const
	{
		cout << "X : " << x << " Y: " << y << endl;
	}
};
template<typename T_X, typename T_Y>
class NewPoint
{
private:
	T_X x;
	T_Y y;
public:
	NewPoint()
	{
		x = y = 0;
	}
	NewPoint(T_X value)
	{
		x = y = value;
	}
	NewPoint(T_X x, T_Y y)
	{
		this->x = x;
		this->y = y;
	}
	void SetCoords(T_X x, T_Y y)
	{
		this->x = x;
		this->y = y;
	}
	void Print()const
	{
		cout << "X : " << x << " Y: " << y << endl;
	}
};
template<class T_coll, class T_value>
class MyClass
{
private:
	int size;
	T_coll* collection;
	T_value point;
public:
	MyClass()
	{
		size = 0;
		collection = nullptr;
		//point = 0;
	}
	MyClass(T_coll*coll, T_value value):collection(coll),point(value){}
	~MyClass()
	{
		if (collection != nullptr)
			delete[]collection;
	}
	void SetCollection(T_coll* coll);

	void SetValue(T_value value)
	{
		point = value;
	}
	void Print()const;

};
template<class T_coll, class T_value>
void MyClass<T_coll, T_value>::Print()const
{
	cout << "Collection : " << collection << endl;
	cout << "Point : " << point << endl;
}
template<class T_coll, class T_value>
void MyClass<T_coll, T_value>::SetCollection(T_coll* coll)
{
	collection = coll;
}

class Array
{
	int* arr;
	int size;
public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	explicit Array(int size )
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	Array(const initializer_list<int>& list)
	{
		this->size = list.size();
		arr = new int[size];
		/*for (int i = 0; i < size; i++)
		{
			arr[i] = list[i];
		}*/
		int i = 0;
		for (int element : list)
		{
			arr[i++] = element;
		}

	}
	void Fill(const initializer_list<int>& list)
	{
		if (arr !=nullptr) delete[]arr;
		this->size = list.size();
		arr = new int[size];
		int i = 0;
		for (int element : list)
		{
			arr[i++] = element;
		}
	}
	void Print()
	{
		cout << "Array size : " << size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int static_arr[5] = { 1,2,3,4,5 };
	int* dynam_arr = new int[5] {5, 6, 7, 8, 9};

	Array arr;//default c-tor;
	arr.Print();

	Array arr2(7);//parametrized c-tor
	//Array arr2 = 7;//
	arr2.Print();
	Array arr3({ 1,2,3,4,5,6,70,88,9,10,11,12,13,14,15 ,14,47,45,25,89});//parametrized c-tor
	arr3.Print();
	arr3.Fill({ 99,98,97,96,95,94 });
	arr3.Print();


	delete[]dynam_arr;

	/*
	Point<int> p(11, 15);
	p.Print();

	p.SetCoords(100, 110);
	p.Print();


	Point<float> p2(3, 3.33);
	p2.Print();
	p2.SetCoords(0.325, 0.145);
	p2.Print();

	NewPoint<int,float> p3(11, 15.15465);
	p3.Print();

	p3.SetCoords(100, 110);
	p3.Print();


	NewPoint<float, double> p4(3.3, 3.36549864643);
	p4.Print();
	p4.SetCoords(0.325, 0.145);
	p4.Print();
	*/

	//long* arr_long = new long[4];
	//for (int i = 0; i < 4; i++)
	//{
	//	arr_long[i] = i + 1;
	//	cout << arr_long[i] << " ";
	//}
	//cout << endl;

	//char* char_arr = new char[4];
	//for (int i = 0; i < 4; i++)
	//{
	//	char_arr[i] = 'a' + i;
	//	cout << char_arr[i] << " ";
	//}
	//cout << endl;

	//MyClass<long, string> cl1(arr_long, "Class with long collection");
	//MyClass<char, string> cl2(char_arr, "Class with char collection");
	//cl1.Print();
	//cl2.Print();
	////delete[]arr_long;
	//delete[]char_arr;
	/*const int size = 10;
	int numbers1[size] = { 5,7,8,15,14,33,9,72,4,8 };
	cout << "Int Max : " << GetMax(numbers1, size) << endl;
	double numbers2[size] = { 5,7.33,8,15,14.33,33,9,72.05,4,8 };
	cout << "Double Max : " << GetMax(numbers2, size) << endl;
	float numbers3[size] = { 5,7,8,15,14,33,9,72.77,4,8 };
	cout << "Float Max : " << GetMax(numbers3, size) << endl;
	short numbers4[size] = { 5,7,8,15,14,33,9,72,4,8 };
	cout << "short Max : " << GetMax(numbers4, size) << endl;
	string colors[5] = { "red", "green", "blue", "yellow","cyan" };
	cout << "colors Max : " << GetMax(colors, 5) << endl;*/


}

