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
struct Node
{
	Node* prev;
	int info;
	Node* next;
};
struct List
{
	Node* head;
	Node* tail;
};
List* newList();
void initList(List*&, int value);
void addToBeginning(List*&, int);
void addToEnd(List*&, int);
bool deleteFirstFound(List*, int);
void changeOrder(List*);
void printList(List*);
void printListFromEnd(List*);
void deleteList(List*);
int main()
{
	srand(time(0));

	List* list = newList();
	
	int n;
	cout << "\nInput how many elements in list is required.\n";
	cin >> n;
	
	for (int i = 0; i < n / 2; ++i)
		addToBeginning(list, rand() % 20);
	
	cout << "\n\nAdding in beginning of the list...";
	printList(list);
	
	for (int i = n / 2; i < n; ++i)
		addToEnd(list, rand() % 20);
	
	cout << "\n\n...and in the end";
	printList(list);
	
	changeOrder(list);
	
	cout << "\n\nThe list after re-ordering\n";
	printList(list);
	
	int toDelete;
	cout << "\n\nInput an element to delete\n";
	cin >> toDelete;
	if (!deleteFirstFound(list, toDelete))
		cout << "\nThere are no such elements in the list\n";
	
	cout << endl;
	printList(list);
	
	cout << "\n\nTyping from the end:\n";
	printListFromEnd(list);
	
	deleteList(list);
	printList(list);
	delete list;
	
	_getch();
	return 0;
}
void addToBeginning(List* &list, int value)
{
	if (!list)
	{
		initList(list, value);
		return;
	}
	Node* t = new Node;
	t->info = value;
	list->head->prev = t;
	t->next = list->head;
	t->prev = NULL;
	list->head = t;
	t = 0;
	delete t;
}
void addToEnd(List* &list, int value)
{
	if (!list)
	{
		initList(list, value);
		return;
	}
	Node* t = new Node;
	t->info = value;
	t->prev = list->tail;
	t->next = NULL;
	list->tail->next = t;
	list->tail = t;
	t = 0;
	delete t;
}
bool deleteFirstFound(List* list, int value)
{
	if (!list)
		return false;
	Node* curr = list->head;
	while (curr && curr->info != value)
		curr = curr->next;
	if (!curr)
		return false;
	if (curr == list->head){
		if (curr->next){
			list->head = curr->next;
			list->head->prev = NULL;
		}
		else
			list->head = list->tail = NULL;
	}
	else if (curr == list->tail)
	{
		list->tail = curr->prev;
		list->tail->next = NULL;
	}
	else
	{
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
	}
	delete curr;
	return true;
}
void changeOrder(List* list)
{
	if (!list || list->head == list->tail)
		return;
	for (Node* curr = list->head; curr; curr = curr->prev)
		swap(curr->next, curr->prev);
	swap(list->head, list->tail);
}
void printList(List* list)
{
	if (!list) return;
	Node* curr = list->head;
	cout << endl;
	while (curr != NULL)
	{
		cout << ' ' << curr->info << ' ';
		curr = curr->next;
	}
	curr = 0;
	delete curr;
}
void printListFromEnd(List* list)
{
	if (!list) return;
	cout << endl;
	for (Node* k = list->tail; k; k = k->prev)
		cout << ' ' << k->info << ' ';
	cout << endl;
}
void deleteList(List* list)
{
	if (!list) return;
	while (list->head)
	{
		Node* t = list->head;
		list->head = t->next;
		delete t;
	}
	list->tail = list->head = NULL;
}
void initList(List* &list, int value)
{
	list = new List;
	list->head = new Node;
	list->head->info = value;
	list->head->next = list->head->prev = NULL;
	list->tail = list->head;
}
List* newList()
{
	return NULL;
}
