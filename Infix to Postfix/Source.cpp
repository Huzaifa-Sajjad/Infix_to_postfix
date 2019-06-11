#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "Stack.h"
using namespace std;

bool isOperator(char opr)
{
	if (opr == '+' || opr == '-' || opr == '*' || opr == '/')
		return true;
	else
		return false;
}

int precedence(char opr)
{
	if (opr == '*' || opr == '/')
		return 1;
	else
		return 0;
}

bool checkPrecedence(char opr, char opr2)
{
	if (precedence(opr) > precedence(opr2))
		return true;
	else
		return false;
}


void main()
{
	string eq,output;
	char a, b;
	ifstream file ("eqs.txt");
	while (file.good())
	{
		file >> eq;
		Stack s(eq.length());
		for (string::size_type i = 0; i < eq.length(); i++)
		{
			if (!isOperator(eq[i]))
			{
				if (eq[i] == '(')
					s.push(eq[i]);
				else if (eq[i] == ')')
				{
					while (!s.isEmpty())
					{
						a = s.pop();
						if (a == '(')
							break;
						else
							output += a;
					}
				}
				else
					output += eq[i];
			}
			else
			{
				if (s.isEmpty())
					s.push(eq[i]);
				else
				{
					if (checkPrecedence(eq[i],s.valueAtTop()))
						s.push(eq[i]);
					else
					{
						while (!s.isEmpty())
						{
							b = s.pop();
							if (b == '(')
								break;
							else
								output += b;
						}
						s.push(eq[i]);
					}
				}
			}
		}
		while (!s.isEmpty())
			output += s.pop();
		ofstream file1("solution.txt", ios::app);
		file1 << output << endl;
		file1.close();
	}
	system("pause>null");
}

