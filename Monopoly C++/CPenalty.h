#pragma once
#include "CSquare.h"
class CPenalty :
    public CSquare
{
protected:

public:
    CPenalty(istream& file, int type);
    ~CPenalty();
    void SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3); // if the player lands on penalty this is called
    friend istream& operator >> (istream& inputStream, CPenalty& penalty);
    void SquareMortagaging(SmartPtr_CPlayer player, string decision);
};

