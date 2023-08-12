#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// UNIT - Component
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

// UNITS - Leafs
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

// Units Group - Composite
class UnitGroup : public Unit
{
	vector<Unit*> group;
public:
	UnitGroup(string name) : Unit{ name } {};

	int Attack() override
	{
		int attack{};
		for (auto unit : group)
			attack += unit->Attack();
		return attack;
	}

	string ToString() override
	{
		string str = Unit::ToString() + "\n";
		for (auto unit : group)
			str += "\t" + unit->ToString()
						+ "\n";
		return str;
	}

	void Add(Unit* unit)
	{
		group.push_back(unit);
	}

	void Remove(int index)
	{
		group.erase(group.begin() + index);
	}
};
