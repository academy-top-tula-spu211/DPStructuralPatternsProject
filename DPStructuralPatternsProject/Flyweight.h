#pragma once
#include <iostream>
#include <map>

using namespace std;

class BookBad
{
    string title;
    string authorNameFirst;
    string authorNameLast;
public:
    BookBad(string title,
        string authorNameFirst,
        string authorNameLast)
        : title{ title },
        authorNameFirst{ authorNameFirst },
        authorNameLast{ authorNameLast } {};
};

class Author
{
    string authorNameFirst;
    string authorNameLast;
public:
    Author(string authorNameFirst,
            string authorNameLast)
        : authorNameFirst{ authorNameFirst },
        authorNameLast{ authorNameLast } {};
};

class BookGood
{
    string title;
    Author* author;
};




class House
{
protected:
    int floors;
public:
    virtual void Build(double longtude, double latitude) = 0;
};

class PanelHouse : public House
{
public:
    PanelHouse() { this->floors = 9; }

    void Build(double longtude, double latitude) override
    {
        cout << "Panel house building:\n"
            << "\tFoolrs: " << this->floors << "\n"
            << "\tLongtude: " << longtude << "\n"
            << "\tLatitude: " << latitude << "\n\n";
    }
};

class BrickHouse : public House
{
public:
    BrickHouse() { this->floors = 5; }

    void Build(double longtude, double latitude) override
    {
        cout << "Brick house building:\n"
            << "\tFoolrs: " << this->floors << "\n"
            << "\tLongtude: " << longtude << "\n"
            << "\tLatitude: " << latitude << "\n\n";
    }
};

class HouseFactory
{
    map<string, House*> houses;
public:
    HouseFactory()
    {
        houses.insert(make_pair("Panel", new PanelHouse()));
        houses.insert(make_pair("Brick", new BrickHouse()));
    }

    House* GetHouse(string key)
    {
        if (houses.find(key) != houses.end())
            return houses[key];
        else
            return nullptr;
    }
};