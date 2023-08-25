#include <iostream>
#include <list>
#include <fstream>
using namespace std;
class AccountingOfApplications       //Написати програму обліку заявок на авіаквитки. Кожна заявка містить:
{
    string Destination_Point;        //•	пункт призначення
    int Flight_Number;               //•	номер рейса
    string ThePassengers_Initials;   //•	прізвище та ініціали пасажира
    string Desired_Date_of_departure;//•	бажану дату вильоту
public:
    AccountingOfApplications() :Destination_Point(""), Flight_Number(0), ThePassengers_Initials(""), Desired_Date_of_departure("") {}
    AccountingOfApplications(string D, int F, string T, string d) :Destination_Point(D), Flight_Number(F), ThePassengers_Initials(T), Desired_Date_of_departure(d) {}
    string GetDate()const
    {
        return Desired_Date_of_departure;
    }
    string GetPAss()const
    {
        return ThePassengers_Initials;
    }
    string GetDestination()const
    {
        return Destination_Point;
    }
    int GetNumber()const
    {
        return Flight_Number;
    }
    void Print()
    {
        cout << "\n\n\t--------------- info ----------------\n";
        cout << "\tDestination point : " << Destination_Point << endl;
        cout << "\tFlight number : " << Flight_Number << endl;
        cout << "\tThePassengers initials : " << ThePassengers_Initials << endl;
        cout << "\tDesired date of departure : " << Desired_Date_of_departure << endl;
    }
    friend  istream& operator >> (istream& in, AccountingOfApplications& other);
};
istream& operator >> (istream& in, AccountingOfApplications& other)
{
    in >> other.Destination_Point >> other.Flight_Number >> other.ThePassengers_Initials
        >> other.Desired_Date_of_departure;
    return in;
}
class List
{
    list<AccountingOfApplications>l;
public:
    void AddToList(AccountingOfApplications a)// • додавання заявок у список;
    {
        l.push_front(a);
    }

    void DeleteByNumber(int Flight_Number)// • видалення заявок певного пасажира або за номером рейса;
    {
        list<AccountingOfApplications>::iterator iter;
        cout << "list1: ";
        for (iter = l.begin(); iter != l.end(); ++iter)
        {
            //виводимо елемент на який вказує ітератор
            if ((*iter).GetNumber() == Flight_Number)
            {
                l.erase(iter);
                break;
            }
        }
    }
    void PrintByNumber(int Flight_Number)// • показ заявок за заданим номером рейса або датою вильоту;
    {
        list<AccountingOfApplications>::iterator iter;
        cout << "list1: ";
        for (iter = l.begin(); iter != l.end(); ++iter)
        {
            //виводимо елемент на який вказує ітератор
            if ((*iter).GetNumber() == Flight_Number)
                (*iter).Print();
            //cout << *iter << endl;//ostream << 
        }
    }
    void ShowInfo()// • виведення усіх заявок
    {
        list<AccountingOfApplications>::iterator iter;
        for (iter = l.begin(); iter != l.end(); ++iter)
        {
            (*iter).Print();
            //cout << *iter<< " ";//ostream << 
        }
    }
    void sortRequestsByDate()
    {
        l.sort([](const AccountingOfApplications& a, const AccountingOfApplications& b) 
            { return a.GetDate() < b.GetDate(); });
        //l.sort(CompareByDate);
    }
   /* bool CompareByDate(const AccountingOfApplications& a, const AccountingOfApplications& b)
    { return a.GetDate() < b.GetDate(); }*/
   
    void sortRequestsByDestination()
    {
        l.sort([](const AccountingOfApplications& a, const AccountingOfApplications& b) 
            {return a.GetDestination() < b.GetDestination(); });
    }
    friend ostream& operator << (ostream& out, const List& l);
    friend istream& operator >> (istream& in, List& l);

};
ostream& operator << (ostream& out, const List& list)
{

    for (auto request : list.l)
    {
        out << request.GetDestination() << "," << request.GetNumber() << ","
            << request.GetPAss() << "," << request.GetDate() << endl;
    }
    return out;
}
istream& operator >> (istream& in, List& l)
{
    AccountingOfApplications t;
    while (in >> t)
    {
        l.AddToList(t);
    }
    return in;
}

int main()
{
    AccountingOfApplications a;
    List l;
    int choice = -1;
    ofstream file("fil.txt");
    List read;
    ifstream inFile("fil.txt");
    //string country_name ; int number; string full_name; string data;
    while (choice != 0)
    {
        cout << "\n\n\n\tMenu :D " << "\n\t\t1 - Add To List\n\t\t2 - Delete By Number\n\t\t3 - Print By Number\n\t\t4 - Show Info\n\t\t5 - Sort Requests By Date\n\t\t6 - Sort Requests By Destination\n\t\t7 - Save To File\n\t\t8 - Output From File\n\t\t0 - EXIT" << endl;;
        cout << "Enter choice : "; cin >> choice;
        switch (choice)
        {
        case 1:
            l.AddToList(AccountingOfApplications("Peru", 2, "Indiano J. G.", "30.02.2024"));
            l.AddToList(AccountingOfApplications("Maroco", 3, "Jimi J. J.", "26.01.2042"));
            l.AddToList(AccountingOfApplications("Nepal", 1, "Bishop A. H.", "30.02.2063"));
            /*cout << "\n\tEnter passenger information\n\t\tEnter country name : "; cin >> country_name;
            cout << "\n\t\tEnter flight number : "; cin >> number;
            cout << "\n\t\tEnter your last name and initials : "; cin >> full_name;
            cout << "\n\t\tEnter the departure date : "; cin >> data;
            l.AddToList(AccountingOfApplications(country_name, number, full_name, data));*/
            break;
        case 2:
            int Delete;
            cout << "\tWho do you want to remove? : "; cin >> Delete;
            l.DeleteByNumber(Delete);
            break;
        case 3:
            int Print;
            cout << "\tWho do you want to see? : "; cin >> Print;
            l.PrintByNumber(Print);
            break;
        case 4:
            l.ShowInfo();
            break;
        case 5:
            l.sortRequestsByDate();
            l.ShowInfo();
            break;
        case 6:
            l.sortRequestsByDestination();
            l.ShowInfo();
            break;
        case 7:
            file << l;
            file.close();
            cout << endl;
            break;
        case 8:
            inFile >> read;
            cout << " \n\t<<<<<<<<< Information From A File <<<<<<<<<<<\n";
            l.ShowInfo();
            break;
        case 0:
            choice = 0;
            break;
        default:
            cout << ":((((        Sory:D";
            break;
        }
    }




}