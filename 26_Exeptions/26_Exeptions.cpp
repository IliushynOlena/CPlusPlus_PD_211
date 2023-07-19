#include <iostream>
#include <exception>
using namespace std;

class List
{
private:
	int size;
public:
	List() :size(0) {}
	List(int size) :size(size) {}

	int GetFromPosition(int pos)
	{
		if (size == 0) return 1;
		if (pos < 1 || pos > size) return 2;

		return rand() % 10;//0 1 2 3 4 5 6 7 8 9
	}
};

int Divide(float a, float b)
{
	float res = 0;

	//exception ex("Can't divide by zero!!!! Study math!");
	if (b == 0)
	{
		//cout << " Can't divide by zero!!!! Study math!" << endl;
		throw exception("Can't divide by zero!!!! Study math!");
		//throw ex;//as return 
	}
	if (b == 1)
	{
		throw 404;
	}
	if (b == 5)
	{
		throw "Can't divide by zero!!!!";
	}
	if (b == 10)
	{
		throw 'A';
	}


	res = a / b;
	cout << "Result = [" << res << "]" << endl;
	return res;
}
class PasswordInvalidException : public exception
{
public:
	PasswordInvalidException(const char* message) :exception(message) {}
};
class PasswordSmallException : public exception
{
	int lenght;
public:

	PasswordSmallException(const char* message, int lenght) :lenght(lenght),
		exception(message) {}
	void Message()const
	{
		cout << what() << endl;
		cout << "Actual lenght : " << lenght << endl;
	}
};
void Validation(const char* login, const char* password)
{
	if (strlen(password) < 6)
		throw PasswordSmallException("To small password", strlen(password));
	if (!isalpha(password[0]) || !islower(password[0]))
		throw PasswordInvalidException("Password invalid");;
	if (!isalpha(login[0]) || !isupper(login[0]))
		throw exception("Login invalid");
	cout << "Loading........" << endl;

}

class MyArr
{
private:
	int* arr;
	int size;
public:
	MyArr(int size = 10) :size(size)
	{
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 20;
		}
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~MyArr()
	{
		if (arr != nullptr)
			delete[]arr;
	}
	int operator[](int index)
	{
		if (index < 0 || index >= size)
			throw out_of_range("Index is less that 0 or more than size");
		else
			return arr[index];
	}

	void CheckLenght(int lenght)
	{
		if (lenght < 0)
			throw length_error("Some lenght error");
		else
			cout << " Valid lenght!" << endl;
		//some
	}
	void SetSize(int newSize)
	{
		if (newSize <= 0)
			throw invalid_argument("New size is less than 0");
		else
		{
			int* temp = new int[newSize];
			for (int i = 0; i < newSize && i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete[]arr;
			arr = temp;
			size = newSize;
		}
	}
};
int main()
{
	MyArr arr(5);
	arr.Print();
	
	try
	{
		cout << "Element with index 2 is : " << arr[2] << endl;
		//cout << "Element with index 2 is : " << arr[100] << endl;

		//arr.CheckLenght(-5);
		arr.SetSize(-10);
	}
	catch ( out_of_range & out)
	{
		cout << out.what() << endl;
	}
	catch (invalid_argument& ex)
	{
		cout << "Out of range......" << endl;
		cout << ex.what() << endl;
	}
	catch (logic_error& ex)
	{
		cout << "Logic error......" << endl;
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
	}

	//char login[100];
	//char password[100];
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << "Enter login:";
	//	cin >> login;
	//	cout << "Enter password : ";
	//	cin >> password;

	//	try
	//	{
	//		Validation(login, password);
	//	}		
	//	catch (PasswordInvalidException ex)
	//	{
	//		cout << ex.what() << endl;
	//		cout << "You need create password using A-Z, a-z, 0-9" << endl;
	//	}
	//	catch (PasswordSmallException ex)
	//	{
	//		cout << "Small....do something...." << endl;
	//		ex.Message();
	//		cout << "Lenght must be more than 6 symbols" << endl;
	//	}
	//	catch (exception& ex)
	//	{
	//		cout << "General error " << endl;
	//		cout << ex.what() << endl;
	//	}
	//	
	//	catch (...)
	//	{
	//		cout << "Unknown error" << endl;
	//	}
	//	cout << endl;
	//	cout << endl;
	//	

	//}


	/*float a, b;
	cout << "Enter number a and b : ";
	cin >> a >> b;
	try
	{
		int res = Divide(a, b);
		cout << "Result in main : " << res << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (int ex)
	{
		cout << ex << endl;
		cout << "Error divide by 1" << endl;
	}
	catch (const char * ex)
	{
		cout << ex << endl;
		cout << "Error divide by 5" << endl;
	}
	catch (...)
	{
		cout << "Unknown exception" << endl;
	}
	cout << "Continue......." << endl;
	cout << "Continue......." << endl;
	cout << "Continue......." << endl;
	cout << "Continue......." << endl;*/
}
