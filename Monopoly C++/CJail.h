#pragma once
#include "CSquare.h"
class CJail :
    public CSquare
{
protected:

public:
    CJail(istream& file, int type);
    ~CJail();
    void SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3); // if a player lands on jail then it will do this
    friend istream& operator >> (istream& inputStream, CJail& jail);
    void SquareMortagaging(SmartPtr_CPlayer player, string decision);
};

