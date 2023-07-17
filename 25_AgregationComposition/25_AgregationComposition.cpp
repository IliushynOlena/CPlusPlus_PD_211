#include <iostream>
using namespace std;

class Cartridge
{
public:
    enum Type{None, Standart, XL};
private:
    float volume;
    string color; 
    Type type;
public:
    Cartridge() :volume(0), color("no color"), type(None) {}
    Cartridge(float v, string c, Type t) :volume(v), color(c), type(t) {}
    void ShowInfo()const
    {
        cout << "Volume : " << volume << endl;
        cout << "Color : " << color << endl;
        cout << "Type : " ;
        switch (type)
        {
        case Cartridge::None:cout << "None" << endl;break;
        case Cartridge::Standart:cout << "Standart" << endl;break;
        case Cartridge::XL:cout << "XL" << endl;break;
        }
        cout << endl;
    }    
};
class Scanner
{
private:
    float scanResolution;
    float height, width;
public:
    Scanner() :scanResolution(0), height(0), width(0) {}
    Scanner(float s, float h, float w) :scanResolution(s), height(h), width(w) {}
    void ShowInfo()const
    {
        cout << "Scan Resolution : " << scanResolution << " ppi" << endl;
        cout << "Height : " << height << " mm" << endl;
        cout << "Width : " << width << " mm" << endl;
    }   
};

class Printer
{
private:
    string model;
    Cartridge* cartridges;
    int countCartridges;
    Scanner scanner;

public:
    Printer() :model("no model"), cartridges(nullptr), countCartridges(0) {}
    Printer(string model, float scanRes, float h, float w)
    {
        this->model = model;
        scanner = Scanner(scanRes, h, w);

        countCartridges = 5;
        cartridges = new Cartridge[countCartridges];

        cartridges[0] = Cartridge(100, "Green", Cartridge::Standart);
        cartridges[1] = Cartridge(150, "Blue", Cartridge::Standart);
        cartridges[2] = Cartridge(120, "Red", Cartridge::Standart);
        cartridges[3] = Cartridge(400, "Black", Cartridge::XL);
        cartridges[4] = Cartridge(300, "Yellow", Cartridge::XL);
    }
    void Scan()const
    {
        cout << "Scanning with setting ........" << endl;
        scanner.ShowInfo();
    }
    void PrintDocument()const
    {
        cout << "Printing......with setting" << endl;
        for (int i = 0; i < countCartridges; i++)
        {
            cartridges[i].ShowInfo();
        }
    }
    ~Printer()
    {
        if (cartridges != nullptr)
            delete[]cartridges;
    }
};

int main()
{
    Printer printer("HP", 300, 50, 30);
    printer.Scan();
    printer.PrintDocument();
    
}

