#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CPlayer.h"
#include "CSquare.h"
#include "Functions.h"
using namespace std;

class CMonopoly
{
protected:
	int bankruptPlayers = 0; // stores the amount of bankrupt players
public:
	CMonopoly();
	~CMonopoly();
	void PlayerRoll(SmartPtr_CPlayer player, CreateSmartPtr_CSquare square, SmartPtr_CPlayer otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3); // every player roll this is called
	void GameEnd(shared_ptr<CPlayer> player1, shared_ptr<CPlayer> player2, shared_ptr<CPlayer> player3, shared_ptr<CPlayer> player4); // this is called at the end of the game
	void MortagagingManager(SmartPtr_CPlayer player, string decision, CreateSmartPtr_CSquare square); // this is used to manage morgages
	int CheckPlayersLeft(); //this checks the amount to players left in the game
};
typedef shared_ptr<CMonopoly> SmartPtr_CMonopoly;

