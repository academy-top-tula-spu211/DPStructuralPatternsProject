#include <iostream>
#include "Adapter.h"
#include "Composite.h"
#include "Decorator.h"
#include "Facade.h"
#include "Proxy.h"
#include "Flyweight.h"

void AdapterExample()
{
    ISensorTarget* sensor = new CelsiusSensorAdapter(new CelsiusSensor());
    std::cout << sensor->GetSensorData() << "\n";
    delete sensor;

    sensor = new FahrenheitSensorAdapter(new FahrenheitSensor());
    std::cout << sensor->GetSensorData() << "\n";
    delete sensor;
}

void CompositeExample()
{
    srand(time(nullptr));
    vector<FactoryMethod*> factories;
    factories.push_back(new InfantryFactory());
    factories.push_back(new ArcherFactory());
    factories.push_back(new CavalryFactory());

    Unit* legion1 = new UnitGroup("Legion 1");
    int size1 = 10 + rand() % 10;
    for (int i = 0; i < size1; i++)
    {
        auto unit = factories[rand() % 3]->UnitCreate();
        ((UnitGroup*)legion1)->Add(unit);
    }

    Unit* legion2 = new UnitGroup("Legion 2");
    size1 = 10 + rand() % 10;
    for (int i = 0; i < size1; i++)
    {
        auto unit = factories[rand() % 3]->UnitCreate();
        ((UnitGroup*)legion2)->Add(unit);
    }

    Unit* army = new UnitGroup("Army");
    size1 = 20 + rand() % 10;
    for (int i = 0; i < size1; i++)
    {
        auto unit = factories[rand() % 3]->UnitCreate();
        ((UnitGroup*)army)->Add(unit);
    }

    ((UnitGroup*)army)->Add(legion1);
    ((UnitGroup*)army)->Add(legion2);

    cout << legion1->ToString() << "\n\n";
    cout << army->ToString() << "\n\n";
}

void DecoratorExample()
{
    IMessage* messageWathUp = new EmailMessage("Foma", "Erema", "Hello Erema!", ":-)");
    messageWathUp->Send();
    cout << "\n";

    messageWathUp = new ContactMessage(messageWathUp, "Afonya 123-45-67");
    ((IMessageDecorator*)messageWathUp)->Message()->To() = "Onufim";
    messageWathUp->Send();
    cout << "\n";

    messageWathUp = new FileMessage(messageWathUp, "docs.pdf");
    messageWathUp->Send();
    cout << "\n";
}

void FacadeExample()
{
    VisualStudioFacade* studio = new VisualStudioFacade(
        new TextEditor(),
        new Compiller(),
        new Debugger(),
        new Runtime()
    );

    studio->Process();
}

void ProxyExample()
{
    srand(time(nullptr));

    map<int, Page*> book;
    book[1] = new Page(1, "aaaa");
    book[2] = new Page(2, "bbbb");
    book[3] = new Page(3, "cccc");
    book[4] = new Page(4, "dddd");
    book[5] = new Page(5, "eeee");

    BookStoreProxy* proxy = new BookStoreProxy(new BookStore(book));


    for (int i = 0; i < 10; i++)
    {
        int number = 1 + rand() % 5;
        auto page = proxy->GetPage(number);
        cout << page->Number() << " " << page->Text() << "\n";
    }
}

void FliweightExample()
{
    HouseFactory factory;

    double longitude = 37.65;
    double latitude = 55.65;

    for (int i = 0; i < 5; i++)
    {
        House* house = factory.GetHouse("Panel");
        if (house != nullptr)
            house->Build(longitude, latitude);
        longitude += 0.1;
        latitude += 0.1;
    }

    for (int i = 0; i < 5; i++)
    {
        House* house = factory.GetHouse("Brick");
        if (house != nullptr)
            house->Build(longitude, latitude);
        longitude += 0.1;
        latitude += 0.1;
    }
}

int main()
{
    
    

    
}
