#pragma once
#include <iostream>
#include "Bridge.h"
using namespace std;

class SPlayer : public IPlayer
{
	string name;
public:
	SPlayer(string name = "") : name{name} {};
	string& Name() { return name; }
};


class StrategyGame : public IGame
{
	vector<IPlayer*> players;
public:
	StrategyGame(IGameImplementation* implGame)
		: IGame(implGame)
	{
		players.reserve(2);
	}

	void Setup() override
	{
		implGame->SetupImpl(players);
	}

	void Step() override
	{
		implGame->StepImpl(players);
	}

	bool Validate() override
	{
		return implGame->ValidateImpl();
	}
	
	void Show() override
	{
		implGame->ShowImpl(players);
	}

	void Process() override
	{
		int step{};
		do
		{
			cout << "======= " << ++step << " round =========\n";
			Step();
			Show();
		} while (Validate());
	}
};

class KeyboardImpl : public IGameImplementation
{
public:
	void SetupImpl(vector<IPlayer*>& players) override
	{
		cout << "Console input\n";
		for (int i = 0; i < players.size(); i++)
		{
			players[i] = new SPlayer();
			cout << "inputa name " << i + 1 << "player: ";
			cin >> ((SPlayer*)players[i])->Name();
		}
	}

	virtual void StepImpl(vector<IPlayer*> players) override
	{
		cout << "console step:\n";
		for (int i = 0; i < players.size(); i++)
			cout << i + 1 << " player step "
				 << ((SPlayer*)players[i])->Name();
	}

	virtual void ShowImpl(vector<IPlayer*> players) override
	{
		cout << "console show:\n";
		for (int i = 0; i < players.size(); i++)
			cout << i + 1 << "player "
				 << ((SPlayer*)players[i])->Name();
	}

	virtual bool ValidateImpl() override
	{
		char ch;
		cout << "continue? y/n: ";
		cin >> ch;
		return ch != 'n';
	}

};

