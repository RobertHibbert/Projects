#pragma once
#include <iostream>
#include "NQueen.h"

int solutionNumber = 0; // this holds the number of solutions 
bool safe(int** board, int x, int y, int n) // this line checks if a possition is safe or not
{
	//this checks if there is already a queen on the same row
	for (int theRow = 0; theRow < x; theRow++)// go though the rows to see if there is already a queen on the row
	{
		if (board[theRow][y] == 1) // if there  is a queen in this spot already
		{
			return false; 
		}
	}
	int row = x;
	int col = y;
	// This checks for a diagonal queen clash going down a row and down a col
	while (row >= 0 && col>=0)// while we are not on the first row/col
	{
		if (board[row][col] == 1)
		{
			return false;
		}
		row--;
		col--;
	}
	row = x;
	col = y;
	// This checks for a diagonal queen clash going back a row and up one col
	while (row >= 0 && col < n)// while we are not on the first row and not at the end of the col
	{
		if (board[row][col] == 1)
		{
			return false;
		}
		row--;
		col++;
	}
	return true; // it will return true if it is safe
}

bool nQueen(SmartPtrNqueen queens, int** board, int x, int n, bool noOfSolutions)
{
	if (queens->size() == n) // this checks if the next possiton is off the board
	{
		if (noOfSolutions == true)
		{
			solutionNumber++; // this counts the amount of solutions 
		}
		return true;
	}
	for (int theCol = 0; theCol < n; theCol++) // this does though each col
	{
		if (safe(board, x, theCol, n)) // checks to see if it is safe
		{
			queens->push(theCol);// pushes the col number were the queen will be 
			board[x][theCol] = 1; // marks queen for safe space check
			if (nQueen(queens, board, x + 1, n, noOfSolutions)) //This calls itself to try to place the rest of the queens
			{
				if (noOfSolutions == true) // if we are cheking for the total number of solutions or not
				{

				}
				else
				{
					return true;
				}
			}
			queens->pop();// this is the backtracking - if no solution the queen position will be taken away from this space 
			board[x][theCol] = 0; // marks as a safe place for safe check
		}
	}
	return false;
}


void nQueenSolution()
{
	SmartPtrNqueen nQueenStack = make_shared <Stack<int>>(); // this is a smart ptr to the stack that will hold the position of thr queens
	int boardSize = 0; // this holds the boardsize for NQueen 
	int vadidityChecks = 1; // this holds the value of the amount of vadidity checks
	bool NoOfSolutionsCheck = true; // if we are checking for the total number of solutions
	bool normalCheck = false; // if we are doing a normal check
	cout << endl << "Please enter the size of the board you would like to check: " << endl;
	cin >> boardSize;
	while (boardSize <= 1)
	{
		vadidityChecks++;
		cout << "Please enter a valid board input!" << endl;
		cin >> boardSize;
	}
	cout << endl << "The Board size you are checking is: " << boardSize << " x " << boardSize << endl << endl;
	int** board = new int* [boardSize]; // creates the rows
	//this next for loop sets out the board and puts a 0 in every position
	for (int i = 0; i < boardSize; i++) // goes though board rows
	{
		board[i] = new int[boardSize]; // each row has the same amount on columns as rows (creates board rows/columns)
		for (int j = 0; j < boardSize; j++) // does though board columns
		{
			board[i][j] = 0; // this sets the spaces in the baord to 0 (empty)
		}
	}
	if (nQueen(nQueenStack, board, 0, boardSize, normalCheck))
	{
		int nextRow = -1; // moves to the next row
		int boardPosition = boardSize - 1;
		for (int i = boardPosition; i >= 0; --i)
		{
			for (int j = boardPosition; j >= 0; --j)
			{
				if (nQueenStack->isEmpty() == false)
				{
					if (nQueenStack->top() == j)
					{
						board[i][j] = 1;
						nQueenStack->pop();
						j = nextRow; // this moves to the next row
					}
					else
					{
						board[i][j] = 0;
					}
				}
				else
				{
					board[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < boardSize; i++) // this goes though the board rows
		{
			for (int j = 0; j < boardSize; j++) // this goes though the board columns 
			{
				if (board[i][j] == 1)
				{
					cout << "Q";
				}
				else
				{
					cout << "-";
				}
				cout << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < boardSize; i++) // this loop resets the board for the number of solutions check
		{
			for (int j = 0; j < boardSize; j++) // does though board columns
			{
				board[i][j] = 0; // this sets the spaces in the baord to 0 (empty)
			}
		}
		cout << endl << "OUTPUT STATISTICS: " << endl;
		nQueen(nQueenStack, board, 0, boardSize, NoOfSolutionsCheck); // this gets the number of total solutions 
		cout << "The number of solutions is: " << solutionNumber << endl ; // this prints the number of total solutions 
		cout << "The number of Validity checks is: " << vadidityChecks << endl << endl; // number of Validity checks
	}
	else // if a solution can not be found 
	{ 
		cout << "FALSE." << endl;
		cout << "A solution for this grid size can not be found" << endl;
	}
	for (size_t i = 0; i < boardSize; i++)
	{
		delete board[i]; // this deletes the board contents, without this i have memory leaks!
	}
	delete[] board;
}