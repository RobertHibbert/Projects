#include "CProperty.h"

CProperty::CProperty(istream& file, int type) : CSquare(file, type)
{
	file >> *this;
}

CProperty::~CProperty()
{

}

// this gets the details for the property from the file
istream& operator >> (istream& inputStream, CProperty& property)
{
	inputStream >> property.squareCost;
	inputStream >> property.squareRent;
	inputStream >> property.squareGroup;
	return inputStream;
}

// this does all the tasks needed when a player lands on a property
void CProperty::SquareTask(SmartPtr_CPlayer player, vector<shared_ptr<CSquare>> square, int position, shared_ptr<CPlayer> otherplayer, SmartPtr_CPlayer otherplayer2, SmartPtr_CPlayer otherplayer3)
{
	SmartPtr_CMonopoly Monopoly = make_shared <CMonopoly>(); // creats an instance of the monopoly class
	string name = player->ShowName(); // stores the current players name
	string player2 = otherplayer->ShowName(); // stores name of other players
	string player3 = otherplayer2->ShowName();// stores name of other players
	string player4 = otherplayer3->ShowName();// stores name of other players
	string mortgage = "mortgage"; 
	string unmortgage = "unmortgage";
	Monopoly->MortagagingManager(player, mortgage, square); // checks if player needs to mortgage a property
	Monopoly->MortagagingManager(player, unmortgage, square); //  checks if a player can unmortgage any propertys
	// if the property has bo owner then the player will buy it if they have the funds
	if (owner == "NO")
	{
		double money = player->ShowMoney();
		if (money > NO_MONEY) // if they have the money
		{
			owner = name;
			cout << name << " buys " << *square[position] << " for " << POUND << squareCost << endl;
			player->ChangeMoneydown(squareCost);
			player->AddProperty(squareGroup);
		}	
	}
	// if they already own the property then nothing will happen
	else if (owner == name)
	{
	}
	// if it is owned by a nother player then it will check if it is mortgaged and then send the money if not
	else 
	{
		if (mortgaged == false) // checks the property is not mortgaged
		{
			if (player2 == owner)
			{
				double rentTimes = otherplayer->CheckOwnership(squareGroup); // checks if the other player has the set of the current colour 
				double rent = (squareRent * rentTimes);
				player->ChangeMoneydown(rent); // takes moneyof the current player
				otherplayer->ChangeMoneyup(rent); // gives money to the owner
				cout << name << " pays " << POUND << rent << endl;
			}
			else if (player3 == owner)
			{
				double rentTimes = otherplayer2->CheckOwnership(squareGroup);// checks if the other player has the set of the current colour 
				double rent = (squareRent * rentTimes);
				player->ChangeMoneydown(rent); // takes moneyof the current player
				otherplayer2->ChangeMoneyup(rent); // gives money to the owner
				cout << name << " pays " << POUND << rent << endl;
			}
			else if (player4 == owner)
			{
				double rentTimes = otherplayer3->CheckOwnership(squareGroup);// checks if the other player has the set of the current colour 
				double rent = (squareRent * rentTimes);
				player->ChangeMoneydown(rent); // takes moneyof the current player
				otherplayer3->ChangeMoneyup(rent); // gives money to the owner
				cout << name << " pays " << POUND << rent << endl;
			}
		}
	}
	Monopoly->MortagagingManager(player, mortgage, square); // checks if player needs to mortgage a property
}

// this mortgages/ unmortgages propertys
void CProperty::SquareMortagaging(SmartPtr_CPlayer player, string decision)
{
	string name = player->ShowName();
	double money = player->ShowMoney();
	if (name == owner) // checks that the player has the property
	{
		if (mortgaged == false) //checks its not mortgaged
		{
			if (decision == "mortgage") //if its trying to mortgage the property
			{
				if (money < NO_MONEY) // checks they have less then no money
				{
					player->ChangeMoneyup(squareCost); //gives the player the mortagage amount
					mortgaged = true; // mortgage property
				}
			}
		}

		if (mortgaged == true) // checks theproperty is already ortgaged
		{
			if (decision == "unmortgage") // checks the player wants to unmortgage it
			{
				money = money - squareCost;
				if (money > NO_MONEY) // checks the player will have more than no money after the money is taken out
				{
					player->ChangeMoneydown(squareCost); // takes the money away
					mortgaged = false; // unmortgage property
				}
			}
		}

		// if the player needs to be made bankrupt then this will happen
		if (decision == "bankrupt")
		{
			owner = "NO"; // the property now has no owner - 'other players can now buy it'
			mortgaged = false; // the property is no longer mortgaged
		}
	}
}



