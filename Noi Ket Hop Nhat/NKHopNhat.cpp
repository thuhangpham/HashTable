// Noi ket hop nhat
// tim kiem va xoa
#include<iostream>
using namespace std;
#define max 50
struct Item
{
	int key;
	int next;
};
void Init(Item HashTable[], int n)
{
	for (int i = 0; i < n; i++)
	{
		HashTable[i].key = -1;
		HashTable[i].next = -1;
	}
}
int HashFuntion(int key)
{
	return key % 11;
}
void AddItem(Item HashTable[], int x, int n)
{
	int index = HashFuntion(x);
	if (HashTable[index].key == -1)
		HashTable[index].key = x;
	else
	{
		int p = index, v = n - 1;
		// Tim vi tri ben phai. tra ve vi tri truoc do.
		while (HashTable[p].next != -1)
			p = HashTable[p].next;
		// Tim vi tri trong -> day x vao.
		while (HashTable[v].key != -1)
			v--;
		HashTable[p].next = v;
		HashTable[v].key = x;
	}
}
int SearchItem(Item HashTable[], int n, int x)
{
	int index = HashFuntion(x);
	if (index > n)
		return 0;
	if (HashTable[index].key == x)
		return index;
	else if (HashTable[index].next == -1)
		return 0;
	int p = HashTable[index].next;
	while (true)
	{
		if (HashTable[p].key != x && HashTable[p].next == -1)
			return 0;
		else if (HashTable[p].key == x)
			return p;
		p = HashTable[p].next;
	}
	return 0;
}
void RemoveItem(Item HashTable[], int n, int x)
{
	int q = SearchItem(HashTable, n, x);
	if (!q)
		return;
	int index = q;
	int p = HashTable[index].next;
	do
	{
		// p là next mới cho mỗi lần lặp.
		HashTable[index].key = HashTable[p].key;
		// Thay index mới.
		index = p;
		p = HashTable[p].next;
	} while (p != -1);
	// Reset dữ liệu.
	HashTable[index].key = -1;
	// reset next ke cuoi.
	while (HashTable[HashTable[q].next].next != -1)
		q = HashTable[q].next;
	HashTable[q].next = -1;
}
int main()
{
	Item HashTable[max];
	int n = 11;
	Init(HashTable, n);
	AddItem(HashTable, 17, n);
	AddItem(HashTable, 2, n);
	AddItem(HashTable, 4, n);
	AddItem(HashTable, 25, n);
	AddItem(HashTable, 54, n);
	AddItem(HashTable, 9, n);
	AddItem(HashTable, 78, n);
	AddItem(HashTable, 12, n);
	AddItem(HashTable, 7, n);
	AddItem(HashTable, 11, n);
	AddItem(HashTable, 67, n);
	RemoveItem(HashTable, n, 12);
	for (int i = 0; i < n; i++)
		cout << HashTable[i].key << "  ";
	system("pause");
	return 0;
}