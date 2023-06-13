#include <iostream>
using namespace std;

void Test()
{
    const int size = 5;
    int arr[size];
}
int* CreateArrDynam()
{
    int size = 5;
    int *arr = new int[size];
    return arr;
}
void Fill(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        //*(arr + i) = i + 1;
        arr[i] = rand() % 20;
    }
}
void Show(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        //*(arr + i) = i + 1;
        cout << arr[i] << " ";
    }
}

int main()
{
    Test();
    int size = 5;
    int *arr =  CreateArrDynam();
    Fill(arr, size);
    Show(arr, size);
    delete[]arr;
    /*
    int a = 5;
    cout << a << endl;
    int* pa = &a;
    cout << pa << endl;
    cout << *pa << endl;

    int b = 10;
    int* pb = &b;

    cout << a + b << endl;

    cout << *pa + *pb << endl;

    pa = &b;
    *pa += 2;
    cout << b << endl;
    cout << *pb << endl;
    cout << *pa << endl;

    int* pa = new int;
    *pa = 3;
    int* pb = new int(12);
    cout << *pa << endl;
    cout << *pb << endl;
    delete pa;
    pa = pb;


    delete pa;
    delete pb;
    */
    
}

