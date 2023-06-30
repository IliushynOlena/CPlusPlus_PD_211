#include <iostream>
using namespace std;

//class Stack
//{
//    enum { EMPTY = -1, FULL = 9 };
//    int data[FULL + 1];
//    int topIndex;
//public:
//  
//    Stack()
//    {
//        topIndex = EMPTY;
//    }
//    ~Stack() = default;//empty
//    Stack(const Stack& other) = delete;
//    bool IsFull()const
//    {
//       return topIndex == FULL;
//    }
//    bool Push(int elem)
//    {
//        if (!IsFull())
//        {
//            data[++topIndex] = elem;
//
//            return true;
//        }
//        return false;
//    }
//    bool IsEmpty()const
//    {
//        return topIndex == EMPTY;
//    }
//    int Pop() 
//    {
//        if (!IsEmpty())
//            return data[topIndex--];    
//    }
//    int GetCount()const
//    {
//        return topIndex+1;
//    }
//    void Clear()
//    {
//        topIndex = EMPTY;
//    }
//    int Peek()const
//    {
//        if (!IsEmpty())
//            return data[topIndex];
//    }   
//};

class Stack
{
private:
    enum{ EMPTY = -1};
    int size;
    int* arr;
    int top;
public:
    Stack() =  delete;//delete = do not allow to create a default c-tor  //default = {}
    Stack(int size):size(size)
    {
        arr = new int[size];
        top = EMPTY;
    }
    bool IsFull()const
    {
        return top == size - 1;//9 == 10-1
    }
    bool Push(int value)
    {
        if (!IsFull())
        {
            arr[++top] = value;
            return true;
        }
        return false;
    }
    bool IsEmpty()const
    {
        return top == EMPTY;
    }
    int Pop()
    {
        if (!IsEmpty())
            return arr[top--];
    }
    int GetCount()const
    {
        return top + 1;
    }
    int Peek()const
    {
        if (!IsEmpty())
            return arr[top];
    }
    void Clear()
    {
        top = EMPTY;
    }
    void Print()const
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Stack()
    {
        delete[]arr;
    }
};

bool IsValidCode(string code)
{
    Stack stack(20);
    for (char symbol : code)
    {
        if (symbol == '{')
        {
            stack.Push(1);
        }
        if (symbol == '}')
        {
            if (stack.IsEmpty()) return false;
            stack.Pop();
        }
    }
    return stack.IsEmpty();
}

int main()
{


    string code = "class Stack{{{ void Print(){ for(){if()}} Stack(){}};";
    if (IsValidCode(code))
        cout << "Valid code" << endl;
    else 
        cout << "InValid code" << endl;



    Stack st(15);
    st.Push(1);
    st.Push(7);
    st.Push(55);
    st.Push(35);
    st.Push(15);
    cout << "Count : " << st.GetCount() << endl;
    cout << "Element : " << st.Pop() << endl;
    cout << "Count : " << st.GetCount() << endl;
    cout << "---------------------------" << endl;
    while (!st.IsEmpty())
    {
        cout << "Element : " << st.Pop() << endl;
    }
    

    /*
    Stack st;
    st.Push(56);
    cout << "Count : " << st.GetCount() << endl;
    st.Push(115);
    st.Push(18);
    st.Push(55);
    st.Push(64);
    cout << "Count : " << st.GetCount() << endl;
    cout << "Element : " << st.Pop() << endl;
    cout << "Count : " << st.GetCount() << endl;

    cout << "---------------------------" << endl;
    while (!st.IsEmpty())
    {
        cout << "Element : " << st.Pop() << endl;        
    }
    */
}

