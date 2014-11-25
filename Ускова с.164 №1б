// Ускова с.164 №1б
// Реализуйте операции работы с очередью, построенной на основе
// динамических структур
#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

struct Node
{
	int value;
	Node* next = NULL;
};
struct Queue
{
	Node* head = NULL;
	Node* tail = NULL;
};

Queue* newQueue();
int pop(Queue*);
int pop(Node*&);
void push(Queue*, int);
void push(Node*&, int);
bool isEmpty(Queue* queue);

int main()
{
	srand(time(0));
	int n;
	cout << "How many numbers should be in queue?\n";
	cin >> n;

	Queue* queue = new Queue();
	for (int i = 0; i < n; ++i)
	{
		push(queue, rand()%20);
	}

	while (!isEmpty(queue))
	{
		cout << pop(queue) << ' ';
	}
	cout << "\nThe queue is empty: " << (isEmpty(queue) ? "true" : "false");
	_getch();
	return 0;
}

void push(Queue* queue, int value)
{
	if (!queue->head)
	{
		queue->head = new Node;
		queue->tail = queue->head;
		queue->head->value = value;
		return;
	}
	push(queue->tail, value);
}

void push(Node* &tail, int value)
{
	tail->next = new Node;
	tail = tail->next;
	tail->value = value;
}

int pop(Queue* queue)
{
	return pop(queue->head);
}

int pop(Node*& head)
{
	int retValue = head->value;
	Node* t = head;
	head = head->next;
	delete t;
	return retValue;
}

bool isEmpty(Queue* queue)
{
	return !queue->head;
}

void deleteQueue(Queue* queue)
{
	while (!isEmpty(queue))
	{
		pop(queue->head);
	}
}
