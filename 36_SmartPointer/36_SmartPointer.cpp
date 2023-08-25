#include <iostream>
#include <memory>
using namespace std;
template<typename T >
class SmartPointer
{
    T* ptr;
public:
	SmartPointer() :ptr(nullptr) {}
	SmartPointer(T *ptr) :ptr(ptr) {}
	~SmartPointer()
	{
		if (ptr != nullptr)
		{
			cout << "Destructor for : " << ptr << endl;
			cout << "Destructor for : " << *ptr << endl;
			delete ptr;
			ptr = nullptr;
		}
	}
	SmartPointer(const SmartPointer* other) = delete;
	
	T* Get()const
	{
		return ptr;
	}
	T operator *()const
	{
		return *ptr;
	}	
};
void FunctionWithEx()
{
	int i = rand() % 2;
	if (i == 0)
		throw exception();	
	cout << "Good" << endl;
}
void SetNumber(int& num)
{
	SmartPointer<int> newNum(new int);
	cin >> *(newNum.Get());
	//int* newNum = new int;// 4b
	//cin >> *newNum;//0

	FunctionWithEx();
	if (*newNum == 0)
	{
		//delete newNum;
		throw exception();//return
	}

	num = *newNum;
	//delete newNum;
}
/////// Function with return smart pointer
unique_ptr<int> make_int(int i)
{
	/*unique_ptr<int> ptr(new int(i));
	return ptr;*/
	return make_unique<int>(i);
}
////// Function with smart pointer in parameters
void ShowValue(unique_ptr<int>& ptr)
{
	cout << "Value: " << *ptr << endl;
}
// Class than generate exception in constructor
class ClassThatThrowException
{
public:
	ClassThatThrowException()
	{
		throw exception();
	}
};
void SomeFunc(unique_ptr<int> ptr, ClassThatThrowException exceptClass)
{
	cout << "Value: " << *ptr << endl;
}


int main()
{
	/*
	srand(time(0));
	int a = 0;
	try
	{
		SetNumber(a);
		cout << "Number : " << a << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	cout << "Number : " << a << endl;
	*/
	// My Smart Pointer Class
	//SmartPointer<int> my_ptr1(new int(4));
	//SmartPointer<int> my_ptr2(my_ptr1.Get());
	//SmartPointer<int> my_ptr(my_ptr1);

	// ---------------------------------------
	/////////////////////////////// unique_ptr
	
	int * memory = new int(9);
	//delete memory;
	//unique_ptr<int> u_ptr = unique_ptr<int>(memory);
	unique_ptr<int> u_ptr = make_unique<int>(9);
	//unique_ptr<int> u_ptr1 = u_ptr;//operator = 
	//unique_ptr<int> u_ptr1(u_ptr);//ctor copy
	int* int_ptr = u_ptr.get();
	cout << *int_ptr << endl;

	//delete int_ptr; // явне видалення адреси
	//u_ptr.reset(); // очистка вказівника

	if ((bool)u_ptr)
		cout << "Has pointer\n";
	else
		cout << "Has not pointer\n";

	//cout << *int_ptr << endl;
	//cout << *u_ptr << endl;

	unique_ptr<int> u_ptr2;// = move(u_ptr);
	u_ptr2 = move(u_ptr);
	//u_ptr2.reset(u_ptr.release());
	//u_ptr2.release();
	//cout << *u_ptr << endl;
	cout << *u_ptr2 << endl;

	// ----------------------------------------
	//////////////////////////////// shared_ptr

	shared_ptr<int> s_ptr1(make_shared<int>(5));	// ctor ptr1
	shared_ptr<int> s_ptr2;						// ctor ptr2

	////shared_ptr<int> a = shared_ptr<int>()

	s_ptr2 = s_ptr1;

	//// перевіряємо чи існує вказівник на адресу в shared_ptr
	if (s_ptr1)
		cout << "Ptr 1: " << *s_ptr1 << endl;
	if (s_ptr2)
		cout << "Ptr 2: " << *s_ptr2 << endl;

	//// перевіряємо чи shared_ptr є єдиним власником своєї адреси
	cout << "s_ptr1 " << (s_ptr1.unique() ? "is unique" : "is not unique") << endl;
	s_ptr2.reset();
	cout << "s_ptr1 " << (s_ptr1.unique() ? "is unique" : "is not unique") << endl;
	s_ptr1.reset();

	// ------------------------------------------------
	////////////////////////////// return from function
	shared_ptr<int> my_maked_ptr = make_shared<int>(10);
	//// make_ptr
	unique_ptr<int> makedPtr = make_unique<int>(5);
	//// pass to function
	ShowValue(makedPtr);

	//// --------------------------------------------------------
	//////////////////// Error example with not use make function
	try
	{
		//SomeFunc(unique_ptr<int>(new int(5)), ClassThatThrowException());
		// Fix error
		//SomeFunc(make_unique<int>(5), ClassThatThrowException());
	}
	catch (...)
	{
		cout << "Error...\n";
	}

	// ------------------------------------------------
	///////////////////////// Error example with delete
	int * ptr = new int(10);
	unique_ptr<int> u_ptr3(ptr);
	//delete ptr;				// error with delete

	system("pause");
	return 0;
	
}

