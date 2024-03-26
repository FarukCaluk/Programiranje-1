/*Napisati program koji izraèunava aritmeticku sredinu svih savrsenih brojeva iz zadatog intervala.
 Za neki broj se kaze da je savršen ukoliko je jednak sumi svih svojih djelilaca
 (ne uk1juèujuci njega samog). Na primjer, 28 je savršen broj: njegovi djelioci su:
1, 2, 4, 7 i 14, a 1 + 2 + 4 + 7 + 14 = 28. Jedini savrseni brojevi u opsegu od 1 do 100 su
 brojevi 6 i 28. U rjesenju koristiti funkciju sljedeceg prototipa: bool IsSavrsen(int).Primjer
Unesite granice intervala: 1 500
Aritmeticka sredina savrsenih brojeva iz zadatog intervala je: 176.667*/
#include <iostream>
using namespace std;
bool isSavrsen(int);
void main()
{
	int x, y,brojacSavrsenih=0;
	double suma = 0;
	cout << "Unesite x i y:" << endl;
	cin >> x, y;
	for (int i = x; i <= y;i++)
	{
		if (isSavrsen(i)) {
			suma += i;
			brojacSavrsenih++;
		}
	}
	cout << "Aritmeticka sredina iznosi:" << suma / brojacSavrsenih << endl;

	system("pause");
}
bool isSavrsen(int br)
{
	int suma = 0;
	for (int i = 0; i < br; i++)
	{
		if (br % i == 0)
		{
			suma += i;
		}
	}
	if (suma == br)
		return true;
	else
		return false;
}