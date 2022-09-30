#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "CSquare.h"
#include "SquareFactory.h"
#include "CPlayer.h"
#include "Constants.h"
#include "Functions.h"
#include "CMonopoly.h"

using namespace std;

int main()
{
	{
		srand(5);
		CreateSmartPtr_CSquare square; // creates a vector 

		ifstream file("monopoly.txt");
		if (file.is_open())
		{
			while (file)
			{
				int type = 0;
				file >> type; // read into the file

				if (type != 0) // if the file is not empty
				{ 
					const auto CSQUARE_FUNCTION = newSquare(ESquareType(type), file, type); // using auto to clean up the code 
					square.push_back(CSQUARE_FUNCTION); // creats a new square on the board
				}
			}
		}
		file.close(); // closes the file 

		SmartPtr_CMonopoly Monopoly = make_shared <CMonopoly>(); // smart pointer of the monopoly manager class
		SmartPtr_CPlayer Player1 = make_shared <CPlayer>("dog"); // creates player 1
		SmartPtr_CPlayer Player2 = make_shared <CPlayer>("car"); // creates player 2
		SmartPtr_CPlayer Player3 = make_shared <CPlayer>("shoe"); // creates player 3
		SmartPtr_CPlayer Player4 = make_shared <CPlayer>("hat"); // creates player 4
	
		for (int i = 0; i < ROUNDS; i++) // loops for 20 rounds
		{
			int playersLeft = Monopoly->CheckPlayersLeft();
			if (playersLeft == MAX_BANKRUPT_PLAYERS)  // checks there is still more than 1 player left in the game
			{
				break; // break becasue there is a winner
			}
			cout << endl;
			Monopoly->PlayerRoll(Player1, square, Player2, Player3, Player4); // player 1 playes their turn
			playersLeft = Monopoly->CheckPlayersLeft(); 
			if (playersLeft == MAX_BANKRUPT_PLAYERS)  // checks there is still more than 1 player left in the game
			{
				break; // break becasue there is a winner
			}
			cout << endl;
			Monopoly->PlayerRoll(Player2, square, Player1, Player3, Player4); // player 2 playes their turn
			playersLeft = Monopoly->CheckPlayersLeft(); 
			if (playersLeft == MAX_BANKRUPT_PLAYERS)  // checks there is still more than 1 player left in the game
			{
				break; // break becasue there is a winner
			}
			cout << endl;
			Monopoly->PlayerRoll(Player3, square, Player1, Player2, Player4); // player 3 playes their turn
			playersLeft = Monopoly->CheckPlayersLeft();  
			if (playersLeft == MAX_BANKRUPT_PLAYERS)  // checks there is still more than 1 player left in the game
			{
				break; // break becasue there is a winner
			}
			cout << endl;
			Monopoly->PlayerRoll(Player4, square, Player1, Player2, Player3); // player 4 playes their turn
		}
		Monopoly->GameEnd(Player1, Player2, Player3, Player4); // checks to see who wins

	}
	_CrtDumpMemoryLeaks();
}

