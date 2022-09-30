#pragma once
#include <iostream>
#include <string>
#include "Constants.h"
using namespace std;

class CPlayer
{
protected:
	string name; // stores the name of the player
	string bankrupt = "NO"; // says if the player is bankrupt or not
	double money = 1500; // stores the players money
	int position = 0; // stores the players position
	bool passGo = false; // checks if they have passed go
	int propetryGotType0 = 0; // stores the amount of propertys of this type
	int propetryGotType1 = 0; // stores the amount of propertys of this type
	int propetryGotType2 = 0; // stores the amount of propertys of this type
	int propetryGotType3 = 0; // stores the amount of propertys of this type
	int propetryGotType4 = 0; // stores the amount of propertys of this type
	int propetryGotType5 = 0; // stores the amount of propertys of this type
	int propetryGotType6 = 0; // stores the amount of propertys of this type
	int propetryGotType7 = 0; // stores the amount of propertys of this type
public:
	CPlayer(string playerName);
	~CPlayer();
	double ShowMoney(); // returns of amount of money a player has got
	int ChangePosition(int roll); // changes the players position
	void GoPassed(); // checks if a player has passed go
	string ShowName(); // shows the players name
	void ChangeMoneyup(double change); // changes a players money with given paramater
	void ChangeMoneydown(double change); // changes a players money with given paramater
	void MoveToJail(); // moves a player to jail
	void AddProperty(int type); // adds a new property colour to a players collection
	double CheckOwnership(int type); // checks if a player owner a set of a sertain property
	void MakeBankrupt(); // makes a player bankrupt
	string CheckBankrupt(); // checks if a player is bankrupt
};

typedef shared_ptr<CPlayer> SmartPtr_CPlayer;
