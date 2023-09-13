#include <iostream>
using namespace std;

class Laptop
{
	string screenResolution;
	string proccessor;
	string memory;
	string hdd;
	string batery;
public:
	void SetSceenResolution(string value) { screenResolution = value; }
	void SetProccessor(string value) { proccessor = value; }
	void SetMemory(string value) { memory = value; }
	void SetHDD(string value) { hdd = value; }
	void SetBatery(string value) { batery = value; }
	void Show()const
	{
		cout << "Screen Resolution : " << screenResolution << endl;
		cout << "Proccessor : " << proccessor << endl;
		cout << "Memory : " << memory << endl;
		cout << "HDD : " << hdd << endl;
		cout << "Batery : " << batery << endl;
	}
};
class LaptopBuilder
{
protected:
	Laptop* laptop;
public:
	void CreateNewLaptop()
	{
		laptop = new Laptop();
	}
	Laptop* GetMyLaptop()
	{
		return laptop;
	}
	/*~LaptopBuilder()
	{
		delete laptop;
	}*/
	virtual void SetMonitorResolution() = 0;
	virtual void SetProccessor() = 0;
	virtual void SetMemory() = 0;
	virtual void SetHDD() = 0;
	virtual void SetBattery() = 0;
};
class GamingBuilder : public LaptopBuilder
{
public:
	void SetMonitorResolution()override {
		laptop->SetSceenResolution("1900x1200");
	}
	void SetProccessor()override
	{
		laptop->SetProccessor("Inter Core I7, 2.9GHz");
	}
	void SetMemory()override {
		laptop->SetMemory("32 Gb");
	}
	void SetHDD()override {
		laptop->SetMemory("1 Tb");
	}
	void SetBattery()override {
		laptop->SetBatery("5000 mAh");
	}
};
class OfficeBuilder : public LaptopBuilder
{
public:
	void SetMonitorResolution()override {
		laptop->SetSceenResolution("1200x900");
	}
	void SetProccessor()override
	{
		laptop->SetProccessor("Inter Core I5, 2.9GHz");
	}
	void SetMemory()override {
		laptop->SetMemory("8 Gb");
	}
	void SetHDD()override {
		laptop->SetMemory("250 Gb");
	}
	void SetBattery()override {
		laptop->SetBatery("2000 mAh");
	}
};
class ProgrammerBuilder : public LaptopBuilder
{
public:
	void SetMonitorResolution()override {
		laptop->SetSceenResolution("1900x1200");
	}
	void SetProccessor()override
	{
		laptop->SetProccessor("Inter Core I9, 2.9GHz");
	}
	void SetMemory()override {
		laptop->SetMemory("32 Gb");
	}
	void SetHDD()override {
		laptop->SetMemory("500 Gb");
	}
	void SetBattery()override {
		laptop->SetBatery("4000 mAh");
	}
};
class LaptopDirector
{
	LaptopBuilder* builder;
public:
	LaptopDirector(LaptopBuilder* builder = nullptr) : builder(builder) {}
	~LaptopDirector()
	{
		delete builder;
	}
	void SetBuilder(LaptopBuilder* builder)
	{
		this->builder = builder;
	}
	Laptop* GetLaptop()const
	{
		return builder->GetMyLaptop();
	}
	void Configurate()
	{
		builder->CreateNewLaptop();
		builder->SetMonitorResolution();
		builder->SetProccessor();
		builder->SetMemory();
		builder->SetHDD();
		builder->SetBattery();
	}
};

int main()
{
	LaptopDirector dir;
	dir.SetBuilder(new GamingBuilder());
	dir.Configurate();
	Laptop * laptop = dir.GetLaptop();
	laptop->Show();

	cout << endl;
	dir.SetBuilder(new ProgrammerBuilder());
	dir.Configurate();
	delete laptop;
	laptop = dir.GetLaptop();
	laptop->Show();


	delete laptop;

   
}

