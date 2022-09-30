#include "CGo.h"

CGo::CGo(istream& file, int type) : CSquare(file, type)
{
	file >> *this;
}

CGo::~CGo()
{	
}

istream& operator >> (istream& inputStream, CGo& go)
{
	return inputStream;
}

void CGo::SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3)
{
}

void CGo::SquareMortagaging(SmartPtr_CPlayer player, string decision)
{
}