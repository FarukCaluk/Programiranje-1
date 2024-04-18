/*funkciju koja æe taj niz popuniti random brojevima u opsegu od 1 do 100. Za generisanje random brojeva 
koristiti rand() % 100 + 1. Punjenje niza se prekida kada se popuni cijeli niz ili kada se tri puta 
uzastopno dobije isti random broj.*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void rekurzija(int* niz, int vel, int brojac = 0)
{
	if (brojac == vel)
		return;
	else
	{
		*(niz + brojac) = rand() % 100 + 1;
		if(*(niz+brojac)==*(niz+brojac-1)&&*(niz+brojac)==*(niz+brojac-2))
			return;
	}
	rekurzija(niz, vel, brojac + 1);
}
int main()
{
	srand(time(NULL));
	int vel;
	do
	{
		cout << "-------------------------|" << endl;
		cout << "Unesite velicinu niza: ";
		cin >> vel;
		cout << "-------------------------|" << endl;
	} while (vel < 2);
	int* niz = new int[vel];
	rekurzija(niz, vel);

	for (int i = 0; i < vel; i++)
	{
		cout << *(niz + i) << endl;
		cout << "-----|" << endl;
	}

	delete[]niz;
	niz = nullptr;

	system("pause>0");
	return 0;
}