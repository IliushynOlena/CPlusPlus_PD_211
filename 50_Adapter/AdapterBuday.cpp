//#include <iostream>
//using namespace std;
//
//class AmericanSocket
//{
//public:
//    virtual void MatchAmericanSocket()
//    {
//        cout << "US 220 V\n";
//    }
//};
//class EuroSocket
//{
//public:
//    virtual void MatchEuroSocket()
//    {
//        cout << "Euro 220 V\n";
//    }
//};
//
//class ElectricityConsumer
//{
//public:
//    void Charge(EuroSocket *socket)
//    {
//        socket->MatchEuroSocket();
//    }
//};
//
//class Adapter : public EuroSocket
//{
//private:
//    AmericanSocket* usaS;
//public:
//
//    Adapter(AmericanSocket* usaSocket)
//    {
//        usaS = usaSocket;
//    }
//
//    void MatchEuroSocket() override
//    {
//        usaS->MatchAmericanSocket();
//        // additional functionality
//    }
//};
//
//void main()
//{
//    EuroSocket euroS;
//    AmericanSocket usaS;
//
//    Adapter ad(&usaS);
//
//    ElectricityConsumer consumer;
//    consumer.Charge(&ad);
//    consumer.Charge(&euroS);
//
//    //ElecricityConsuner.Charge(Adapter(usaS));
//
//
//}