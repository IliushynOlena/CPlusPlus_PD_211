#include <iostream>
#include <string>
using namespace std;
/*
	Для масиву вагонів створити окрему структуру
	з наступними полями :
	struct Vagon
		номер вагону
		кількість місць
		кількість пасажирів
		class Train
		Створити клас Потяг.У класі оголосити поля(змінні члени класу) :
		модель
		кількість вагонів
		вказівник на масив вагонів(динамічний).Vagon* vagon;
	В класі потяг оголосити дефолтний конструктор
	і перезавантажений конструктор.
	Реалізувати метод Show()
	Реалізувати метод додавання вагону до динамічного масиву
	Реалізувати метод - додати 1 пасажира у вагон
	Реалізувати конструктор копіювання
*/
struct Vagon
{
	int number_Vagony;// номер вагону
	int amount_Of_Pasanger_Place;// кількість місць
	int amountPasangers;// кількість пасажирів
	Vagon():number_Vagony(0),amount_Of_Pasanger_Place(0),amountPasangers(0){}
	Vagon(int num, int places)
	{
		number_Vagony = num;
		amount_Of_Pasanger_Place = places;
		amountPasangers = 0;
	}
	void Print()
	{
		cout << "Number : " << number_Vagony << endl;
		cout << "amount_Of_Pasanger_Place : " << amount_Of_Pasanger_Place << endl;
		cout << "amountPasangers : " << amountPasangers << endl;
	}
};

class Train
{
	string model;// модель
	int amount_of_vagons;// кількість вагонів
	Vagon* vagon;// вказівник на масив вагонів
	//Vagon vagon;// вказівник на масив вагонів
public:
	Train()
	{
		model = "no model";
		amount_of_vagons = 0;
		vagon = nullptr;


	}
	Train(string model)// В класі потяг оголосити дефолтний конструктор і перезавантажений конструктор.
	{
		this->model = model;
		this->amount_of_vagons = 0;
		this->vagon = nullptr;
	}
	Train(const Train &other)
	{
		this->model = other.model;
		this->amount_of_vagons = other.amount_of_vagons;
		this->vagon = new Vagon[other.amount_of_vagons];
		for (int i = 0; i < other.amount_of_vagons; i++)
		{
			vagon[i] = other.vagon[i];
		}
	}
	//Train(string model, int amount_of_vagons, Vagon vagon)// і перезавантажений конструктор.
	//{
	//	this->model = model;
	//	this->amount_of_vagons = amount_of_vagons;
	//	this->vagon = nullptr;

	//}
	void Show()//Реалізувати метод Show()
	{
		cout << "Name Train : " << model << endl;
		cout << "Number of wagons : " << amount_of_vagons << endl;
		for (int i = 0; i < amount_of_vagons; i++)
		{
			vagon[i].Print();
			cout << endl;
		}
		//cout << "\nVagon -> " << "\n\tNumber vagony : " << vagon.number_Vagony << "\n\tNumber of seats : " << vagon.amount_Of_Pasanger_Place << "\n\tNumber of passengers : " << vagon.amountPasangers << endl;
	}
	void Add_Vagon(Vagon v);// Реалізувати метод додавання вагону до динамічного масиву	
	void Add_One_Passenger(int number_vagon) 
	{
		//Реалізувати метод - додати 1 пасажира у вагон
		for (int i = 0; i < amount_of_vagons; i++)
		{
			if (vagon[i].number_Vagony == number_vagon)
			{
				vagon[i].amountPasangers++;
			}
		}
	}
	~Train() {
		if (vagon != nullptr) {
			delete[]vagon;
		}
		cout << "Destructor" << endl;
	}
	Train operator+(const Train& other)
	{
		Train result(*this);
		for (int i = 0; i < other.amount_of_vagons; i++)
		{
			result.Add_Vagon(other.vagon[i]);
		}
		return result;
	}
	void operator++()
	{
		for (int i = 0; i < amount_of_vagons; i++)
		{
			vagon[i].amountPasangers++;
		}
	}
	Vagon getVagon(int index)
	{
		if (index < 0 || index >= amount_of_vagons) return Vagon();

		return vagon[index];
	}
	Vagon operator[](int index)
	{
		if (index < 0 || index >= amount_of_vagons)return Vagon();

		return vagon[index];
	}
	void ChangePassangers(int count)
	{
		for (int i = 0; i < amount_of_vagons; i++)
		{
			vagon[i].amountPasangers += count;
		}
	}
	void operator ()(int count)
	{
		for (int i = 0; i < amount_of_vagons; i++)
		{
			vagon[i].amountPasangers += count;
		}
	}
	void operator ()(int count, int number)
	{
		for (int i = 0; i < amount_of_vagons; i++)
		{
			if(vagon[i].number_Vagony == number)
				vagon[i].amountPasangers += count;
		}
	}
	operator string()
	{
		/*string res = "";
		for (int i = 0; i < amount_of_vagons; i++)
		{
			res += to_string(vagon[i].number_Vagony) + " ";
		}
		return res;*/
		return model;
	}

};

void Train::Add_Vagon(Vagon v)// Реалізувати метод додавання вагону до динамічного масиву
{
	amount_of_vagons++;
	Vagon* temp = new Vagon[amount_of_vagons];
	for (size_t i = 0; i < amount_of_vagons - 1; i++)
	{
		temp[i] = vagon[i];
	}
	temp[amount_of_vagons - 1] = v;
	if (vagon != nullptr)
	{
		delete[]vagon;
	}
	vagon = temp;
}
int main()
{
	Train train("Tom");
	train.Show();
	Vagon v{ 1,15 };
	train.Add_Vagon(v);
	train.Add_Vagon(Vagon{2,30});
	train.Add_Vagon(Vagon{ 3,10 });
	train.Add_One_Passenger(1);
	train.Add_One_Passenger(1);
	train.Add_One_Passenger(1);
	train.Add_One_Passenger(1);
	train.Add_One_Passenger(2);
	train.Show();
	cout << "*****************************" << endl;
	Train newTrain = Train(train);
	newTrain.Show();

	cout << "*****************************" << endl;

	Train superTrain = train + newTrain;
	superTrain.Show();
	++superTrain;
	++superTrain;
	++superTrain;
	++superTrain;
	//superTrain.Show();

	superTrain.ChangePassangers(10);
	superTrain(3);
	superTrain(2,3);
	superTrain.Show();

	cout << "-------------------------------" << endl;
	cout << (string)superTrain << endl;
	/*Vagon vagon = superTrain.getVagon(5);
	vagon.Print();
	vagon = superTrain[0];
	vagon.Print();*/
} // виклик деструкторів