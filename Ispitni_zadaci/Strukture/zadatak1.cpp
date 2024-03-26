/*Kreirati dinamièki dvodimenzionalni niz èiji su elementi objekti tipa fudbaler (fudbaler je struktura èija su obilježja data 
u nastavku). Omoguæiti korisniku da unese dimenzije niza.*/ 
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct fudbaler
{
	int* godRodjenja;
	int* brojIgraca;
	int* golovi;

	fudbaler() 
	{
		godRodjenja = new int;
		brojIgraca = new int;
		golovi = new int;
	}

	~fudbaler()
	{
		delete godRodjenja;
		godRodjenja = nullptr;

		delete brojIgraca;
		brojIgraca = nullptr;

		delete golovi;
		golovi = nullptr;
	}
};

void unos(fudbaler** , int , int );
void ispis(fudbaler**, int, int);
void bestTeam(fudbaler**, int, int);
void bestplayer(fudbaler**, int, int);
void dealokacija(fudbaler**&, int);

int main()
{
	srand(time(0));
	int red;
	int kol;

	cout << "Unesite koliko redova zelite: ";
	cin >> red;
	cout << "Unesite koliko kolona zelite: ";
	cin >> kol;

	fudbaler** niz = new fudbaler * [red];
	for (int i = 0; i < red; i++)
	{
		*(niz + i) = new fudbaler[kol];
	}

	unos(niz, red, kol);
	ispis(niz, red, kol);

	bestTeam(niz, red, kol);
	bestplayer(niz, red, kol);

	dealokacija(niz, red);

	cin.get();
	return 0;
}
void unos(fudbaler** niz, int red, int kol)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			*(*(niz + i) + j)->godRodjenja = 1980 + rand() % ((2000 + 1) - 1980);
			*(*(niz + i) + j)->brojIgraca= rand() % 30 + 1;
			*(*(niz + i) + j)->golovi = rand() % 5;
		}
	}
}
void ispis(fudbaler** niz, int red, int kol)
{
	cout << endl;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			cout << "Godina rodjenja je: " << *(*(niz + i) + j)->godRodjenja << " | " << endl;
			cout << "Broj igraca je: " << *(*(niz + i) + j)->brojIgraca << " | " << endl;
			cout << "Broj golova igraca je: " << *(*(niz + i) + j)->golovi << endl;
		}
		cout << endl;
	}
}
void bestTeam(fudbaler** niz, int red, int kol)
{
	float* najboljitim = new float[red] {};

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			*(najboljitim + i) += *(*(niz + i) + j)->golovi;
		}
		*(najboljitim + i) /= kol;
	}
	int indeks = 0;
	for (int i = 0; i < red; i++)
	{
		if (*(najboljitim + i) > *(najboljitim + indeks))
		{
			indeks=i;
		}
	}
	cout << "Najbolji tim se nalazi na indeksu: " << indeks << "i sa podacima: " << endl;

	for (int j = 0; j < kol; j++)
	{
		cout << "Godina rodjenja je: " << *(*(niz + indeks) + j)->godRodjenja << " | " << endl;
		cout << "Broj igraca je: " << *(*(niz + indeks) + j)->brojIgraca << " | " << endl;
		cout << "Broj golova igraca je: " << *(*(niz + indeks) + j)->golovi << endl;
	}
	cout << endl;
}
void bestplayer(fudbaler** niz, int red, int kol)
{
	float* najgoritim = new float[red] {};
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			*(najgoritim + i) += *(*(niz + i) + j)->golovi;
		}
		*(najgoritim + i) /= kol;
	}
	int indeks = 0;
	for (int i = 0; i < red; i++)
	{
		if (*(najgoritim + i) < *(najgoritim + indeks))
		{
			indeks = i;
		}
	}

	int najboljfudbaler = *(*(niz + indeks) + 0)->golovi;
	int indeksj = 0;

	for (int j = 0; j < kol; j++)
	{
		if (*(*(niz + indeks) + j)->golovi > najboljfudbaler)
		{
			indeksj = j;
		}
	}
	cout << "Najbolji igrac u najgorem timu rodjen je: " << *(*(niz + indeks) + indeksj)->godRodjenja << " i ima golova: " << *(*(niz + indeks) + indeksj)->golovi << endl;

	delete[]najgoritim;
}
void dealokacija(fudbaler**& niz, int red)
{
	for (int i = 0; i < red; i++)
	{
		delete[] * (niz + i);
	}
	delete[]niz;
	niz = nullptr;
}