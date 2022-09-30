#pragma once
#include <iostream>
#include "CPlayer.h"
#include <vector>
#include "Functions.h"
using namespace std;


class CSquare
{
protected:
	int squareType = 0;
	string squareName; // holds the full name of the square
	string squareName1;
	string squareName2;
	string squareName3;
public:
	CSquare(istream& file, int type); // used to decide what square it will be 
	virtual~CSquare();
	virtual void SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3) = 0; // does tasks when player land on a square
	virtual void SquareMortagaging(SmartPtr_CPlayer player, string decision)= 0; // used for mortgaging propertys
	friend istream& operator >> (istream& inputStream, CSquare& square);
	friend ostream& operator << (ostream& outputStream, const CSquare& square);
};

typedef vector<shared_ptr<CSquare>> CreateSmartPtr_CSquare;
typedef shared_ptr<CSquare> SmartPtr_CSquare;