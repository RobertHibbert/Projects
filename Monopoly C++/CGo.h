#pragma once
#include "CSquare.h"
class CGo: 
    public CSquare
{
protected:
   
public:
    CGo(istream& file, int type);
    ~CGo();
    void SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3); /// used when a player lands on go
    friend istream& operator >> (istream& inputStream, CGo& go);
    void SquareMortagaging(SmartPtr_CPlayer player, string decision);
};


