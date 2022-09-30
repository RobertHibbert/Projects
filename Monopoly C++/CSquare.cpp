#include "CSquare.h"

CSquare::CSquare(istream& file, int type)
{
	squareType = type;
	file >> *this; // i have told in the lecture i can use this for 70% plus
}

CSquare::~CSquare()
{
}

//this code is used to decide what square somthing will be 
istream& operator >> (istream& inputStream, CSquare& square)
{
	if (square.squareType == 1 || square.squareType == 3 || square.squareType == 8)
	{
		inputStream >> square.squareName1;
		inputStream >> square.squareName2;
		square.squareName = square.squareName1 + " " + square.squareName2;// creates the full name of square
	}
	if (square.squareType == 2 || square.squareType == 4 || square.squareType == 5 || square.squareType == 6)
	{
		inputStream >> square.squareName1;
		square.squareName = square.squareName1;// creates the full name of square
	}
	if (square.squareType == 7)
	{
		inputStream >> square.squareName1;
		inputStream >> square.squareName2;
		inputStream >> square.squareName3;
		square.squareName = square.squareName1 + " " + square.squareName2 + " " + square.squareName3;// creates the full name of square
	}
	return inputStream;
}

ostream& operator << (ostream& outputStream, const CSquare& square)
{
	outputStream << square.squareName;
	return outputStream;
}





