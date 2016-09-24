// Nối kết trực tiếp
// Dùng ds liên kết
#include<iostream>
using namespace std;
typedef int data;
struct node
{
	data info;
	node *next;
};
typedef struct list
{
	node *Head, *Tail;
}LINKLIST;
int EmptyList(LINKLIST l)
{
	if (l.Head == NULL)
		return 1;
	return 0;
}
node *GetNode(data x)
{
	node *p = new node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->next = NULL;
	return p;
}
void InitList(LINKLIST &l)
{
	l.Head = l.Tail = NULL;
}
void AddFirst(LINKLIST &l, node *p)
{
	if (EmptyList(l))
		l.Head = l.Tail = p;
	else
	{
		p->next = l.Head;
		l.Head = p;
	}
}
void AddLast(LINKLIST &l, node *p)
{
	if (EmptyList(l))
		l.Head = l.Tail = p;
	else
	{
		l.Tail->next = p;
		l.Tail = p;
	}
}
// Them p sau q
void AddNode(LINKLIST &l, node *p, node *q)
{
	if (EmptyList(l))
		return;
	else
	{
		q->next = p->next;
		q->next = p;
		if (l.Tail == q)
			l.Tail = p;
	}
}
void DelFirst(LINKLIST &l)
{
	if (EmptyList(l))
		return;
	node *p = l.Head;
	if (l.Head == l.Tail)
		l.Head = l.Tail = NULL;
	else
		l.Head = l.Head->next;
	delete p;
}
void DelLast(LINKLIST &l)
{
	if (EmptyList(l))
		return;
	node *p = l.Tail;
	if (l.Head == l.Tail)
		l.Head = l.Tail = NULL;
	else
	{
		while (p->next)
			p = p->next;
		p->next = NULL;
		l.Tail = p;
	}
	delete p;
}
// Huy phan tu sau q
void DelNode(LINKLIST &l, node *q)
{
	if (EmptyList(l))
		return;
	else
	{
		node *p = q->next;
		if (p == NULL)
			return;
		q->next = p->next;
		if (l.Tail == p)
			l.Tail = q;
		delete p;
	}
}
int SearchNode(LINKLIST l, data x)
{
	node *p = l.Head;
	while (p)
	{
		if (p->info == x)
			return 1;
		p = p->next;
	}
	return 0;
}
int HashFuntion(int x)
{
	return x % 11;
}
void AddItem(LINKLIST HashTable[], int x)
{
	int index = HashFuntion(x);
	AddLast(HashTable[index], GetNode(x));
}
int SearchItem(LINKLIST HashTable[], int x)
{
	int index = HashFuntion(x);
	return SearchNode(HashTable[index], x);
}
int main()
{
	LINKLIST HashTable[11];
	for (int i = 0; i < 11; i++)
	{
		InitList(HashTable[i]);
	}
	AddItem(HashTable, 17);
	AddItem(HashTable, 2);
	AddItem(HashTable, 4);
	AddItem(HashTable, 25);
	AddItem(HashTable, 54);
	AddItem(HashTable, 9);
	AddItem(HashTable, 78);
	AddItem(HashTable, 12);
	AddItem(HashTable, 7);
	AddItem(HashTable, 11);
	AddItem(HashTable, 67);

	int i = 0;
	for (int i = 0; i < 11; i++)
	{
		node *p = HashTable[i].Head;
		while (p)
		{
			cout << p->info << "  ";
			p = p->next;
		}
	}
	cout << endl << SearchItem(HashTable, 0) << endl;
	system("pause");
	return 0;
}
