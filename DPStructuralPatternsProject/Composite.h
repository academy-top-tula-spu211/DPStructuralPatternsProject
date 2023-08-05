#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// UNIT
class Unit
{
protected:
	string name;
	int attack;
public:
	string& Name() { return name; }
	Unit(string name) : name{ name }, attack{} {}

	virtual string ToString()
	{
		return "Unit: " + name + " " + to_string(Attack());
	}

	virtual int Attack()
	{
		return attack;
	}

	virtual ~Unit() {}
};

// UNITS
class InfantryUnit : public Unit
{
public:
	InfantryUnit() : Unit("Infantry") { attack = 1; };

};

class ArcherUnit : public Unit
{
public:
    ArcherUnit() : Unit("Archer") { attack = 3; };
    
};

class CavalryUnit : public Unit
{
public:
    CavalryUnit() : Unit("Cavalry") { attack = 3; };
    
};


// FACTORIES
class FactoryMethod
{
public:
	virtual Unit* UnitCreate() = 0;
	virtual ~FactoryMethod() {};
};

class InfantryFactory : public FactoryMethod
{
public:
	Unit* UnitCreate() override
	{
		return new InfantryUnit();
	}
};

class ArcherFactory : public FactoryMethod
{
public:
	Unit* UnitCreate() override
	{
		return new ArcherUnit();
	}
};

class CavalryFactory : public FactoryMethod
{
public:
	Unit* UnitCreate() override
	{
		return new CavalryUnit();
	}
};


