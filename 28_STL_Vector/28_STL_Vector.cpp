#include <iostream>
#include<vector>
using namespace std;

void Print(vector<int> v)
{
    for (int element : v)
    {
        cout << element << " - ";
    }
    cout << endl;
}

struct Time
{
    short h, m, s;
};

class Train
{
    int number;
    Time departureTime;
    string destination;

    // operator < << >>
};

class Railway
{
    vector<Train> trains;

public:
    // public methods
};

int main()
{
    vector<int> arr;
    cout << "Size : " << arr.size() << endl;
    cout << "Capacity : " << arr.capacity() << endl;
    vector<int> v = {1,2,3,4,5,6,7,8};//

    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;

    vector<int> v2 = { 10,11,12,13,14 };

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " - ";
    }
    cout << endl;   
    Print(v);

    //delete element
    v.erase(v.begin());
    Print(v);

    v.erase(v.begin()+2);
    Print(v);

   //v.erase(v.end()); - error
   // Print(v);

    v.erase(v.begin()+2, v.end()-2);
    Print(v);

    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;

    v.insert(v.begin(), { 22,33,44 });
    Print(v);
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;

    v.insert(v.begin() + 3, 5, 7);
    Print(v);
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;

    v.insert(v.end(), 101);
    Print(v);
    v.insert(v.begin(), v2.begin()+1, v2.end()-1);
    Print(v);

    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;


    v[0] = 999;
    Print(v);
    v.push_back(55);
    v.push_back(77);
    v.push_back(88);
    Print(v);
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    
    v.pop_back();
    v.pop_back();
    Print(v);
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
   /* cout << "Before swap : " << endl;
    Print(v);
    Print(v2);
    v.swap(v2);
    cout << "After swap : " << endl;
    Print(v);
    Print(v2);*/

    cout << "First element : " << v.front() << endl;
    cout << "First element : " << *(v.begin()) << endl;

    v.resize(3);
    v.push_back(55);
    v.push_back(77);
    Print(v);
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;

    v.shrink_to_fit();
    Print(v);
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    v.push_back(55);
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    v.push_back(77);
    v.push_back(77);
    v.push_back(77);
    Print(v);
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;

    for (int i = 0; i < v.size(); i++)
    {
        //999 - 12 - 13 - 55 - 77 - 55 - 10 - 10 - 7 - 7 - 7 - 7 - 77 - 77 - 77 -
        if (v[i] == 7) 
        {
            v.insert(v.begin() + i +1, 10);
            break;
        }
    }
    Print(v);



    
}
