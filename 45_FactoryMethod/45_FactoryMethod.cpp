//#include <iostream>
//using namespace std;
//
//class User
//{
//public:
//    virtual void Info() = 0;
//};
//class Admin : public User
//{
//public:
//    virtual void Info() override
//    {
//        cout << "I'm admin" << endl;
//    }
//};
//class Manager : public User
//{
//public:
//    virtual void Info() override
//    {
//        cout << "I'm manager" << endl;
//    }
//};
//class Guest : public User
//{
//public:
//    virtual void Info() override
//    {
//        cout << "I'm guest" << endl;
//    }
//};
//
//int ReadCodeUserFromFile()
//{
//    return 2;
//}
////Admin Guest Manager
//class UserFactory//Factory method
//{
//public:
//    User* CreateUser(int code)
//    {
//        if (code == 0)
//        {
//            return new Admin();
//        }
//        if (code == 1)
//        {
//            return new Guest();
//        }
//        if (code == 2)
//        {
//            return new Manager();
//        }
//    }
//};
//int main()
//{
//
//    UserFactory factoryMethod;
//
//    int code = ReadCodeUserFromFile();
//
//    User * user = factoryMethod.CreateUser(code);
//    user->Info();
//
//    delete user;
//    
//}
//
