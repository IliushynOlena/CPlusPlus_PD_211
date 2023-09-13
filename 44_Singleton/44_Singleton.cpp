//#include <iostream>
//using namespace std;
//
//class Singleton
//{
//private:
//    static Singleton* p_instance;
//    Singleton() {}
//    Singleton(const Singleton& other) = delete;
//    Singleton& operator = (const Singleton& other) = delete;
//public:   
//   
//    static Singleton* GetInstance()
//    {
//        if (p_instance == nullptr)
//        {
//            p_instance = new Singleton();
//        }
//        return p_instance;
//    }
//    void Log(string msg)
//    {
//        cout << " Msg : " << msg << endl;
//    }
//};
//Singleton* Singleton::p_instance = nullptr;
//
//int main()
//{
//    //Singleton p;///default constructor
//    //p.p_instance = nullptr;
//    //Singleton::p_instance = nullptr;
//    Singleton* ptr =  Singleton::GetInstance();
//    ptr->Log("Hello world");
//    Singleton::GetInstance()->Log("Insert new user at 21:15");
//    Singleton::GetInstance()->Log("Download file");
//    Singleton::GetInstance()->Log("Download game Fortnight");
//    Singleton::GetInstance()->Log("Delete Visual Studio");
//
//    Singleton* ptr2 = Singleton::GetInstance();
//    ptr2->Log("Hello world");
//
//    //Singleton test;//default constructor
//    //Singleton test2(test);//copy constructor
//    //Singleton test3 = test;//operator =
//    //p.Log("Hello world from p1");
//    // Singleton *ptr = p.GetInstance();
//    //Singleton p1;
//   // p1.Log("Hello world from p2");
//    //Singleton p2;
//    ////Singleton p3;
//    //Singleton p4;
//    ///Singleton p5;
//    
//}
