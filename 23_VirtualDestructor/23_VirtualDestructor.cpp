//#include <iostream>
//using namespace std;
//
//class Student
//{
//	string name;
//	string spetialization;
//	int* marks;
//	int markCount;
//public:
//	Student() :name(""), spetialization(""), marks(nullptr), markCount(0) {}
//	Student(string name, string spetialization):name(name), spetialization(spetialization)
//	{
//		markCount = rand() % 10 + 1;//1-12
//		marks = new int[markCount];
//		for (int i = 0; i < markCount; i++)
//		{
//			marks[i] = 8 + rand() % 4;//8-12
//		}
//	}
//	virtual void Print()const
//	{
//		cout << "\nName : " << name << endl;
//		cout << "Spetialization : " << spetialization << endl;
//		cout << "Marks : ";
//		for (int i = 0; i < markCount; i++)
//		{
//			cout << marks[i] << " ";
//		}
//		cout << "\n_____________________________" << endl;
//	}
//	virtual ~Student()
//	{
//		if (marks != nullptr)
//			delete[]marks;
//	}
//};
//
//class Aspirant: public Student
//{
//	string *subjects;
//	int countSubjects;
//public:
//	Aspirant(string name, string spetialization, initializer_list<string> sub) ://8
//		Student(name, spetialization) 
//	{
//		this->countSubjects = sub.size();
//		subjects = new string[countSubjects];
//		int i = 0;
//		for (string subj : sub)
//		{
//			subjects[i] = subj;
//			i++;
//		}
//	}
//	void Print()const override
//	{
//		Student::Print();
//		cout << "Subject :  ";
//		for (int i = 0; i < countSubjects; i++)
//		{
//			cout << subjects[i] << " ";
//		}
//	}
//	~Aspirant()
//	{
//		if (subjects != nullptr)
//			delete[]subjects;
//	}
//};
//int main()
//{
//	srand(time(0));
//	/*Student student("Danulo","Programmer");
//	student.Print();
//
//	Aspirant aspirant("Daniel", "Designer", { "UI/UX","Main page", "Defense Earth"});
//	aspirant.Print();*/
//	cout << "\n*******************************" << endl;
//	Student* groups[3]{
//		new Student("Danulo","Programmer"),
//		new Aspirant("Daniel", "Designer", { "UI/UX","Main page", "Defense Earth"}),
//		new Aspirant("Olya", "Manager", { "Audut","Finance"})
//	};
//	for (int i = 0; i < 3; i++)
//	{
//		groups[i]->Print(); 
//		delete groups[i];
//	}
//  
//}