#include <iostream>
using namespace std;

class Document
{
private:
    string name;
    string format;
    int pages;
public:
    Document() :name("no name"), format("no format"), pages(0) {}
    Document(string name, string format, int pages) :name(name), format(format)
    {
        this->pages = pages > 0 ? pages : 0;
    }
    void ShowInfo()const
    {
        cout << "___________Document________" << endl;
        cout << "Name : " << name << endl;
        cout << "Format : " << format << endl;
        cout << "Pages : " << pages << endl;
    }
  
};
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
    const Document* doc;

public:
    Printer() :model("no model"), cartridges(nullptr), countCartridges(0), doc(nullptr) {}
    Printer(string model, float scanRes, float h, float w)
    {
        doc = nullptr;
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
        if (doc == nullptr)
            cout << "No document to print!" << endl;
        else
        {
            cout << "Printing......" << endl;
            doc->ShowInfo();
        }      
    }
    void CartridgeSetting()
    {
        cout << "You have cartridges :" << endl;
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
    void AddDocument(const Document &doc)
    {
        this->doc = &doc;
    }
    void Cancel()
    {
        doc = nullptr;
    }
};
int main()
{
    Document document("Passport", "A5", 7);
    Document document2("C++ for beginners", "A4", 1500);
    Printer printer("HP", 300, 50, 30);
    printer.Scan();
    printer.PrintDocument();

    printer.AddDocument(document);
    printer.PrintDocument(); 

    printer.AddDocument(document2);
    printer.Cancel();
    printer.PrintDocument();
}

