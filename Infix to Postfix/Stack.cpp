#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(int arraySize)
{
	ptr = new char[arraySize];
	size = arraySize;
	top = -1;
}

bool Stack::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

bool Stack::isFull()
{
	if (top >= size - 1)
		return true;
	else
		return false;
}

void Stack::push(char value)
{
	if (!isFull())
		ptr[++top] = value;
	else
		cout << "\n\t***Stack is Full***";
}

char Stack::pop()
{
	if (!isEmpty())
		return ptr[top--];
	else
		cout << "\n\t***Stack is Empty***";
}

int Stack::topValue()
{
	return top;
}

void Stack::display()
{
	cout << "\n{";
	for (int val = 0; val <= top; val++)
		cout << ptr[val] << " ";
	cout << "}";
}

char Stack::valueAtTop()
{
	return ptr[top];
}

Stack::~Stack()
{
	ptr = NULL;
	delete ptr;
}