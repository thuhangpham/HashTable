#include<iostream>
using namespace std;
#define max 50
#define m 13
int HashFuntion(int x)
{
	return x % m;
}
int ReHashFuntion(int i, int x)
{
	return (HashFuntion(x) + i) % m;
}
void Init(int HashTable[], int n)
{
	for (int i = 0; i < n; i++)
		HashTable[i] = -1;
}
void AddItem(int HashTable[], int n, int x)
{
	int index;
	int i = 0;
	while (i < n)
	{
		index = ReHashFuntion(i, x);
		if (HashTable[index] == x)
			break;
		if (HashTable[index] == -1)
		{
			HashTable[index] = x;
			break;
		}
		i++;
	}
}
int SearchItem(int HashTable[], int x)
{
	int index = HashFuntion(x);
	if (HashTable[index] == x)
		return index;
	int i = 1;
	while (i<max)
	{
		if (HashTable[index] == x)
			return index;
		index = ReHashFuntion(i, x);
		i++;
	}
	return -1;
}
void RemoveItem(int HashTable[], int x)
{
	int index;
	int i = 0;
	while (i < max)
	{
		index = ReHashFuntion(i, x);
		if (HashTable[index] == x)
		{
			HashTable[index] = -1;
			break;
		}
		i++;
	}
}
int main()
{
	int HashTable[max];
	int n = 13;
	Init(HashTable, n);
	AddItem(HashTable,n, 17);
	AddItem(HashTable,n, 2);
	AddItem(HashTable,n, 4);
	AddItem(HashTable,n, 25);
	AddItem(HashTable,n, 54);
	AddItem(HashTable,n, 9);
	AddItem(HashTable,n, 78);
	AddItem(HashTable,n, 12);
	AddItem(HashTable,n, 7);
	AddItem(HashTable,n, 11);
	AddItem(HashTable,n, 67);
	AddItem(HashTable,n, 68);
	RemoveItem(HashTable, 11);
	cout << endl << SearchItem(HashTable, 12) << endl;
 
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << HashTable[i] << "  ";
	
	system("pause");
	return 0;
}