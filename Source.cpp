//Щепітки Соломії
//Варіант 23
//lab_12.2 рек.
#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void Enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* first);
int negative(Elem* L, int count);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Elem* first = NULL,
		* last = NULL;

	Info info, N;

	do
	{
		cout << "Введіть кількість елементів списку: "; cin >> N;
	} while (N < 0);

	for (int i = 0; i < N; i++)
	{
		cout << "Введіть дані: "; cin >> info;
		Enqueue(first, last, info);
	}

	cout << "Елементи списку: ";
	Print(first); cout << endl;

	cout << "Кількість від'ємних елементів: " << negative(first, 0) << endl;
	return 0;
}
void Enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;

	last = tmp;
	if (first == NULL)
		first = tmp;
}

void Print(Elem* L)
{
	if (L != NULL)
	{
		cout << L->info << " ";
		return Print(L->link);
	}
}
int negative(Elem* L, int count)
{
	if (L->info < 0)
		count++;

	L = L->link;
	if (L != NULL)
	{
		return negative(L, count);
	}
	else {
		return count;
	}
}
