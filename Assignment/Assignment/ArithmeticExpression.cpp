#pragma once
#include <iostream>
#include "ArithmeticExpression.h"

bool operatorCheck(char c) // this checks if the current char is an operator
{
	if (c == '-' || c == '+' || c == '/' || c == '*' || c == '^')
	{
		return true; // returns true if it is an operator
	}
	else
	{
		return false;// returns false if it is not an operator
	}
}

int precedenceCheck(char c) // this gives a precedence to the operators
{
	if (c == '^')
	{
		return 3;
	}
	else if (c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

string infixToPostfix(string theInfix) // turns the infix to postfix
{
	SmartPtrArithmetic stack1 = make_shared <Stack<char>>(); // smart ptr for the stack i am using
	string thePostfix; // holds the postfix
	for (int i = 0; i < theInfix.length(); i++)
	{
		if ((theInfix[i] >= 'a' && theInfix[i] <= 'z') || (theInfix[i] >= 'A' && theInfix[i] <= 'Z')) // in case a letter has been entered then this will be ignored
		{
		}
		else if ((operatorCheck(theInfix[i]) == false) && (theInfix[i] != ')') && (theInfix[i] != '('))   // if it is a number
		{
			if ((operatorCheck(theInfix[i + 1]) == false) && (theInfix[i + 1] != ')') && (theInfix[i + 1] != '(')) // if it is a multi-digit number
			{
				thePostfix = thePostfix + theInfix[i];
			}
			else // if it is a single digit
			{
				thePostfix = thePostfix + theInfix[i] + ' '; // adds a space between number (this is taken away later)
			}
		}
		else if (theInfix[i] == '(') // if it is a (
		{
			stack1->push(theInfix[i]);
		}
		else if (theInfix[i] == ')') // if it is a )
		{
			while ((stack1->top() != '(') && (stack1->isEmpty() == false)) // while the top of the stack is not empty and it has not got a (
			{
				char tempTop = stack1->top();
				thePostfix = thePostfix + tempTop; // adds the top of the stack to the postfix
				stack1->pop();
			}
			if (stack1->top() == '(') // while the top of the stack is not a (
			{
				stack1->pop(); // pop the stack
			}
		}
		else if (operatorCheck(theInfix[i]))// checks if it is an operator
		{
			if (stack1->isEmpty() == true) // if the stacks empty the operator will be pushed onto it
			{
				stack1->push(theInfix[i]);
			}
			else
			{
				if (precedenceCheck(theInfix[i]) > precedenceCheck(stack1->top()))// if the current operator has a higher precedence than the top of the stack
				{
					stack1->push(theInfix[i]);
				}
				else if ((precedenceCheck(theInfix[i]) == precedenceCheck(stack1->top())) && (theInfix[i] == '^'))// if it is a an ^
				{
					stack1->push(theInfix[i]);
				}
				else// if it is less then the top of the stack will be pushed onto the postfix and the current infix will be put on the top of the stack
				{
					while ((stack1->isEmpty() == false) && ( precedenceCheck(theInfix[i]) <= precedenceCheck(stack1->top())))
					{
						thePostfix = thePostfix + stack1->top();
						stack1->pop();
					}
					stack1->push(theInfix[i]);
				}
			}
		}	
	}
	while (stack1->isEmpty() == false) // if the stack is not empty pop it all onto the postfix
	{
		thePostfix = thePostfix + stack1->top();
		stack1->pop();
	}
	return thePostfix;
}

string infixToPrefix(string theInfix) //  this turns the infix into a prefix
{
	SmartPtrArithmetic stack1 = make_shared <Stack<char>>(); // samrt ptr for the stack i am using 
	string thePrefix; // this holds the prefix value
	reverse(theInfix.begin(), theInfix.end()); //this reverses the infix
	for (int i = 0; i < theInfix.length(); i++) // goes though the infix
	{
		if (theInfix[i] == '(') // reverses (
		{
			theInfix[i] = ')';
		}
		else if (theInfix[i] == ')')// reverses )
		{
			theInfix[i] = '(';
		}
	}
	for (int i = 0; i < theInfix.length(); i++) //goes though the infix
	{
		if (theInfix[i] >= 'a' && theInfix[i] <= 'z' || (theInfix[i] >= 'A' && theInfix[i] <= 'Z')) // if a letter has been entered then nothing will happen
		{
		}
		else if ((operatorCheck(theInfix[i]) == false) && (theInfix[i] != ')') && (theInfix[i] != '('))// if it is a number it will add it to the prefix
		{
			thePrefix = thePrefix + theInfix[i];
		}
		else if (theInfix[i] == '(') // if it is a ( it will go onto the stack
		{
			stack1->push(theInfix[i]);
		}
		else if (theInfix[i] == ')') // if it is a )
		{
			while ((stack1->top() != '(') && (stack1->isEmpty() == false)) // if the stack is not empty and the top is not a ( then top of the stack will be popped
			{
				thePrefix = thePrefix + stack1->top();
				stack1->pop();
			}
			if (stack1->top() == '(') // if the top of the stack is a ( it will be popped
			{
				stack1->pop();
			}
		}
		else if (operatorCheck(theInfix[i]))  // checks if it is an operator
		{
			if (stack1->isEmpty() == true) // if the stack is empty it will be pushed onto it
			{
				stack1->push(theInfix[i]);
			}
			else
			{
				if (precedenceCheck(theInfix[i]) > precedenceCheck(stack1->top())) // if it has a higher precedence then it will be pushed onto the stack
				{
					stack1->push(theInfix[i]);
				}
				else if ((precedenceCheck(theInfix[i]) == precedenceCheck(stack1->top())) && (theInfix[i] == '^'))// if it is a ^
				{
					while ((precedenceCheck(theInfix[i]) == precedenceCheck(stack1->top())) && (theInfix[i] == '^'))// pop the stack and add it to the prefix if there is already a ^ on top of the stack
					{
						thePrefix = thePrefix + stack1->top();
						stack1->pop();
					}
					stack1->push(theInfix[i]); // now push the ^ 
				}
				else if (precedenceCheck(theInfix[i]) == precedenceCheck(stack1->top())) // if it is the same precedence as the top of the stack then push it on top
				{
					stack1->push(theInfix[i]);
				}
				else
				{
					while ((stack1->isEmpty() == false) && (precedenceCheck(theInfix[i]) < precedenceCheck(stack1->top())))// if the stack is not empty and the precedence is less
					{
						thePrefix = thePrefix + stack1->top(); // add the top of the stack to the prefix
						stack1->pop(); 
					}
					stack1->push(theInfix[i]); // pushes the current infix value onto the stack
				}
			}
		}
	}
	while (stack1->isEmpty() == false) // if the stack is not empty then add all of the stack onto the prefix
	{
		thePrefix = thePrefix + stack1->top();
		stack1->pop();
	}
	reverse(thePrefix.begin(), thePrefix.end()); // this is now reversed again to get the prefix
	return thePrefix;// this returnes the prefix value
}

int theAnswer(string thePostfix)
{
	SmartPtrAnswer stackint = make_shared <Stack<int>>(); // smart ptr of an int stack to hold the values i push t0 it 
	int newValue = 0; // this holds a new value (the value of the two stack values calculated together)
	int theAnswer = 0; // this holds the full answer
	int currentInt = 0; //  this holds the currnet int
	int nextInt = 0; //this holds the next int if the number is multi-digit
	for (int i = 0; i < thePostfix.length(); i++)// goes though the postfix
	{
		if ((operatorCheck(thePostfix[i]) == false) && (thePostfix[i] != ')') && (thePostfix[i] != '(') && (thePostfix[i] != ' ')) // if the value is an int
		{
			currentInt = thePostfix[i] - '0'; // converts the char value to an int
			stackint->push(currentInt); // then pushes it to the stack
			if ((operatorCheck(thePostfix[i + 1]) == false) && (thePostfix[i + 1] != ')') && (thePostfix[i + 1] != '(') && (thePostfix[i + 1] != ' ')) // if the next value is also an int
			{
				while ((operatorCheck(thePostfix[i + 1]) == false) && (thePostfix[i + 1] != ')') && (thePostfix[i + 1] != '(') && (thePostfix[i + 1] != ' ')) // while the next value is still an int
				{
					currentInt = stackint->pop(); // pops the current value as it is a multi-digit number and atm it is only a single digit number
					nextInt = thePostfix[i + 1] - '0';

					int mergeInt1 = currentInt;
					int mergeInt2 = nextInt;
					int mergeInt2Copy = mergeInt2;
					do // this adds to ints together ( for exaple 1 and 2 will become 12)
					{
						mergeInt1 *= 10;
						mergeInt2Copy /= 10;
					} while (mergeInt2Copy > 0);
					int mergedValue = mergeInt1 + mergeInt2;
					stackint->push(mergedValue); // this new multi-digit value is pushed to the stack
					i++;
				}
			}
		}
		else if (operatorCheck(thePostfix[i])) // checks if it is an operator
		{
			int value1 = stackint->pop();// value on top of the stack
			int value2 = stackint->pop();// value 2nd (now on top) of stack
			
			switch (thePostfix[i]) // depending on what operater it is 
			{
			case '+':
				newValue = value2 + value1; // values added 
				stackint->push(newValue); // then pushed to the stack
				break;
			case '-':
				newValue = value2 - value1;
				stackint->push(newValue);
				break;
			case '*':
				newValue = value2 * value1;
				stackint->push(newValue);
				break;
			case '/':
				newValue = value2 / value1;
				stackint->push(newValue);
				break;
			case '^':
				newValue = pow(value2,value1);
				stackint->push(newValue);
				break;
			}
		}
	}
	theAnswer = stackint->pop(); // the full answer is then popped and returned 
	return theAnswer;
}

string postfixClean (string thePostfix) // this takes the spaces out of the postfix that i added to help me
{
	string newPostfix;
	for (int i = 0; i < thePostfix.length(); i++)
	{
		if (thePostfix[i] == ' ') // if the current value of the costfix is a space then do nothing and it will not be added to the new postfix
		{

		}
		else
		{
			newPostfix = newPostfix + thePostfix[i];
		}
	}
	return newPostfix; // return postfix with no spaces
}

void arithmeticExpression()
{
	string infix; // hods the infix value inputted by the user
	string postfix; // holds the postfix value
	string prefix; // holds the prefix value
	int answer = 0; // this holds the value of the expression
	cout << endl << "Please enter an Infix Expression: " << endl;
	cin.ignore();
	getline(cin,  infix); // this is done if the user wants to enter the infix with spaces (they do not have to)
	cout << endl << "The Infix Expression is: " << infix << endl;

	postfix = infixToPostfix(infix); // calcualtes the postfix
	prefix = infixToPrefix(infix); // clculates the prefix
	answer = theAnswer(postfix); // calculates the result of the math operation
	postfix = postfixClean(postfix); // takes spaces away ( i added them to help with working with multi-digit numbers)
	cout << "The Prefix Expression is: " << prefix << endl;
	cout << "The Postix Expression is: " << postfix << endl;
	cout << "The result of this mathematical operation is: " << answer << endl << endl;
}