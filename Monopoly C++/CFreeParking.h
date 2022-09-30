#pragma once
#include "CSquare.h"

class CFreeParking :
    public CSquare
{
protected:

public:
    CFreeParking(istream& file, int type);
    ~CFreeParking();
    void SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3); // if a player lands on free parking it will run this
    friend istream& operator >> (istream& inputStream, CFreeParking& parking);
    void SquareMortagaging(SmartPtr_CPlayer player, string decision);
};

