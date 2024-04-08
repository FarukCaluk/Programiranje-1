/*Napisati program koji korisniku omoguæava unos cijelog broja N, te izraèunava geometrijsku sredinu svih neparnih brojeva u intervalu 
[1, N] koji nisu djeljivi sa brojem 5. Rezultat trebi biti zaokružen na dvije decimale.*/
#include <iostream>
#include <iomanip>
using namespace std;

double geo_sred(int);

int main()
{

	int n;
	cout << "Unesite vrijednost n: ";
	cin >> n;

	cout << "Geometrijska sredina svih neparnih brojeva: " <<setprecision(3)<<geo_sred(n)<< endl;
	return 0;
}
double geo_sred(int n)
{
	double gs = 1.0;
	int brojac = 0;
	for (int i = 1; i <= n; i += 2)
	{
		if (i % 5 != 0)
		{
			gs *= i;
			brojac++;
		}
}
	return pow(gs, 1 / double(brojac));
}
