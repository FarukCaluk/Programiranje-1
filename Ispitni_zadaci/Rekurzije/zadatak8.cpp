/*Napisati program koji učitava prirodan broj n.Program treba ispisati najmanji prirodni broj m ,veći ili jednak n , koji je 
potencija nekog prirodnog broja, tj. m=k^l, gdje su k i l≥2 prirodni brojevi. U ovom zadatku je zabranjeno koristiti pow funkciju 
za računanje potencije.Potenciju računati koristeći rekurzivnu funkciju kojoj se proslijeđuje k i l i u kojoj je dozvoljena samo operacija množenja.*/
#include <iostream>

using namespace std;

int recur(int,int);

int main()
{
	int n;
	while (cout << "Unesit neki broj: ", cin >> n, n < 0);
	int k = 2, l = 2;
	int m = n;
	bool zastava = true;

	while (zastava)
	{
		int potencija = recur(k, l);
		if (potencija < m)
			l++;
		else if (sqrt(m) + 1 < k) {
			m++; k = 2; l = 2;
		}
		else if (potencija > m) {
			k++; l = 2;
		}
		else
			zastava = false;
	}
	cout << "Najmanji prirodni broj je: " << k <<" ^ "<< l <<" = "<< m << endl;
	system("pause>0");
}
int recur(int k, int l)
{
	if (l == 1)
		return k;
	return k * recur(k, l - 1);
}