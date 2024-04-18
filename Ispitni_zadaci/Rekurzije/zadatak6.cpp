#include <iostream>
using namespace std;

void fibo(int*, int, int);
void ispis(int*, int);
float srednja(int);
void sort(int* niz, int vel);

int main()
{
	const int vel = 20;
	int* niz = new int[vel];

	fibo(niz, vel,0);
	ispis(niz, vel);
	cout << "Niz sortiran uzlazno po srednjoj cifri je: " << endl;
	sort(niz, vel);
	ispis(niz, vel);

	delete[]niz;
	niz = nullptr;
	
	system("pause>0");
	return 0;
}
void ispis(int niz[])
{
	for (int i = 0; i < x; i++)
	{
		cout << niz[i]; << endl;
	}
}
void fibo(int* niz, int vel, int brojac = 0)
{
	if (brojac == vel)
		return;
	if (brojac == 0 || brojac == 1)
		*(niz + brojac) = 1;
	else
		*(niz + brojac) = *(niz + brojac - 1) + *(niz + brojac - 2);
	fibo(niz, vel, brojac + 1);
}
float srednja(int broj)
{
	int brojac = log10(broj) + 1;
	if (brojac % 2 != 0)
	{
		broj /= pow(10, brojac / 2);
		return broj % 10;
	}
	else
	{
		broj /= pow(10, (brojac / 2) - 1);
		int temp = broj % 10;
		broj /= 10;
		temp += broj % 10;
		return temp / float(2);
	}
}
void sort(int* niz, int vel)
{
	bool zastava;
	do
	{
		zastava = false;
		for (int i = 0; i < vel - 1; i++)
		{
			if (srednja(niz[i]) > srednja(niz[i + 1]))
			{
				zastava = true;
				int temp = niz[i];
				niz[i] = niz[i + 1];
				temp = niz[i + 1];
			}
		}
	} while (zastava);
	ispis(niz);
}