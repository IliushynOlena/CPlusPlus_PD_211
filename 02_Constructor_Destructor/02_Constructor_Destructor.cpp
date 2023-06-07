#include <iostream>
#include<Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

int Max(int a, int b)
{
    return a > b ? a : b;
}
float Max(float a, float b)
{
    return a > b ? a : b;
}
int Max(int a, int b, int c)
{
    return a > b ? a : b;
}

struct Date
{
    int day;
    int month;
    int year;
};

class Student
{
private:
    string name;
    string last_name;
    string surname;
    Date birth_date;
    string phone;
    string city;
    string country;
    string education;
    string education_city;
    string education_country;
    string group_number;
    int* marks;
    int markCount;
    float averageMark;
    void SetAverage()
    {
        float sum = 0;
        for (int i = 0; i < markCount; i++)
        {
            sum += marks[i];
        }
        averageMark = (float)sum / markCount;
    }
public:
    //ctor + TAB
    Student()
    {
        cout << "Constructor" << name << endl;
        name = "no name";
        last_name = "no last name";
        surname = "no surname";
        birth_date = {0,0,0};
        phone = "no phone";
        city = "no city";
        country = "no country";
        education = "no education";
        education_city = "no education_city";
        education_country = "no education_country";
        group_number = "no group_number";
        marks = nullptr;
        markCount = 0;
        averageMark = 0;
    }
    Student(string name)
    {
        cout << "Constructor invocation..." << name << endl;
        this->name = name;
    }
    Student(string name, string surname, string lastname)
    {
        cout << "Constructor invocation..." << name << endl;
        this->name = name;
        this->surname = surname;
        this->last_name = lastname;
    }
#pragma region SetGet
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setLastName(string last_name)
    {
        this->last_name = last_name;
    }
    string getLastName()
    {
        return last_name;
    }
    void setSurname(string surname)
    {
        this->surname = surname;
    }
    string getSurname()
    {
        return surname;
    }
    void setBithday(Date date)
    {
        this->birth_date.day = date.day;
        this->birth_date.month = date.month;
        this->birth_date.year = date.year;
    }
    Date getBirthday()
    {
        return birth_date;
    }
    void setPhone(string phone)
    {
        this->phone = phone;
    }
    string getPhone()
    {
        return phone;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    string getCity()
    {
        return city;
    }
    void setCountry(string coutry)
    {
        this->country = country;
    }
    string getCountry()
    {
        return country;
    }
    void setEducation(string ed)
    {
        this->education = ed;
    }
    string getEducation()
    {
        return education;
    }
    void setCityEducation(string city)
    {
        this->city = city;
    }
    string getCityEducation()
    {
        return city;
    }
    void setEducation_country(string education_country)
    {
        this->education_country = education_country;
    }
    string getEducation_country()
    {
        return education_country;
    }
    void setGroup_number(string group_number)
    {
        this->group_number = group_number;
    }
    string getGroup_number()
    {
        return group_number;
    }
    void Print()
    {
        cout << "Name : " << name << endl;
        cout << "Last name  : " << last_name << endl;
        cout << "Surname : " << surname << endl;
        cout << "Birthday : " << birth_date.day << "."<<birth_date.month<<"."<<birth_date.year << endl;
        cout << "Phone : " << phone << endl;
        cout << "City : " << city << endl;
        cout << "Country : " << country << endl;
        cout << "Education : " << education << endl;
        cout << "Education city : " << education_city << endl;
        cout << "Education country : " << education_country << endl;
        cout << "Group : " << group_number << endl;  
        cout << "Rating : ";
        for (int i = 0; i < markCount; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Average Mark : " << averageMark << endl;
    }
    void Input()
    {
        cout << "Enter Name : "; 
        cin >> name ;
        cout << "Enter Last name  : ";
        cin >> last_name ;
        cout << "Enter Surname : "; 
        cin >> surname ;
        cout << "Enter Birthday : "; 
        cin >> birth_date.day;
        cin >> birth_date.month; ; 
        cin >> birth_date.year ;
        cout << "Enter Phone : "; 
        cin >> phone ;
        cout << "Enter City : "; 
        cin >> city;
        cout << "Enter Country : "; 
        cin >> country ;
        cout << "Enter Education : "; 
        cin >> education ;
        cout << "Enter Education city : "; 
        cin >> education_city ;
        cout << "Enter Education country : "; 
        cin >> education_country;
        cout << "Enter Group : "; 
        cin >> group_number;
    }
#pragma endregion
    void AddMark(int mark)
    {
        //int* marks = nullptr;
        ///int markCount = 0;
        markCount++;//3
        int* temp = new int[markCount];//3
        for (int i = 0; i < markCount-1; i++)
        {
            temp[i] = marks[i];
        }
        temp[markCount - 1] = mark;
        if (marks != nullptr)
            delete[]marks;
        marks = temp;
        SetAverage();
    }
    void Delete()
    {
        if (marks != nullptr)
            delete[]marks;
    }
    //~ + TAB
    ~Student()
    {
        cout << "Destructor" << name << endl;
        Delete();
    }
};

int main()
{
    gotoxy(10, 10);
    Student student("Olena");
    student.AddMark(10);
    student.AddMark(8);
    student.AddMark(5);
    student.AddMark(12);
    student.AddMark(11);
    student.Print();
    cout << endl;
    Student student1("Olena", "Iliushyn", "Sergievna");
    student1.Print();
    cout << endl;
    Student st;//default c-tor
    st.setName("Vasia");
    //st.Input();
    st.Print();

    //st.setCity("Kyiv");
    //st.setEducation("IT_Step");
    //st.Print();
    Student st2;//default c-tor
    st2.setName("Petro");
    //st2.Print();
    Student st3;//default c-tor
    st3.setName("Ivan");
    Student st4;//default c-tor
    st4.setName("Mukola");
    Student st5;//default c-tor
    st5.setName("Ivanka");
    
}

