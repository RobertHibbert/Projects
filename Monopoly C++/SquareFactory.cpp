#include "SquareFactory.h"
#include "CProperty.h"
#include "CGo.h"
#include "CStation.h"
#include "CBonus.h"
#include "CPenalty.h"
#include "CJail.h"
#include "CGoToJail.h"
#include "CFreeParking.h"

// this creates a new square on the board
SmartPtr_CSquare newSquare(ESquareType square, istream& file, int type)
{
	switch (square)
	{
	case ESquareType::Property: 
	{
		return make_shared <CProperty>(file, type); // creates a property square
		break;
	}
	case ESquareType::Go:
	{
		return make_shared <CGo>(file, type); // creates a go square
		break;
	}
	case ESquareType::Station:
	{
		return make_shared <CStation>(file, type); // creates a station square
		break;
	}
	case ESquareType::Bonus:
	{
		return make_shared <CBonus>(file, type); // creates a bonus square
		break;
	}
	case ESquareType::Penalty:
	{
		return make_shared <CPenalty>(file, type); //craetes a penalty square
		break;
	}
	case ESquareType::Jail:
	{
		return make_shared <CJail>(file, type); // creates a jail square
		break;
	}
	case ESquareType::GoToJail:
	{
		return make_shared <CGoToJail>(file, type); // creates a go to jail square
		break;
	}
	case ESquareType::FreeParking:
	{
		return make_shared <CFreeParking>(file, type); // creates a free parking square
		break;
	}
	}
}