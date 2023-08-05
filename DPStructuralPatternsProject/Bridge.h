#pragma once
#include <vector>
using namespace std;

class IPlayer
{
};

class IGameImplementation;

class IGame
{
protected:
	IGameImplementation* implGame;
public:
	IGame(IGameImplementation* implGame)
		: implGame{ implGame } {};

	virtual IGameImplementation*& Implementation() { return implGame; }

	virtual void Setup() = 0;
	virtual void Step() = 0;
	virtual void Process() = 0;
	virtual bool Validate() = 0;
	virtual void Show() = 0;

	virtual ~IGame() {}
};

class IGameImplementation
{
public:
	virtual void SetupImpl(vector<IPlayer*>&) = 0;
	virtual void StepImpl(vector<IPlayer*>) = 0;
	virtual void ShowImpl(vector<IPlayer*>) = 0;
	virtual bool ValidateImpl() = 0;
};

