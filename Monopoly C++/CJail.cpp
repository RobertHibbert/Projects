#include "CJail.h"
CJail::CJail(istream& file, int type) : CSquare(file, type)
{
	file >> *this;
}

CJail::~CJail()
{
}

istream& operator >> (istream& inputStream, CJail& jail)
{
	return inputStream;
}

// if a player lands of jail it will run this and say that they are just visiting
void CJail::SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3)
{
	string name = player->ShowName(); // gets player name
	cout << name << " is just visiting" << endl;
}

void CJail::SquareMortagaging(SmartPtr_CPlayer player, string decision)
{
}