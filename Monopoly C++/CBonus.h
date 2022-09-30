#pragma once
#include "CSquare.h"

class CBonus :
    public CSquare
{
protected:

public:
    CBonus(istream& file, int type);
    ~CBonus();
    void SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3); // if the player lands on bonus then this is called
    friend istream& operator >> (istream& inputStream, CBonus& bonus);
    void SquareMortagaging(SmartPtr_CPlayer player, string decision);
};

