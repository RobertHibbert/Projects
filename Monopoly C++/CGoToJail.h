#pragma once
#include "CSquare.h"
class CGoToJail :
    public CSquare
{
protected:

public:
    CGoToJail(istream& file, int type);
    ~CGoToJail();
    void SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3); // if a player runs of go to jail it will run this
    friend istream& operator >> (istream& inputStream, CGoToJail& tojail);
    void SquareMortagaging(SmartPtr_CPlayer player, string decision);
};

