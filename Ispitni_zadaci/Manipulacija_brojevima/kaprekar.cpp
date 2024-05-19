#include <iostream>

using namespace std;


int sortiranje(int);
bool svakaCifraIsta(int);
int obrnuti(int);


int main()
{
	int n;
	int prethodnarazlika = 0;
	int razlika = 0;
	int sortirani = 0;
	int brojac = 0;
	do {
		cout << "Unesite cetverocifren broj koji se ne sastoji od iste cifre: "; cin >> n;
	} while (n < 1000 || n>9999 || svakaCifraIsta(n) == true);

	razlika = n;
	do
	{
		prethodnarazlika = razlika;
		sortirani = sortiranje(razlika);
		razlika = sortirani - obrnuti(sortirani);
		brojac++;

		cout << razlika << " = " << sortirani << " - " << obrnuti(sortirani) << endl;

	} while (razlika != prethodnarazlika);


	cout << "Kaprekarova konstanta pojavljuje se u broju: " << razlika;

	system("pause>null");
	return 0;
}


int sortiranje(int n)
{
	int sortiran = 0;

	for (int i = 9; i >= 0; i--)
	{
		int temp = n;
		while (temp)
		{
			if (temp % 10 == i)
			{
				sortiran *= 10;
				sortiran += i;
			}
			temp /= 10;
		}
	}
	return sortiran;
}
bool svakaCifraIsta(int n)
{
	int brojac = 0;
	int cifra = n % 10;
	while (n)
	{
		if (n % 10 == cifra)
			brojac++;
		n /= 10;

	}
		if (brojac == 4)
			return true;
	return false;
}


int obrnuti(int n)
{
	int obrnuti = 0;
	do
	{
		int temp = n % 10;
		obrnuti = obrnuti * 10 + temp;
		n /= 10;
	} while (n);
	return obrnuti;
}