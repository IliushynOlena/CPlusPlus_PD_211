#include <iostream>
using namespace std;
// Уже существующий класс температурного датчика окружающей среды
class FahrenheitSensor
{
public:
    // Получить показания температуры в градусах Фаренгейта
    float getFahrenheitTemp() {
        float t = 32.0;
        // ... какой то код
        return t;
    }
};

// Interface
class Sensor
{
public:
    virtual ~Sensor() {}
    virtual float getTemperature() = 0;
};

class Adapter : public Sensor
{
private:
    FahrenheitSensor* p_fsensor;
public:
    Adapter(FahrenheitSensor* p) : p_fsensor(p) {
    }
  
    float getTemperature() {
        return (p_fsensor->getFahrenheitTemp() - 32.0) * 5.0 / 9.0;
    }

};

class ControlSystem
{
public:
    void Normilize(Sensor* sensor)
    {
        cout << "Celsius temperature = " << sensor->getTemperature() << endl;
        // func
        // ........
    }
};

int main()
{
    // Sensor* p = new Adapter( new FahrenheitSensor);
    FahrenheitSensor* fahrenheitSensor = new FahrenheitSensor();

    Adapter ad(fahrenheitSensor);

    ControlSystem system;
    //system.Normilize(&fahrenheitSensor);//error
    system.Normilize(&ad);

    delete fahrenheitSensor;
    return 0;
}