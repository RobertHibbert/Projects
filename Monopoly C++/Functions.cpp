#pragma once
#include "Functions.h"

int RandomNumber()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1); // creates a random number for the die roll
}

