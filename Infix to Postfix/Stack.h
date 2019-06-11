#pragma once
class Stack
{
private:
	char *ptr;
	int size, top;
public:
	Stack(int);
	~Stack();
	bool isEmpty();
	bool isFull();
	void push(char);
	char pop();
	int topValue();
	char valueAtTop();
	void display();
};