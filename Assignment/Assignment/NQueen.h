#pragma once
#include <iostream>
#include <string>
#include "Constants.h"
#include "Stack.cpp"
using namespace std;

bool safe(int** board, int x, int y, int n); // this checks if a possition is safe to place a queen
bool nQueen(SmartPtrNqueen queens, int** board, int x, int n, bool noOfSolutions); // nqueen code - backtracking with the stack
void nQueenSolution(); // this is called from main and calles the functions to do the NQueen requirments 