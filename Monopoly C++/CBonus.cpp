#include "CBonus.h"

CBonus::CBonus(istream& file, int type) : CSquare(file, type)
{
	file >> *this;
}

CBonus::~CBonus()
{
}

istream& operator >> (istream& inputStream, CBonus& bonus)
{
	return inputStream;
}

void CBonus::SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3)
{
	int randomNumber = RandomNumber(); // gets a random number to see waht bonus the player will get
	if (randomNumber == ACTION1) // if the random number is the same as the action number
	{
		cout << "Find some money. Gain " << POUND << "20" << endl;
		player->ChangeMoneyup(FIND_MONEY); // adds the money to the players total
	}
	else if (randomNumber == ACTION2) // if the random number is the same as the action number
	{
		cout << "Win a coding competition. Gain " << POUND << "50" << endl;
		player->ChangeMoneyup(CODING_COMPETITION); // adds the money to the players total
	}
	else if (randomNumber == ACTION3) // if the random number is the same as the action number
	{
		cout << "Receive a rent rebate. Gain " << POUND << "100" << endl;
		player->ChangeMoneyup(RENT_REBATE); // adds the money to the players total
	}
	else if (randomNumber == ACTION4) // if the random number is the same as the action number
	{
		cout << "Win the lottery. Gain " << POUND << "150" << endl;
		player->ChangeMoneyup(LOTTERY); // adds the money to the players total
	}
	else if (randomNumber == ACTION5) // if the random number is the same as the action number
	{
		cout << "Receive a bequesst. Gain " << POUND << "200" << endl;
		player->ChangeMoneyup(BEQUEST); // adds the money to the players total
	}
	else if (randomNumber == ACTION6) // if the random number is the same as the action number
	{
		cout << "It's your birthday. Gain " << POUND << "300" << endl;
		player->ChangeMoneyup(BIRTHDAY); // adds the money to the players total
	}
}

void CBonus::SquareMortagaging(SmartPtr_CPlayer player, string decision)
{
}