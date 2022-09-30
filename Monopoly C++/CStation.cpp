#include "CStation.h"

CStation::CStation(istream& file, int type) : CSquare(file, type)
{
	file >> *this;
}

CStation::~CStation()
{
}

istream& operator >> (istream& inputStream, CStation& railway)
{
	return inputStream;
}

void CStation::SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3)
{
	string name = player->ShowName();
	string player2 = otherplayer->ShowName();
	string player3 = otherplayer2->ShowName();
	string player4 = otherplayer3->ShowName();
	// checks that it does not have an owner yet
	if (owner == "NO") 
	{
		double money = player->ShowMoney();
		// if it does not have an owner and they have the funds then they can buy it
		if (money > 0)
		{
			owner = name;
			cout << name << " buys " << *square[position] << " for " << POUND << squareCost << endl;
			player->ChangeMoneydown(squareCost);
		}
	}
	// if they already own it then nothing happens
	else if (owner == name)
	{
	}
	// if another player ownes it then they need to pay for landing on it
	else
	{
		if (player2 == owner)
		{
			player->ChangeMoneydown(squareFee); // this takes money away from the current player
			otherplayer->ChangeMoneyup(squareFee); //this give it to the other player
			cout << name << " pays " << POUND << squareFee << "  for ticket" << endl;
		}
		else if (player3 == owner)
		{
			player->ChangeMoneydown(squareFee);// this takes money away from the current player
			otherplayer2->ChangeMoneyup(squareFee);//this give it to the other player
			cout << name << " pays " << POUND << squareFee << "  for ticket" << endl;
		}
		else if (player4 == owner)
		{
			player->ChangeMoneydown(squareFee);// this takes money away from the current player
			otherplayer3->ChangeMoneyup(squareFee);//this give it to the other player
			cout << name << " pays " << POUND << squareFee << "  for ticket" << endl;
		}
	}
}

void CStation::SquareMortagaging(SmartPtr_CPlayer player, string decision)
{
}