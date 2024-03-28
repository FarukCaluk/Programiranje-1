/*Napisati program koji æe omoguæiti korisniku da unese velièinu jednodimenzionalnog dinamièkog niza integer 
vrijednosti. Napisati rekurzivnu funkciju koja æe taj niz popuniti serijom brojeva 2, 4, 8, 16, 32, 64, 128, 256, 512, 
itd., tako da je svaki sljedeæi broj jednak prethodnom pomnoženom sa 2, poèevši od broja 2. Zatim,korisnik unosi
željeni broj te rekurzivnom funkcijom provjerava da li je taj broj èlan kreiranog niza. Rekurzija se prekida kada se 
popuni cijeli niz ili kada se desi overflow na integer varijabli*/
#include <iostream>
using namespace std;

void rekurzija(int* niz, int vel, int brojac = 0)
{
	if (brojac == vel)
		return;
	if (brojac == 0)
		*(niz + brojac) = 2;
	else
	{
		if (*(niz + brojac - 1) * 2 < 0)
			return;
		else
			*(niz + brojac) = *(niz + brojac - 1) * 2;
	}
	rekurzija(niz, vel, brojac + 1);
}
int main()
{
	int vel;
	do
	{
		cout << "unesite velicinu niza: ";
		cin >> vel;
	} while (vel < 2);
	int* niz = new int[vel];

	rekurzija(niz, vel);
	for (int i = 0; i < vel; i++)
	{
		cout << *(niz + i) << endl;
	}

	niz = nullptr;
	delete[]niz;
	system("pause>0");
	return 0;
}