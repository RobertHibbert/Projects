#include "CMonopoly.h"

CMonopoly::CMonopoly()
{
	cout << "Welcome to Monopol-ish" << endl;
}

CMonopoly::~CMonopoly()
{
}

// this does everything needed for each players turn
void CMonopoly::PlayerRoll(SmartPtr_CPlayer player, CreateSmartPtr_CSquare square, SmartPtr_CPlayer otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3)
{
	string checkBankrupt = player->CheckBankrupt();
	if (checkBankrupt == "NO") // checks they are not already bankrupt
	{
		int randomNumber = RandomNumber(); // gets a random number
		cout << player->ShowName() << " rolls " << randomNumber << endl;
		int position = player->ChangePosition(randomNumber); // chenages the players position
		player->GoPassed();// checks if they have passed go
		cout << player->ShowName() << " lands on " << *square[position] << endl;

		square[position]->SquareTask(player, square, position, otherplayer, otherplayer2, otherplayer3); // does the square task for the square they have landed on
		cout << player->ShowName() << " has " << POUND << player->ShowMoney() << endl;
	}
}

// this is called at the end of the game to find a winner
void CMonopoly::GameEnd(shared_ptr<CPlayer> player1, shared_ptr<CPlayer> player2, shared_ptr<CPlayer> player3, shared_ptr<CPlayer> player4)
{
	// this displayes how much money each player has
	cout << endl << "Game Over" << endl;
	cout << player1->ShowName() << " has " << POUND << player1->ShowMoney() << endl;
	cout << player2->ShowName() << " has " << POUND << player2->ShowMoney() << endl;
	cout << player3->ShowName() << " has " << POUND << player3->ShowMoney() << endl;
	cout << player4->ShowName() << " has " << POUND << player4->ShowMoney() << endl;

	double player1Money = player1->ShowMoney();
	double player2Money = player2->ShowMoney();
	double player3Money = player3->ShowMoney();
	double player4Money = player4->ShowMoney();
	// this checks if a player has more money then all the other players
	if (player1Money > player2Money && player1Money > player3Money && player1Money > player4Money)
	{
		cout << player1->ShowName() << " wins" << endl; // player wins the game
	}
	else if (player2Money > player1Money && player2Money > player3Money && player2Money > player4Money)
	{
		cout << player2->ShowName() << " wins" << endl; // player wins the game
	}
	else if (player3Money > player1Money && player3Money > player2Money && player3Money > player4Money)
	{
		cout << player3->ShowName() << " wins" << endl; // player wins the game
	}
	else if (player4Money > player1Money && player4Money > player2Money && player4Money > player3Money)
	{
		cout << player4->ShowName() << " wins" << endl; // player wins the game
	}
	else
	{
		cout << "draw" << endl; // no winner and it is a draw
	}
}

// this is called to manage if a player can unmorgage, morgage or even if they are now bankrupt
void CMonopoly::MortagagingManager(SmartPtr_CPlayer player, string decision, CreateSmartPtr_CSquare square)
{
	double money = player->ShowMoney();
	if (decision == "mortgage")
	{
		if (money < NO_MONEY) // if the player has less than no money
		{
			for (int i = 0; i < BOARDSIZE; i++) // goes though each square which will be from the least amount of money to the most
			{
				square[i]->SquareMortagaging(player, decision); // calls a square to try and morgage a property
			}
			money = player->ShowMoney();
			if (money < NO_MONEY) // if they still have less than no money with no more propertys they are now bankrupt
			{
				cout << player->ShowName() << " is Bankrupt." << endl;
				decision = "bankrupt";
				player->MakeBankrupt(); // bankrupt player
				bankruptPlayers++;
				// this will go though the board make it so that others players can now buy them 
				for (int i = 0; i < BOARDSIZE; i++)
				{
					square[i]->SquareMortagaging(player, decision);
				}
			}
		}
	}
	if (decision == "unmortgage") 
	{
		// if they can unmortgage it will attempt to do so from the cheapest to the richest and check if the player can or not in the function
		for (int i = 0; i < BOARDSIZE; i++)
		{
			square[i]->SquareMortagaging(player, decision);
		}
	}
}

// this will return the amount of bankrupt players
int CMonopoly::CheckPlayersLeft()
{
	return bankruptPlayers; // returns the amount of bankrupt player
}