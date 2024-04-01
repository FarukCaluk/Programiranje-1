#include <iostream>
using namespace std;

bool isProst(int broj)
{
	for (int i = 2; i <= broj / 2; i++)
		if (broj % i == 0)
			return false;
	return true;
}
long int faktorijel(int broj)
{
	long int proizvod = 1;
	for (int i = 2; i <= broj; i++)
		proizvod *= i;
	return proizvod;
}
int generisiFibonaci(int pozicija)
{
	if (pozicija == 0 || pozicija == 1)
		return pozicija;

	int predhodnik1 = 0;
	int predhodnik2 = 1;
	
	int fibonaci = 0;
	for (int i = 0; i < pozicija; i++)
	{
		fibonaci = predhodnik1 + predhodnik2;
		if (fibonaci < predhodnik2)
			return 0;

		predhodnik1 = predhodnik2;
		predhodnik2 = fibonaci;
	}
	return fibonaci;
}
void dodajFaktorijel(long int& suma, int pozicija)
{
	int broj = generisiFibonaci(pozicija);
	if (isProst(broj))
		suma += faktorijel(broj);
}
int main()
{
	long int suma = 0;

	for (int i = 0; i < 100; i++)
		dodajFaktorijel(suma, i);

	cout << "Suma je: " << suma;
	return 0;
}