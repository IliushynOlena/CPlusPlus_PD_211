#include <iostream>
using namespace std;

template<typename T>
class Queue
{
public:
	struct Element
	{
		T value;
		int priority;
	};
private:
	Element* arr;
	int size;
public:
	Queue() :arr(nullptr), size(0) {}
	~Queue()
	{
		if (arr != nullptr)
			delete[]arr;
	}
	void Enqueue(T value, int priority)
	{
		int index = 0;
		while (index < size && arr[index].priority < priority)
		{
			index++;
		}
		size++;
		Element* temp = new Element[size];
		for (int i = 0; i < index; i++)
		{
			temp[i] = arr[i];
		}
		temp[index] = Element{value, priority};
		for (int i = index; i < size-1; i++)
		{
			temp[i + 1] = arr[i];
		}
		if (arr != nullptr)
			delete[]arr;

		arr = temp;
	}
	bool IsEmpty()const
	{
		return size == 0;
	}
	Element Dequeue()
	{
		if (!IsEmpty())
		{
			Element first = arr[0];

			for (int i = 0; i < size - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			size--;
			return first;
		}
		return Element();
	}
	void Print()
	{
		cout << "- - - - - - Queue - - - - - -" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "Value : " << arr[i].value << " . Priority : " << arr[i].priority << endl;
		}
		cout << endl;
		cout << "------------------------------------" << endl;
	}

};
int main()
{
	Queue<string> q;
	q.Enqueue("A", 1);
	q.Enqueue("N",12);
	q.Enqueue("C",3);
	q.Enqueue("B",2);
	q.Enqueue("K",8);
	q.Enqueue("G",5);
	q.Print();
	cout << "--------------------------------" << endl;
	q.Enqueue("D",4);
	q.Print();

	while (!q.IsEmpty())
	{
		cout << "Element : " << q.Dequeue().value << endl;
	}

   
}
