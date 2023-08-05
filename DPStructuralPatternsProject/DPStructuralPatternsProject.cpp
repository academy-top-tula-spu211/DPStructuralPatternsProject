#include <iostream>
#include "Adapter.h"

void AdapterExample()
{
    ISensorTarget* sensor = new CelsiusSensorAdapter(new CelsiusSensor());
    std::cout << sensor->GetSensorData() << "\n";
    delete sensor;

    sensor = new FahrenheitSensorAdapter(new FahrenheitSensor());
    std::cout << sensor->GetSensorData() << "\n";
    delete sensor;
}

int main()
{

    
}
