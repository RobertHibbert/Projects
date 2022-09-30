#pragma once
#include <iostream>
#include "Stack.h"

template <class T>
Stack<T>::Stack()
{
	element_top = -1;
}

template <class T>
Stack<T>::~Stack()
{
	//delete[] arr;
}

template <class T>
bool Stack<T>::isEmpty()// checks if the stack is empty 
{
	if (element_top == STACK_BOTTOM)  // if the top element is equal to the bottom of the stack value 
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool Stack<T>::isFull() // checks if the stack is full
{
	if (element_top == STACK_TOP) // if the top element is is the same as the max stack value
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void Stack<T>::push(T newValue) // pushes an element to the top of the stack
{
	if (isFull()) // if the stack is full
	{
		cout << "There is a stack overflow" << endl;
	}
	else
	{
		element_top++;
		arr[element_top] = newValue;
	}
}

template <class T>
T Stack<T>::pop() // pops the top element of the stack
{
	if (isEmpty()) // checks if the stack is empty
	{
		cout << "The stack is empty" << endl;
		return emptyReturn;
	}
	else
	{
		T value_pop = arr[element_top];
		element_top--;
		return value_pop; // this retruns the value that has just been popped
	}
}

template <class T>
int Stack<T>::size() // gets the size of the stack
{
	return (element_top + 1); // this returns the number of elements in the stack
}

template <class T>
T Stack<T>::top() // returns the top element in the stack
{
	if (isEmpty())// checks if the stack is empty
	{
		cout << "The stack is empty" << endl;
		return emptyReturn;
	}
	else
	{
		return arr[element_top];// returns the top element in the stack
	}
}

template <class T>
string Stack<T>::ToString()// converts the contents of the stack to a string
{
	if (isEmpty())// checks if the stack is empty
	{
		return "Empty stack!";
	}
	else
	{
		string contents;
		for (int i = 0; i <= element_top; i++) // goes though the stack
		{
			contents += arr[i];
		}
		return contents;// returns the contents of the stack
	}
}
