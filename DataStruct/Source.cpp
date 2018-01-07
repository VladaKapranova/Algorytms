#include <stdio.h>
#include <malloc.h>

struct Node
{
	int data;
	Node *prev, *next;
};

void printNode(Node *n)
{
	printf("%i ", n->data);
}

//Стек на массиве

struct StackArr
{
	int data[100000000];
	long int counter;

	StackArr()
	{
		counter = 0;
	}
};

void pushA(int n, StackArr *st)
{
	st->data[st->counter++] = n;
}

int popA(StackArr *st)
{
	int i = st->counter - 1;
	printf("%i\n", st->data[i]);
	return st->data[st->counter--];
}

void printStA(StackArr *st)
{
	for (long int i = 0; i < st->counter; i++)
		printf("%i ", st->data[i]);
	printf("\n");
}

//Стек на списке

struct StackList
{
	Node *end;

	StackList()
	{
		end = nullptr;
	}
};

void pushL(int el, StackList *st)
{
	if (st->end == nullptr)
	{
		st->end = (Node*)malloc(sizeof(Node));
		st->end->data = el;
		st->end->prev = nullptr;
		st->end->next = nullptr;
	}
	else
	{
		st->end->next = (Node*)malloc(sizeof(Node)); // Ошибка!
		st->end->next->prev = st->end;
		st->end->next->next = nullptr;
		st->end->next->data = el;
		st->end = st->end->next;
	}
	printNode(st->end);
}

int popL(StackList *st)
{
	if (st->end == nullptr)
		return -1;
	Node *to_free = (Node*)malloc(sizeof(Node));
	to_free = st->end;
	int ret_val = st->end->data;
	st->end = st->end->prev;
	if (st->end != nullptr)
		st->end->next = nullptr;
	free(to_free);
	printf("%i\n", ret_val);
	return ret_val;
}

//Очередь на списке

struct QueueList
{
	Node *start, *end;
	int data[100];

	QueueList()
	{
		start = end = nullptr;
	}
};

void push_backL(int n, QueueList *q)
{
	if (q->end == nullptr)
	{
		q->start = q->end = (Node*)malloc(sizeof(Node));
		q->start->data = q->end->data = n;
		q->end->prev = nullptr;
		q->end->next = nullptr;
	}
	else
	{
		q->end->next = (Node*)malloc(sizeof(Node));
		q->end->next->prev = q->end;
		q->end = q->end->next;
		q->end->data = n;
		q->end->next = nullptr;
	}
}

int pop_frontL(QueueList *q)
{
	if (q->end == nullptr)
		return -1;
	Node *to_free = (Node*)malloc(sizeof(Node));
	to_free = q->start;
	int a = q->start->data;
	q->start = q->start->next;
	free(to_free);
	q->start->prev = nullptr;
	return a;
}

void printQL(QueueList *q)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node = q->start;

	while (node != q->end)
	{
		printNode(node);
		node = node->next;
	}
	printNode(q->end);
	printf("\n");
}

//Очередь на массиве

struct QueueArr
{
	int data[100000000];
	long int cbegin = 0, cend = 0;
};

void push_backA(int n, QueueArr *q)
{
	if (q->cbegin == 0 && q->cend == 0)
		q->data[q->cend++] = n;
	else if (q->cend == 100000000 - 1)
	{
		q->cend = 0;
		q->cbegin++;
		q->data[q->cend] = n;
	}
	else q->data[q->cend++] = n;
}

int pop_frontA(QueueArr *q)
{
	int ret_val = q->data[q->cbegin];
	if (q->cbegin == 100000000 - 1)
		q->cbegin = 0;
	else q->cbegin++;
	printf("%i\n", ret_val);
	return ret_val;
}

void printQA(QueueArr *q)
{
	if (q->cbegin < q->cend)
	{
		for (long int i = q->cbegin; i < q->cend; i++)
			printf("%i ", q->data[i]);
	}
	else
	{
		for (long int i = q->cbegin; i < 100000000; i++)
			printf("%i ", q->data[i]);
		for (long int i = 0; i < q->cend; i++)
			printf("%i ", q->data[i]);
	}
	printf("\n");
}

void main()
{
	//Стек на массиве
	printf("Stack on array\n");
	StackArr *st_arr = new StackArr;
	pushA(10, st_arr);
	pushA(6, st_arr);
	pushA(21, st_arr);
	pushA(100, st_arr);
	pushA(4, st_arr);
	printStA(st_arr);
	popA(st_arr);
	popA(st_arr);
	printStA(st_arr);
	delete st_arr;

	//Стек на списке
	printf("Stack on list\n");
	StackList *st_l = new StackList;
	pushL(5, st_l);
	pushL(2, st_l);
	pushL(40, st_l);
	pushL(25, st_l);
	printf("\n");
	popL(st_l);
	popL(st_l);
	delete st_l;

	//Очередь на списке
	printf("Queue on list\n");
	QueueList *q_l = new QueueList;
	push_backL(15, q_l);
	push_backL(34, q_l);
	push_backL(8, q_l);
	push_backL(23, q_l);
	printQL(q_l);
	pop_frontL(q_l);
	pop_frontL(q_l);
	printQL(q_l);
	delete q_l;

	//Очередь на массиве
	printf("Queue on array\n");
	QueueArr *q_arr = new QueueArr;
	push_backA(67, q_arr);
	push_backA(34, q_arr);
	push_backA(56, q_arr);
	push_backA(12, q_arr);
	printQA(q_arr);
	pop_frontA(q_arr);
	pop_frontA(q_arr);
	printQA(q_arr);
	delete q_arr;
}