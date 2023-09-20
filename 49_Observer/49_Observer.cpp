#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
enum Status { None, Increase, Decrease };
struct CryptoCurrency
{
    string name;
    double price;
    Status status;
    int incCount = 0;
    int decCount = 0;
    CryptoCurrency(string n ,double p)
    {
        name = n;
        price = p;
        status = None;
        incCount = 0;
        decCount = 0;
    }
    void SetNewPrice(double newPrice)
    {
        if (newPrice > price)
        {
            incCount++;
            decCount = 0;
            if (incCount >= 3) status = Increase;
            else status = None;
        }
        else if (newPrice < price)
        {
            decCount++;
            incCount = 0;
            if (decCount >= 3) status = Decrease;
            else status = None;
        }
        price = newPrice;
    }
};
class Trader
{
    string name;
    double balance;
public:
    void Update(CryptoCurrency * currency)
    {
         switch (currency->status)
         {
         case None:cout << "Do nothing" << endl; break;
         case Increase:cout << "Buy" << endl;break;
         case Decrease:cout << "Sell" << endl; break;
         }
    }
};

class StockExchange
{
private:
    vector<CryptoCurrency*> cryptos;
    vector<Trader*> traders;//null
public:
    StockExchange()
    {
        cryptos.push_back(new CryptoCurrency("Dollar", 37.5));
        cryptos.push_back(new CryptoCurrency("Euro", 42.15));
        cryptos.push_back(new CryptoCurrency("Bitcoin", 27090));

    }
    void Subscribe(Trader* trader)
    {
        traders.push_back(trader);
    }
    double RandomPrice(double price)//37.5
    {
        return price + (rand() % 20 - 10);
    }
    void GeneratePrices()
    {
        for (auto c : cryptos)
        {
            c->SetNewPrice(RandomPrice(c->price));//38
            //notify all subscribers
            Notify(c);
        }
    }
    void Notify(CryptoCurrency * currency)
    {
        for (auto t : traders)
        {
            t->Update(currency);
        }
    }
    void StartTrading()
    {
        for (int i = 0; i < 1000; i++)
        {
            GeneratePrices();
            Sleep(1000);
        }
    }
};

int main()
{

    StockExchange exchange;

    Trader* tr1 = new Trader();
    Trader* tr2 = new Trader();
    Trader* tr3 = new Trader();

    exchange.Subscribe(tr1);
    exchange.Subscribe(tr2);
    exchange.Subscribe(tr3);

    exchange.StartTrading();

    delete tr1;
    delete tr2;
    delete tr3;
    
}

