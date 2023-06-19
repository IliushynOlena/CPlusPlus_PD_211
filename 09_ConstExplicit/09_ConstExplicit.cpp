#include <iostream>
using namespace std;

class Date 
{
private:
    const int baseYear;
    int& currentYear;

    int day;   
    int month;
    int year;
public:
    Date(int currentYear) :baseYear(2000), currentYear(currentYear), day(0), month(0), year(0) { }
    Date(int base ,int currentYear) :baseYear(base), currentYear(currentYear), day(0), month(0), year(0) { }
    void setDay(int day)
    {
        this->day = day;
    }
  /*  void setDay(Date* const this, int day)
    {
        this->day = day;
    }*/
  /*  int getDay()
    {
        return day;
    }*/
    int getDay()const
    {
        return this->day;
    }
    void Show()
    {
        cout << "Base Year : " << baseYear << endl;
        cout << "Current Year : " << currentYear << endl;
        cout << "Day : " << day << endl;
        cout << "Month : " << month << endl;
        cout << "Year : " << year << endl;
    }
};

class Account
{
private:
    double sum;//2000
    const double rate;//5
public:
    Account(double Sum ,double Rate): rate(Rate)
    {
        sum = Sum;
        //this->rate = Rate;
    }
    double getRate()const
    {
        return rate;
    }
    double getIncome()
    {
        return sum * rate / 100;
    }
    double getIncome()const
    {
        return sum * rate / 100;//2000*8/100
    }
    double getSum()const
    {
        return sum;
    }
    double setSum()
    {
        sum += getIncome();
        return sum;
    }
};

void doSomething(long number)
{

}
float doSomething()
{
    return 10.3;//double -> float
}
class Array
{
    int size;
    int* arr;
public:
    explicit Array(int size = 10)
    {
        this->size = size;
        arr = new int[size];
       
    }
    explicit Array(const Array& other)
    {
        this->size = other.size;
        this->arr = new int[other.size];
        for (int i = 0; i < other.size; i++)
        {
            arr[i] = other.arr[i];
        }

    }
    ~Array()
    {
        delete[]arr;
    }
    int getSize()const
    {
        return size;
    }
    int getValue(int index)const
    {
        return arr[index];
    }
    void setValue(int index, int value)
    {
        arr[index] = value;
    }
    void Display(int index)const
    {
        cout << arr[index] << " ";
    }
    int operator[](int index) 
    { 
        return arr[index];
    }
    int operator()(int value) 
    {
        for (size_t i = 0; i < size; i++)
        {          
              arr[i] += value;
        }
    }
};

void DisplayArr(const Array& arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.Display(i);
    }
}


int main()
{
    int size = 4;
    Array arr(size);//explicit
    for (int i = 0; i < size; i++)
    {
        arr.setValue(i, size - i - 1);
    }
    DisplayArr(arr);
    cout << endl;
    cout << "!!!" << endl;
    //DisplayArr(3);
    Array arr2(3);
    DisplayArr(arr2);
    cout << endl;
    cout << "----------------------" << endl;
    //Array arr3 = arr;//copy ctor
    Array arr3(arr);//copy ctor
    DisplayArr(arr3);

   

    //implicit
    double a(10);//10.0000000000000 //initialization
    a = 5;//присвоєння
    doSomething(5);//int -> long

    double d = 5.0 / 4;//int -> double 


    /*
    Account account1(2000, 5);
    const Account account2(5000, 8);

    cout << "Rate 1 : " << account1.getRate() << endl;
    cout<< "Rate 2 : "<< account2.getRate() << endl;

    cout<< "Summa 1 : "<< account1.getSum() << endl;
    cout<< "Summa 2 : "<< account2.getSum() << endl;

    cout<< "Income 1 : "<< account1.getIncome() << endl;
    cout<< "Income 2 : "<< account2.getIncome() << endl;

    cout<< "Set summa 1 : "<< account1.setSum() << endl;
    //cout<< "Set summa 2 : "<< account2.setSum();
    */
    /*
    int year;
    cout << "Enter current year : ";
    cin >> year;
    Date date(year, 2023);
    date.Show();
    */
    /*
    Date date;
    date.setDay(10);
    cout << "Date : " << date.getDay() << endl;

   
    const int size = 5;
    const string s{ "first day" };

    const char* str{ "text.txt" };
    const int days[]{ 31,31,28 };
    //days[0] = 30;
    const Date eventDay{ 15, 6, 2023 };
    //eventDay.setDay(25); error
    int day =  eventDay.getDay();
    cout << "Day :" << day << endl;

    Date d{ 1,1,2001 };
     cout<<  d.getDay();
    */
}

