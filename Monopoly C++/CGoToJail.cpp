#include "CGoToJail.h"

CGoToJail::CGoToJail(istream& file, int type) : CSquare(file, type)
{
	file >> *this;

}

CGoToJail::~CGoToJail()
{

}

istream& operator >> (istream& inputStream, CGoToJail& tojail)
{

	return inputStream;
}

// if a player lands on go to jail it will run this and send them to the jail square
void CGoToJail::SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3)
{
	string name = player->ShowName(); // gets player name and stores it in a name varible
	cout << name << " goes to jail" << endl;
	cout << name << " pays " << POUND << JAIL_FEE << endl;
	player->ChangeMoneydown(JAIL_FEE); // takes the jail fee out of the players total
	player->MoveToJail(); // moves the player to the jail square
}

void CGoToJail::SquareMortagaging(SmartPtr_CPlayer player, string decision)
{
}