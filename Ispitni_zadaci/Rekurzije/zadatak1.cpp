/*omogu�iti korisniku da unese veli�inu n jednodimenzionalnog dinami�kog niza integer vrijednosti (n > 2). Napisati rekurzivnu funkciju koja 
�e taj niz puniti serijom brojeva tako da je svaki sljede�i broj jednak umno�ku dva prethodna broja, a prva dva elementa su 1 i 3 
(1, 3, 3, 9, 27, ...).Zatim napraviti drugu rekurzivnu funkciju koja �e izra�unati zbir svih elemenata tog niza (voditi ra�una o 
tipu podatka zbog veli�ine broja).*/
#include <iostream>
using namespace std;

void rekurzija(int* niz, int vel, int brojac = 0)
{
	if (brojac == vel)
		return;
	if (brojac == 0)
		*(niz + brojac) = 1;
	else if (brojac == 1)
		*(niz + brojac) = 3;
	else
	{
		if (*(niz + brojac - 2) * *(niz + brojac - 1) < 0)
			return;
		else
			*(niz + brojac) = *(niz + brojac - 1) * *(niz + brojac - 2);
	}
	rekurzija(niz, vel, brojac + 1);
}
void ispis(int* niz, int vel)
{
	for (int i = 0; i < vel; i++)
		cout << *(niz + i) << endl;
}
int suma(int* niz, int vel)
{
	if (vel == 0)
		return *(niz + vel);
	return *(niz + vel) + suma(niz, vel - 1);
}
int main()
{
	int vel;
	do
	{
		cout << "Unesite vrijednost velicine : " << endl;
		cin >> vel;
	} while (vel < 2);
	int* niz = new int[vel];
	rekurzija(niz, vel);
	ispis(niz, vel);
	cout << "Suma svih clanova je: " << suma(niz, vel - 1) << endl;
	delete[]niz;
	niz = nullptr;
	system("pause>0");
	return 0;
}