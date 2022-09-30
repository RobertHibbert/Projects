#include "CPenalty.h"

CPenalty::CPenalty(istream& file, int type) : CSquare(file, type)
{
	file >> *this;
}

CPenalty::~CPenalty()
{
}

istream& operator >> (istream& inputStream, CPenalty& penalty)
{
	return inputStream;
}

// this code will see what penalty the player needs to get
void CPenalty::SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3)
{
	int randomNumber = RandomNumber(); // will get a random number that will be used to see what penalty they need
	if (randomNumber == ACTION1) // if the random number is the same as the action number then it will run the if statment 
	{
		cout << "Buy a coffee in Starbucks. Lose " << POUND << "20" << endl;
		player->ChangeMoneydown(STARBUCKS); // takes away the penalty from the players total
	}
	else if (randomNumber == ACTION2) // if the random number is the same as the action number then it will run the if statment 
	{
		cout << "Pay your broadband bill. Lose " << POUND << "50" << endl;
		player->ChangeMoneydown(BROADBAND); // takes away the penalty from the players total
	}
	else if (randomNumber == ACTION3) // if the random number is the same as the action number then it will run the if statment 
	{
		cout << "Vist the SU shop for food. Lose " << POUND << "100" << endl;
		player->ChangeMoneydown(SU_SHOP); // takes away the penalty from the players total
	}
	else if (randomNumber == ACTION4) // if the random number is the same as the action number then it will run the if statment 
	{
		cout << "Buy an assignment solution. Lose " << POUND << "150" << endl;
		player->ChangeMoneydown(ASSIGNMENT_SOLUTION); // takes away the penalty from the players total
	}
	else if (randomNumber == ACTION5) // if the random number is the same as the action number then it will run the if statment 
	{
		cout << "Go for a romantic meal. Lose " << POUND << "200" << endl;
		player->ChangeMoneydown(ROMANTIC_MEAL); // takes away the penalty from the players total
	}
	else if (randomNumber == ACTION6) // if the random number is the same as the action number then it will run the if statment 
	{
		cout << "Pay some university fees. Lose " << POUND << "300" << endl;
		player->ChangeMoneydown(UNIVERSITY_FEES); // takes away the penalty from the players total
	}
}

void CPenalty::SquareMortagaging(SmartPtr_CPlayer player, string decision)
{
}
