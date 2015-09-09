//Ускова с.165 №1б.
//Реализуйте операции работы со стеком, построенным на основе динамических
//структур
#include <iostream>
#include <conio.h>

using namespace std;

struct Stack
{
	int value;
	Stack* next = NULL;
};

Stack* newStack();
void push(Stack*&, int);
int pop(Stack*&);
void deleteStack(Stack*&);

int main()
{
	Stack* stack = newStack();

	cout << "Input how many elements will be in stack\n";
	int n;
	cin >> n;
	cout << "\n\nNow input " << n << " elements\n";
	int val;
	for (int i = 0; i < n; ++i)
	{
		cin >> val;
		push(stack, val);
	}

	cout << "\nNumbers popped from stack:\n";
	for (int i = 0; i < n; ++i)
	{
		cout << pop(stack) << ' ';
	}

	deleteStack(stack);
	delete stack;

	_getch();
	return 0;
}

Stack* newStack()
{
	return NULL;
}

void push(Stack* &top, int newValue)
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

int pop(Stack* &top)
{
	int retValue = top->value;
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
