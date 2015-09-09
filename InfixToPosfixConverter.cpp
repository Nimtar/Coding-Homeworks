#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
struct Stack
{
	char value;
	Stack* next = NULL;
};
Stack* newStack();
void push(Stack*&, char);
char pop(Stack*&);
void deleteStack(Stack*&);
bool isOperator(char c);
int priority(char c);
int main()
{
	cout << "Please input an expression which you want to convert into postfix form\n"
		"Note you can omit multiplication sign between number and variable\n"
		"In the very end write equal sign \"=\"\n";
	Stack* stack = newStack();
	string postfix = "";
	char c;
	do
	{
		string number = "";
		string variable = "";
		cin.get(c);

		while (isdigit(c))
		{
			number += c;
			cin.get(c);
		}

		while (isalpha(c) )
		{
			number += c;
			cin.get(c);
		}
		if (number != "")
			number += ' ';
		postfix += number;

		if (c == '(')
			push(stack, c);

		if (c == ')')
		{
			while (stack && stack->value != '(')
				postfix = postfix + pop(stack) + ' ';
			pop(stack); //Pop an opening bracket
		}
		
		
		if (isOperator(c))
		{
			while (stack && stack->value != '('
				&& priority(stack->value) > priority(c)
				)
			{
				postfix = postfix + pop(stack) + ' ';
			}
			push(stack, c);
		}
	} while (c != '=');

	while (stack)
		postfix = postfix + pop(stack) +' ';

	cout << endl << postfix;
	_getch();
	return 0;
}



Stack* newStack()
{
	return NULL;
}

void push(Stack* &top, char newValue)
{
	if (!top)
	{
		top = new Stack;
		top->value = newValue;
		return;
	}
	Stack* newTop = new Stack;
	newTop->value = newValue;
	newTop->next = top;
	top = newTop;
	newTop = NULL;
	delete newTop;
}

char pop(Stack* &top)
{
	char retValue = top->value;
	Stack* t = top;
	top = top->next;
	delete t;
	return retValue;
}

void deleteStack(Stack* &top)
{
	while (top){
		Stack* t = top;
		top = top->next;
		delete t;
	}
}

bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '/' || c == '*';
}

int priority(char c)
{
	if (c == '/' || c == '*')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	return 0;
}
