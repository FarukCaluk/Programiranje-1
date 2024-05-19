/*Kreirati jednodim dinam niz n velicine i napuniti ga serijom kubova svakog proslog broja pocevsi od 2. 
Prekida se kada se deesi overflow, napuni niz.Ispisati niz rekurzivno!*/
#include <iostream>
using namespace std;

void rekurzija(int* niz, int vel, int brojac = 0)
{
	if (brojac == vel)
		return;
	if (brojac == 0)
		*(niz + brojac) = 2;
	if (brojac > 0) 
	{
		int temp = pow(*(niz + brojac - 1), 3);
		if (temp < 0)
			return;
		*(niz + brojac) = temp;
	}
	rekurzija(niz, vel, brojac + 1);
}
int main()
{
	int vel;
	do
	{
		cout << "---------------------------|" << endl;
		cout << "Unesite velicinu niza : ";
		cin >> vel;
		cout << "---------------------------|" << endl;
	} while (vel < 2);
	int* niz = new int[vel];
	rekurzija(niz, vel);

	for (int i = 0; i < vel; i++)
	{
		cout << *(niz + i) << endl;
		cout << "----------|" << endl;
	}

	delete[]niz;
	niz = nullptr;

	system("pause>0");
	return 0;
}