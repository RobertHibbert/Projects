#include "CFreeParking.h"

CFreeParking::CFreeParking(istream& file, int type) : CSquare(file, type)
{
	file >> *this;
}

CFreeParking::~CFreeParking()
{
}

istream& operator >> (istream& inputStream, CFreeParking& parking)
{
	return inputStream;
}

// if a player lands on free parking this will runa nd it will say that the palyer is resting
void CFreeParking::SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3)
{
	string name = player->ShowName();
	cout << name << " is resting" << endl;
}

void CFreeParking::SquareMortagaging(SmartPtr_CPlayer player, string decision)
{
}
