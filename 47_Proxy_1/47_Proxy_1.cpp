//#include <iostream>
//using namespace std;
//
//class Subject
//{
//public :
//    virtual void Print()
//    {
//        cout << "This is a subject" << endl;
//    }
//};
//
//class SubjectProxy : public Subject
//{
//public:
//    virtual void Print() override
//    {
//        cout << "Before calling Subject::Print()" << endl;
//        Subject::Print();
//        cout << "After calling Subject::Print()" << endl;
//    }
//};
//class Helper
//{
//public:
//    static Subject* GetSubject()
//    {
//        return new SubjectProxy();
//    }
//};
//int main()
//{
//  //  Subject s;
//  //  s.Print();
//  ///*  Print();
//  //  Subject::Print();*/
//  //  Helper h;
//  //  h.GetSubject();
//
//    Subject * sub = Helper::GetSubject();
//    sub->Print();
//}
//
