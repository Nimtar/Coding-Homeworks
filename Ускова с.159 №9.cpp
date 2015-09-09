/*
Пусть дан упорядоченный список названий книг. Необходимо добавить информацию
о новой книге, сохранив упорядоченность списка.
*/

#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>
using namespace std;

struct Node
{
	Node* prev;
	string info;
	Node* next;
};
struct List
{
	Node* head;
	Node* tail;
};

List* newList();
void initList(List*&);

void addToBeginning(List*&, string);
void addToEnd(List*&, string);
void printList(List*);
void deleteList(List*);
void insertInList(List*&, string);

void main()
{
	List* list = newList();
	initList(list);
	printList(list);
	
	cout << "\nEnter the name of book to insert\n";
	string newName;
	getline(cin, newName);
	
	insertInList(list, newName);
	printList(list);

	deleteList(list);
	delete list;
	_getch();
}
void addToBeginning(List* &list, string value)
{
	if (!list)
	{
		initList(list);
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

void addToEnd(List* &list, string value)
{
	if (!list)
	{
		initList(list);
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

void printList(List* list)
{
	if (!list) return;
	Node* curr = list->head;
	cout << endl;
	while (curr != NULL)
	{
		cout << ' ' << curr->info << endl;
		curr = curr->next;
	}
	curr = 0;
	delete curr;
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

void insertInList(List* &list, string value)
{
	Node* it = list->head;
	while (it && it->info < value)
		it = it->next;
	
	if (!it)
		addToEnd(list, value);
	else if (it->info == value)
		cout << "\nThe element is already in the list.\n";
	else if (it->info == list->head->info)
		addToBeginning(list, value);
 
	else
	{
		Node* q = new Node;
		q->info = value;
		q->prev = it->prev;
		q->next = it;
		q->prev->next = q;
		q->next->prev = q;
	}


}

void initList(List* &list)
{
	list = new List;
	list->head = new Node;
	list->head->info = "A Doll's House";
	list->head->next = list->head->prev = NULL;
	list->tail = list->head;
	addToEnd(list, "Anna Karenina");
	addToEnd(list, "Beloved");
	addToEnd(list, "Children of Gebelawi");
	addToEnd(list, "Crime and Punishment");
	addToEnd(list, "Dead Souls");
	addToEnd(list, "Demons");
	addToEnd(list, "Epic of Gilgamesh");
	addToEnd(list, "Fairy tales");
	addToEnd(list, "Gargantua and Pantagruel");
	addToEnd(list, "Iliad");
	addToEnd(list, "Leaves of Grass");
	addToEnd(list, "Lolita");
	addToEnd(list, "Sleepy");
	addToEnd(list, "The Brothers Karamazov");
	addToEnd(list, "The Death of Ivan Ilyich");
	addToEnd(list, "The Idiot");
	addToEnd(list, "War and Peace");
}

List* newList()
{
	return NULL;
}
