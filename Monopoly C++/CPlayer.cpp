#include "CPlayer.h"

CPlayer::CPlayer(string playerName)
{
	name = playerName;
}

CPlayer::~CPlayer()
{
}

// shows the players name
string CPlayer::ShowName()
{
	return name;
}

// changes player position from roll
int CPlayer::ChangePosition(int roll)
{
	position = position + roll;

	if (position >= BOARDSIZE) // if it goes over the boardsize it will go back to go again
	{
		position = position - BOARDSIZE;
		passGo = true; // marks that it has passed go
	}
	return position;
}

// checks if the player has passsed go
void CPlayer::GoPassed()
{
	if (passGo == true) // if they ahve passed go
	{
		money = money + PASS_GO; // adds £200 to money
		passGo = false; // changes it back to false
		cout << name << " passes GO and collects " << POUND << "200" << endl;
	}
}

// shows the plaers money
double CPlayer::ShowMoney()
{
	return money;
}

// cheages the players money down from the passsed paramiter
void CPlayer::ChangeMoneydown(double change)
{
	money = money - change;
}

// cheages the players money up from the passsed paramiter
void CPlayer::ChangeMoneyup(double change)
{
	money = money + change;
}

// moves the player to jail
void CPlayer::MoveToJail()
{
	position = JAIL_POSITION;
}

// adds a new property colour to a players collection
void CPlayer::AddProperty(int type)
{
	if (type == SQUARE_COLOUR0) // if the property type is the same as this square colour
	{
		propetryGotType0++;
	}
	else if (type == SQUARE_COLOUR1) // if the property type is the same as this square colour
	{
		propetryGotType1++;
	}
	else if (type == SQUARE_COLOUR2) // if the property type is the same as this square colour
	{
		propetryGotType2++;
	}
	else if (type == SQUARE_COLOUR3) // if the property type is the same as this square colour
	{
		propetryGotType3++;
	}
	else if (type == SQUARE_COLOUR4) // if the property type is the same as this square colour
	{
		propetryGotType4++;
	}
	else if (type == SQUARE_COLOUR5) // if the property type is the same as this square colour
	{
		propetryGotType5++;
	}
	else if (type == SQUARE_COLOUR6) // if the property type is the same as this square colour
	{
		propetryGotType6++;
	}
	else if (type == SQUARE_COLOUR7) // if the property type is the same as this square colour
	{
		propetryGotType7++;
	}
}

// checks how much resnt should be payed (if a player has a colour set it will be more)
double CPlayer::CheckOwnership(int type)
{
	if (type == SQUARE_COLOUR0) // if the property type is the same as this square colour
	{
		if (propetryGotType0 == SQUARE_GATHERED2) // if the player has got a clour set the rent will be double
		{
			return DOUBLE_RENT;
		}
		else
		{
			return NORMAL_RENT;
		}
	}
	else if (type == SQUARE_COLOUR1) // if the property type is the same as this square colour
	{
		if (propetryGotType1 == SQUARE_GATHERED2) // if the player has got a clour set the rent will be double
		{
			return DOUBLE_RENT;
		}
		else
		{
			return NORMAL_RENT;
		}
	}
	else if (type == SQUARE_COLOUR2) // if the property type is the same as this square colour
	{
		if (propetryGotType2 == SQUARE_GATHERED2) // if the player has got a clour set the rent will be double
		{
			return DOUBLE_RENT;
		}
		else
		{
			return NORMAL_RENT;
		}
	}
	else if (type == SQUARE_COLOUR3) // if the property type is the same as this square colour
	{
		if (propetryGotType3 == SQUARE_GATHERED3) // if the player has got a clour set the rent will be double
		{
			return DOUBLE_RENT;
		}
		else
		{
			return NORMAL_RENT;
		}
	}
	else if (type == SQUARE_COLOUR4) // if the property type is the same as this square colour
	{
		if (propetryGotType4 == SQUARE_GATHERED2) // if the player has got a clour set the rent will be double
		{
			return DOUBLE_RENT;
		}
		else
		{
			return NORMAL_RENT;
		}
	}
	else if (type == SQUARE_COLOUR5) // if the property type is the same as this square colour
	{
		if (propetryGotType5 == SQUARE_GATHERED2) // if the player has got a clour set the rent will be double
		{
			return DOUBLE_RENT;
		}
		else
		{
			return NORMAL_RENT;
		}
	}
	else if (type == SQUARE_COLOUR6) // if the property type is the same as this square colour
	{
		if (propetryGotType6 == SQUARE_GATHERED3) // if the player has got a clour set the rent will be double
		{
			return DOUBLE_RENT;
		}
		else
		{
			return NORMAL_RENT;
		}
	}
	else if (type == SQUARE_COLOUR7) // if the property type is the same as this square colour
	{
		if (propetryGotType7 == SQUARE_GATHERED2) // if the player has got a clour set the rent will be double
		{
			return DOUBLE_RENT;
		}
		else
		{
			return NORMAL_RENT;
		}
	}
}

// makes a player bankrupt
void CPlayer::MakeBankrupt()
{
	bankrupt = "YES";
}

// returns if a player is bankrupt
string CPlayer::CheckBankrupt()
{
	return bankrupt;
}