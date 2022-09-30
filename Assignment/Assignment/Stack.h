#pragma once
#include <iostream>
#include <string>
#include "Constants.h"
using namespace std;

template <class T>
class Stack
{
private:
	int element_top; // this is the top element in the stack
	T arr[ARRAY_SIZE]; //5 for no but can be changed dynamicaly 
	T emptyReturn;
public:

	Stack(); // this is my constructor 
	~Stack(); // this is my destructor 

	bool isEmpty(); // checks if the stack is empty 
	void push(T newValue); // pushes to the stack
	T pop(); // pops the top element from the stack
	int size(); // checks the size of the sack
	T top(); // gets the top of the stack
	string ToString(); // converts the contents of the stack to a string
	bool isFull(); // checks if the stack is full
};
typedef shared_ptr<Stack<int>> SmartPtrNqueen;// smart ptr for the nqueen problem
typedef shared_ptr<Stack<int>> SmartPtrAnswer;// smart ptr for the arithmetic expression answer
typedef shared_ptr<Stack<char>> SmartPtrArithmetic;// smart ptr for the arithmetic expression stack