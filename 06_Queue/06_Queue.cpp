
#include <iostream>
#include<conio.h>
using namespace std;

class Queue
{
    int* arr;
    int size;
    int top;
public:
    Queue() = default;//{}
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        top = 0;
    }
    ~Queue()
    {
        delete[]arr;
    }
    bool IsFull()const
    {
        return top == size;
    }
    bool IsEmpty()const
    {
        return top == 0;
    }
    void Enqueue(int elem)
    {
        if (!IsFull())
            arr[top++] = elem;
    }
    int Peek()const
    {
        if (IsEmpty)return 0;
        return arr[top - 1];
    }
    int Dequeue()
    {
        if (!IsEmpty())
        {
            int first = arr[0];
            for (int i = 0; i <= top; i++)
            {
                arr[i] = arr[i + 1];
            }

            //Default Queue
            //top--;
            //return first;

            //cycle queue
            arr[top - 1] = first;
            return first;
        }
    }
    int GetCount()const
    {
        return top;
    }
    void Clear()
    {
        top = 0;
    }
    void Print()const
    {
        for (int i = 0; i < top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q(25);
    for (int i = 0; i < 10; i++)
    {
        q.Enqueue(i + 1);
    }
    q.Print();
    cout << "Count = " << q.GetCount() << endl;
    cout << "Element = " << q.Dequeue() << endl;
    cout << "Count = " << q.GetCount() << endl;
    q.Print();

    while (!q.IsEmpty())
    {
        cout << "Element = " << q.Dequeue() << endl;
        _getch();
    }

}

