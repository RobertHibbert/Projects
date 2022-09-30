#pragma once
#include <iostream>
#include <string>
#include "Constants.h"
#include "Stack.cpp"
#include<algorithm>
using namespace std;

bool operatorCheck(char c); // checks if the current value is an operator
int precedenceCheck(char c); // checks the precedence of an operator
string infixToPostfix(string theInfix); // calculates the postfix
string infixToPrefix(string theInfix); // calculates the prefix
int theAnswer(string thePostfix); // calculate the value of the math operation
string postfixClean(string thePostfix); // takes spaces away ( i added them to help with working with multi-digit numbers)
void arithmeticExpression(); // this is called in main and calles the functions to the requirments 