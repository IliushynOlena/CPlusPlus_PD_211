#include <iostream>
#include <Windows.h>
using namespace std;

class Car
{
protected:
	string model;
	float volume;
	int year;
	int mileage;
	int max_speed;
public:
	Car() :model("no model"), volume(0), year(0), mileage(0), max_speed(0) {}
	Car(string m,float v, int y, int mil) :model(m), 
		volume(v), year(y), mileage(mil), max_speed(0) {}
	void setSpeed(int speed)
	{
		if (speed >= 0)
			this->max_speed = speed;
	}
	virtual void Drive()const
	{
		cout << "I am a Car! I can drive with speed " << max_speed << " km/h" << endl;
	}
	void Print()const
	{
		cout << "---------- Car --------------" << endl;
		cout << "Model : " << model << endl;
		cout << "Volume : " << volume << endl;
		cout << "Year : " << year << endl;
		cout << "Mileage : " << mileage << endl;
		cout << "Max_speed : " << max_speed << endl;
	}

};
class PoliceCar : public Car
{
	int soundVolume;
public:
	PoliceCar() :soundVolume(0), Car() {}
	PoliceCar(string m, float v, int y, int mil, int sound) :soundVolume(sound), Car(m,v,y,mil) {}
	void Drive()const override
	{
		cout << "I am a Police Car! I can drive with speed " << max_speed << " km/h" << endl;
	}
	void Print()const
	{
		cout << "---------- Police  Car --------------" << endl;
		Car::Print();
		cout << "Sound Volume : " << soundVolume << endl;
	}
	void BeepBeep()
	{
		Beep(659.26, 200);
		Beep(659.26, 200);
		Sleep(200);
		Beep(659.26, 200);
		Sleep(100);
		Beep(523.26, 200);
		Beep(659.26, 200);
		Sleep(200);
		Beep(783.98, 200);
		Sleep(400);
		Beep(391.99, 200);
	}
};
class SportCar : public Car
{
	int turbo;
public:
	SportCar() :turbo(0), Car() {}
	SportCar(string m, float v, int y, int mil, int t) :turbo(t), Car(m, v, y, mil) {}
	void Drive()const override
	{
		cout << "I am a Sport Car! I can drive with speed " << max_speed << " km/h" << endl;
	}
	void Print()const
	{
		cout << "---------- Sport  Car --------------" << endl;
		Car::Print();
		cout << "Turbo speed : " << turbo << endl;
	}
	void Turbo()
	{
		cout << "Let's go!!!!! I can drive very fast)))))" << endl;
		max_speed += turbo;
		cout << "-----------------> " << max_speed << endl;
	}
	
};

void TestDrive(Car &car)
{
	car.setSpeed(60);
	car.Drive();
}
int main()
{
	Car simpleCar("Lada2110", 5.0, 1999, 20000000);
	simpleCar.setSpeed(300);
	simpleCar.Drive();
	simpleCar.Print();

	PoliceCar police("Duster",2.5,2005,3000,500);
	police.setSpeed(150);
	police.Drive();
	police.Print();
	//police.BeepBeep();

	SportCar sportcar("Ferrari", 8.0, 2022, 300, 50);
	sportcar.setSpeed(340);
	cout << "---------------- Test Drive --------------" << endl;
	TestDrive(simpleCar);
	TestDrive(police);
	TestDrive(sportcar);


}
