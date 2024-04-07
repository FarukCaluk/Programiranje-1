/*Napisati program koji æe omoguæiti unos prirodnog broja A (A > 100000), 
te kreirati i ispisati broj B koji æe se sastojati od cifara broja A u obrnutom 
redoslijedu u kojem je svaka parna uklonjena. (npr. ako se unese 45362792 funkcija
æe vratiti 9735). Ispisati razliku brojeva A i B.*/
#include <iostream>
using namespace std;

int slovoB(int a)
{
	int b = 0;
	int cif = 0;
	while (a > 0) {
		cif = a % 10;
		if (cif % 2 != 0)
		{
			b = b * 10 + cif;
		}
			a /= 10;
	}
	return b;
}
int main()
{
	int a;
	int b;
	do
	{

		cout << "Unesite prirodni broj A: ";
		cin >> a;
		cout << "_______________________________" << endl;
		if (a < 100000)
		{
			cout << "Unjeli ste malu vrijednost." << endl;
		}
	} while (a < 100000);
	b = slovoB(a);
	cout << "Broj B je: " << b << endl;
	cout << "________________" << endl;
	cout << "Razlika ta dva broja je: " << a - b << endl;

	return 0;
}
