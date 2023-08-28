#include <iostream>
#include <fstream>
#include <string>
using namespace std;
template<typename T>
class List
{
private:
    struct Node
    {
        Node* prev;
        T value;
        Node* next;
        Node(Node* prev, T value, Node* next) :prev(prev), value(value), next(next) {}
    };
    Node* head;
    Node* tail;
    int size;
    int data;
public:
    List()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    List(const List& other)
    {
        for (Node* current = other.head; current != nullptr; current = current->next)
        {
            this->AddToTail(current->value);
        }
    }
    void Clear()
    {
        Node* current = head;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    List& operator = (const List& other)
    {
        Clear();
        for (Node* current = other.head; current != nullptr; current = current->next)
        {
            this->AddToTail(current->value);
        }
        return *this;
    }
    bool IsEmpty()
    {
        return head == nullptr;
    }
    void AddToHead(T value)
    {
        Node* newNode = new Node(nullptr, value, head);
        if (IsEmpty()) // âêàçóº àäðåñó newNode, êîëè ìè éîãî ñòâîðèëè äëÿ íüîãî ñòâîðèëàñü àäðåñà ³ ìè öþ àäðåñó âêàçóºìî äëÿ Head ³ Tail
        {
            head = tail = newNode;
        }

        head->prev = newNode;
        head = newNode;
        size++;
        /*newNode->value = value;
        newNode->next = head;*/ //òåæ ä³ºâèé ñïîñ³á, àëå ìè çðîáèëè â ñòðóêòóð³ êîíñòðóêòîð
    }
    void PrintList()const
    {
        //Node* current = head;
        /*cout << current->value << " ";
        current = current->next;    */

        //while (current != nullptr)
        //{
        //    cout << current->value << " ";
        //    current = current->next;
        //}
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
        }
        cout << endl;
    }
    ~List()
    {
        Node* current = head;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    void AddToTail(T value)
    {
        Node* newNode = new Node(tail, value, nullptr);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    T GetElement(int pos)//pos = 3
    {
        if (pos <= size)
        {
            Node* current = head;
            int i = 1;
            while (current != nullptr)
            {
                if (pos == i)
                {
                    return current->value;
                }
                current = current->next;
                i++;
            }
        }
        else
        {
            throw overflow_error("Error position");
        }
    }
    T operator[](int pos)//pos = 3
    {
        if (pos <= size)
        {
            Node* current = head;
            int i = 1;
            while (current != nullptr)
            {
                if (pos == i)
                {
                    return current->value;
                }
                current = current->next;
                i++;
            }
        }
        else
        {
            throw overflow_error("Error position");
        }
    }

    void DeleteFromTail()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        Node* current = head;
        while (current->next->next != nullptr)
        {
            current = current->next;

        }
        delete current->next;
        current->next = nullptr;
    }
    void DeleteAll()
    {
        if (size > 0)
        {
            Node* current = head;
            while (head != nullptr)
            {
                current = head;
                head = head->next;
                delete current;
            }
        }
        else
        {
            throw invalid_argument("Nothing to delete");
        }
    }

    void DeleteFromHead()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;

        }
        Node* current = head->next;
        delete head;
        head = current;
        size--;
    }

    void DeleteTail()
    {
        if (IsEmpty()) return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;

        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        size--;
    }
    int GetLength()
    {
        return size;
    }
    void DeleteFromPostion(int pos)
    {// 1- fing element to delete by position
        if (pos <= size)
        {
            if (pos < 1 || pos > size)
            {
                return;
            }
            else if (pos == 1)
            {
                DeleteFromHead();
            }
            else if (pos == size)
            {
                DeleteFromTail();
            }
            else
            {
                Node* current = nullptr;
                if (pos < size / 2)//start width head
                {
                    current = head;
                    for (size_t i = 1; i < pos; i++)
                    {
                        current = current->next;
                    }
                }
                else
                {
                    current = tail;
                    for (size_t i = size; i > pos; i--)
                    {
                        current = current->prev;
                    }
                }
                current->next->prev = current->prev;
                current->prev->next = current->next;
                delete current;
                size--;
            }
        }
        else
        {
            throw overflow_error("Error position");
        }
    }
    friend ostream& operator <<(ostream& out, const List<int>& list);
    friend istream& operator >>(istream& in, List<int>& list);
    void AddToFile(List<T>& list)
    {
        ofstream outfile("list.txt");
        if (outfile.is_open())
        {
            outfile << list;
            outfile.close();
            cout << "Data is successfully written" << endl;
        }
        else
        {
            cout << "Error!" << endl;
        }
    }
    void ReadFile()
    {
        string read_data;
        ifstream infile("list.txt");
        if (infile.is_open())
        {
            infile.seekg(0, ios::beg);
            getline(infile, read_data);
            infile.close();
            cout << "Data read successfully :: " << read_data << endl;
        }
        else
        {
            cout << "Error data read!" << endl;
        }
    }
};
template <typename T>
ostream& operator <<(ostream& out, const List<T>& list)
{
    for (auto out : list)
    {
        out << list << endl;
    }
    return out;
}
template <typename T>
istream& operator >>(istream& in, List<T>& list)
{
    T a;
    getline(in, a);
    list.AddToTail(a);
    return in;
}
int main()
{
    List<int> list;
    list.AddToHead(12);
    list.AddToTail(13);
    list.AddToTail(14);
    list.AddToTail(15);

    ofstream out("list.txt", ios::out);
    out << list;
    out.close();

    List<int> readList;
    ifstream in("list.txt", ios::in);
    in >> readList;
    readList.PrintList();





    /*List<int> l;
    l.AddToHead(12);
    l.AddToHead(13);
    l.AddToHead(14);
    l.PrintList();
    l.AddToTail(20);
    l.AddToTail(22);
    l.AddToTail(222);
    l.PrintList();
    l.DeleteTail();
    l.PrintList();*/





    /*List<string> l;
    l.PrintList();
    l.AddToTail("100");
    l.AddToTail("Privet");
    l.AddToTail("Hello");
    cout << endl;
    l.PrintList();
    cout << endl;
    cout << "Position element 3 :: " << l.GetElement(3) << endl;
    cout << "Position element 5 :: " << l[5] << endl;
    l.DeleteFromTail();
    l.DeleteFromTail();
    l.PrintList();
    cout << endl;
    l.AddToTail("Hello");
    l.AddToTail("World");
    l.AddToTail("C++");
    l.PrintList();
    cout << endl;
    l.DeleteAll();
    l.PrintList();
    cout << endl;
    l.AddToTail("Deleted");
    l.PrintList();
    cout << endl;
    l.AddToTail("Head");
    l.PrintList();
    cout << endl;
    l.DeleteFromHead();
    l.PrintList();*/



}
