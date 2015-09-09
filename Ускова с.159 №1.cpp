// Ускова с.159 №1.cpp : Defines the entry point for the console application.
//
/*
Реализуйте следующие операции для списков без заглавного элемента и с заглавным
элементом:
*инициализация списка;
*добавление элемента в начало списка;
*добавление элемента в конец списка;
*удаление первого вхождения заданного элемента в список;
*переворот списка, то есть такая переустановка ссылок в списке, при которой
элементы списка следуют друг за другом в обратном порядкае;
*печать элементов списка;
*удаление всех элементов списка.
*/

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

struct list
{
	int info;
	list* next;
};

void addToBeginning(list*, int);
void addToEnd(list*&, int);
bool deleteFirstFound(list*, list*, int);
void changeOrder(list*, list*&);
void printList(list*);
void deleteWholeList(list*);

int main()
{
	srand(time(0));

	list* head = new list;
	head->next = NULL;
	int n;
	cout << "\nInput how many elements in list required.\n";
	cin >> n;
	
	addToBeginning(head, rand() % 20);
	cout << "\nThe first element is";
	printList(head);

	list* tail = head->next;
	for (int i = 1; i < n/2; ++i)
	{
		addToBeginning(head, rand() % 20);
	}
	cout << "\n\nAdding in beginning of the list...";
	printList(head);

	for (int i = n / 2; i < n; ++i)
	{
		int value = rand() % 20;
		addToEnd(tail, value);
	}
	cout << "\n\n...and in the end";
	printList(head);

	changeOrder(head, tail);
	
	cout << "\n\nThe list after re-ordering\n";
	printList(head);

	int toDelete;
	cout << "\n\nInput an element to delete\n";
	cin >> toDelete;
	if(!deleteFirstFound(head, tail, toDelete) )
		cout << "\nThere are no such elements in the list\n";
	
	cout << endl;
	printList(head);

	deleteWholeList(head);

	printList(head);
	delete head;
	tail = 0;

	_getch();
	return 0;
}

void addToBeginning(list* head, int value)
{
	list* t = new list;
	t->info = value;
	t->next = head->next;
	head->next = t;
	
	t = 0;
	delete t;
}

void addToEnd(list* &tail, int value)
{
	list* t = new list;
	t->info = value;
	t->next = NULL;
	tail->next = t;
	tail = t;

	t = 0;
	delete t;
}

bool deleteFirstFound(list* head, list* tail, int value)
{
	list* previous = head;
	list* curr = previous->next;
	while (curr != NULL && curr->info != value)
	{
		previous = previous->next;
		curr = curr->next;
	}
	if (curr != NULL)
	{
		previous->next = curr->next;

		if (previous->next == NULL)
			tail = previous;
		delete curr;
		previous = 0;
		return true;
	}
	else
	{
		previous = 0;
		return false;
	}

}

void changeOrder(list* head, list* &tail)
{
	list* prev = head->next;
	list* curr = prev->next;
	list* temp;
	while (curr->next != NULL)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	curr->next = prev;
	tail = head->next;
	tail->next = NULL;
	head->next = curr;

	prev = curr = temp = 0;
	delete prev; delete curr; delete temp;
	
}

void printList(list* head)
{
	list* curr = head->next;
	cout << endl;
	while (curr != NULL)
	{
		cout << ' ' << curr->info << ' ';
		curr = curr->next;
	}

	curr = 0;
	delete curr;
}

void deleteWholeList(list* head)
{
	while (head->next != NULL)
	{
		list* t = head->next;
		head->next = t->next;
		delete t;
	}
}
