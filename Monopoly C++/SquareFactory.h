#pragma once

#include "CSquare.h"

//enum class showing number for each square
enum class ESquareType : int
{
	Property = 1,
	Go = 2,
	Station = 3,
	Bonus = 4,
	Penalty = 5,
	Jail = 6,
	GoToJail = 7,
	FreeParking = 8
};

SmartPtr_CSquare newSquare(ESquareType square, istream& file, int type); // creates a new square
