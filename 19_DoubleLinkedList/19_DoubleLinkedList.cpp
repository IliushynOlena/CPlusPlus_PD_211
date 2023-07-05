#include <iostream>
using namespace std;

template<class T_data>
class List
{
private:
	struct Node
	{
		Node* prev;
		T_data value;//vagon
		Node* next;
		Node(Node* prev, T_data value, Node* next) :prev(prev), value(value), next(next) {}
	};
	Node* head;
	Node* tail;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}
	List(const List &other)
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
	List& operator =(const List& other)
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
	void AddToHead(T_data value)//5
	{
		Node* newNode = new Node(nullptr, value, head);
		if (IsEmpty())
		{
			head = tail = newNode;
		}

		head->prev = newNode;
		head = newNode;
	}
	void PrintList()const
	{
		//Node* current = head;//int i = 0;

		//while (current != nullptr)//i < 10
		//{
		//	cout << current->value << " ";
		//	current = current->next;//i++
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
	void AddToTail(T_data value)
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
	}
	T_data GetElement(int pos)//pos = 3
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->value;
			current = current->next;
			i++;
		}
	}
	T_data operator[](int pos)//pos = 3
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->value;
			current = current->next;
			i++;
		}
	}
	void DeleteFromTail()
	{
		if (IsEmpty())return;
		if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
			return;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
	}
};

struct Vagon
{
	int number_Vagony;// номер вагону
	int amount_Of_Pasanger_Place;// кількість місць
	int amountPasangers;// кількість пасажирів
	Vagon() :number_Vagony(0), amount_Of_Pasanger_Place(0), amountPasangers(0) {}
	Vagon(int num, int places)
	{
		number_Vagony = num;
		amount_Of_Pasanger_Place = places;
		amountPasangers = 0;
	}
	Vagon(int num, int places, int pass):number_Vagony(num), 
		amount_Of_Pasanger_Place(places), amountPasangers(pass) {}
	void Print()
	{
		cout << "Number : " << number_Vagony << endl;
		cout << "amount_Of_Pasanger_Place : " << amount_Of_Pasanger_Place << endl;
		cout << "amountPasangers : " << amountPasangers << endl;
	}
};
ostream& operator << (ostream& out, const Vagon& other)
{
	out << "Number : " << other.number_Vagony << endl;
	out << "amount_Of_Pasanger_Place : " << other.amount_Of_Pasanger_Place << endl;
	out << "amountPasangers : " << other.amountPasangers << endl;
	return out;
}

class Train
{
	string model;// модель
	int amount_of_vagons;// кількість вагонів
	List<Vagon> vagons;
	//Vagon vagon;// вказівник на масив вагонів
public:
	Train()
	{
		model = "no model";
		amount_of_vagons = 0;
	}
	Train(string model)// В класі потяг оголосити дефолтний конструктор і перезавантажений конструктор.
	{
		this->model = model;
		this->amount_of_vagons = 0;
	}
	Train(const Train& other):vagons(other.vagons)
	{
		this->model = other.model;
		this->amount_of_vagons = other.amount_of_vagons;
		//this->vagons = other.vagons;//vagons - List operator =
	}
	void Show()//Реалізувати метод Show()
	{
		cout << "Name Train : " << model << endl;
		cout << "Number of wagons : " << amount_of_vagons << endl;
		vagons.PrintList();
		cout << endl;
	}
	void Add_VagonToHead(Vagon v)// Реалізувати метод додавання вагону до динамічного масиву
	{
		vagons.AddToHead(v);
		amount_of_vagons++;
	} 
	void AddVagonToTail() {}
	void DeleteVagonFromTail() {}
	void DeleteVagonFromHead() {}

};

int main()
{
	Train train("Tomas");
	train.Add_VagonToHead(Vagon{ 1,15,5 });
	train.Add_VagonToHead(Vagon{ 2,25,3 });
	train.Add_VagonToHead(Vagon{ 3,10,8 });
	train.Add_VagonToHead(Vagon{ 4,15,12 });
	train.Show();

	Train newTrain(train);//
	newTrain.Show();


	newTrain = train;

	/*List l;
	for (int i = 0; i < 10; i++)
	{
		l.AddToHead(i);
	}
	l.PrintList();

	l.AddToTail(100);
	l.AddToTail(200);
	l.AddToTail(300);
	l.AddToTail(400);
	l.AddToTail(500);
	l.PrintList();

	l.DeleteFromTail();
	l.DeleteFromTail();
	l.DeleteFromTail();
	l.DeleteFromTail();
	l.PrintList();*/


	

}

