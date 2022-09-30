#pragma once
#include "CSquare.h"
class CStation :
    public CSquare
{
protected:
    string owner = "NO"; // stores the owner of the station
    double squareCost = STATION_COST; // stores the cost od the station
    double squareFee = STATION_FEE; // stores the station fee
public:
    CStation(istream& file, int type);
    ~CStation();
    void SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3); // used when a player lands on a station
    friend istream& operator >> (istream& inputStream, CStation& station);
    void SquareMortagaging(SmartPtr_CPlayer player, string decision);
};

