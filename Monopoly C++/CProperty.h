#pragma once
#include "CSquare.h"
#include "CMonopoly.h"
class CProperty :
    public CSquare
{
protected:
    string owner = "NO"; // used to see if the property has an owner
    bool mortgaged = false; // used to see if a property is mortgaged or not 
    double squareCost = 0; // cost of square
    double squareRent = 0; // rent of square
    int squareGroup = 0; // colour croup of square
public:
    CProperty(istream& file, int type);
    ~CProperty();
    void SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3); // used when a player lands on a property
    friend istream& operator >> (istream& inputStream, CProperty& property);
    void SquareMortagaging(SmartPtr_CPlayer player, string decision);
};

