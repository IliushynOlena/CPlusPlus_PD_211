
#include <iostream>
#include <string>
using namespace std;
template<typename T>
class Prototype
{
public:
    virtual T Clone() const = 0 ;
};
struct Date
{
    int year, month, day;
    string ToString()const
    {
        return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
    }
};
class Member : public Prototype<Member>
{
private:
    string name;
    int age;
public:
    Member():name("no name"),age(0){}
    Member(string name, int age):name(name),age(age){}
    string ToString()const
    {
        return name + "  " + to_string(age);
    }
    Member Clone() const override
    {
        return *this;
    }
};
class Event : public Prototype<Event>
{
private:
    string name;//Independency day
    Date date;//2024/08/24
    string address;//Kyiv
    Member* members;//0x126546
    int countMember;//2
public:
    Event Clone()const override
    {
        Event clone = *this;
        //Independency day
       //2024/08/24
       //Kyiv
       //0x126546 - Error
        clone.members = new Member[countMember];
        for (int i = 0; i < countMember; i++)
        {
            clone.members[i] = this->members[i].Clone();
        }
       
        //2
        return clone;
    }
    Event(const Event & other)
    {
        this->name = other.name;//Independency day
        this->date = other.date;//2024/08/24
        this->address = other.address;//Kyiv
        //this->members = other.members;//0x126546
        this->members = new Member[other.countMember];
        for (int i = 0; i < other.countMember; i++)
        {
            this->members[i] = other.members[i];
        }
        this->countMember = other.countMember;//2
    }
    Event() :name("no name"), date(Date{ 0,0,0 }), address("no address") {}
    Event(string name, Date date, string address) :name(name), date(date), address(address) {}
    void AddTestMembers()
    {
        countMember = 2;
        members = new Member[countMember];
        members[0] = Member("Bob", 30);
        members[1] = Member("Tom", 22);
   }
    string ToString()const
    {
        string res = name + " : " + date.ToString() + "\n" + address + "\n";
        for (int i = 0; i < countMember; i++)
        {
            res += "\tMembers [" + to_string(i + 1) + "] - " + members[i].ToString() + "\n";
        }
        return res;
    }
    ~Event()
    {
        delete[]members;
    }
};


int main()
{
    Event event("Independency day", Date {2024, 8, 24}, "Kyiv, Ukraine");
    event.AddTestMembers();

    cout << event.ToString() << endl;


    Event copy(event);//copy constructor
    cout << "Copy event :\n" <<  copy.ToString() << endl;

    Event clone = event.Clone();
    cout << "Clone event :\n" <<  clone.ToString() << endl;

}

