#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <string>
#include "Constants.h"
#include "Stack.cpp"
#include "ArithmeticExpression.h"
#include "NQueen.h"

using namespace std;

int main()
{
	{
		//the user picks if they want to run the Arithmetric Expression code or the NQueen problem.
		string programNumebr;
		cout << "Enter 1 to run Arithmetic Expression or anthing else for NQueen Problem:" << endl;
		cin >> programNumebr;
		if (programNumebr == "1")
		{
			arithmeticExpression();
		}
		else
		{
			nQueenSolution();
		}
		system("pause");
	}
	_CrtDumpMemoryLeaks(); // this checks if there are any memory leaks, the objects are dumped if there are any - my program has no memory leaks
}