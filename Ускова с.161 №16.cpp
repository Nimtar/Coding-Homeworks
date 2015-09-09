// Ускова с.161 №16.cpp : Defines the entry point for the console application.
// Вычислить сумму тех элементов списка, значения которых меньше значениий 
// элементов, непосредственно следующих за ними.

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;



struct list{
	int info;
	list* next;
};

void addRandToList(list*);
void showList(list*);
int solve(list*);
int main()
{
	srand(time(0));

	list* head = new list;
	head->next = NULL;

	int n;
	cout << "How many elements in list would you like?\n";
	cin >> n;
	for (int i = 0; i < n; i++){
		addRandToList(head);
	}
	cout << "\nThe list is\n";
	showList(head);

	cout << endl
		<< "\nThe sum of all elements which are less than its follower is\n"
		<< solve(head);
	delete head;
	_getch();
	return 0;
}

int solve(list* curr){
	int sum = 0;
	while (curr->next->next != NULL){
		curr = curr->next;
		if (curr->info < curr->next->info)
			sum += curr->info;
	}

	return sum;
}
void addRandToList(list* head){
	list* t = new list;
	t->info = rand() % 20 - 10;
	t->next = head->next;
	head->next = t;
	t = 0;
	delete t;
}
void showList(list* curr){
	while (curr->next != NULL){
		curr = curr->next;
		cout << curr->info << ' ';
	}
}
