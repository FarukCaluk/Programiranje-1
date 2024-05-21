#include <iostream>

using namespace std;

int obrni(int);
bool palindrom(int);

void goldbach(int broj)
{
	for (int i = broj / 2,  j = broj / 2; i <= broj; i++, j--)
	{
		if (palindrom(i) && palindrom(j))
		{
			if (i + j == broj)
			{
				cout << i << " + " << j << " = " << broj<<endl;
			}
		}
	}
}
int main()
{
	int n1, n2;
	do
	{
		cout << "Unesite n1: " << endl;
		cin >> n1;

		cout << "Unesite n2: " << endl;
		cin >> n2;

	} while (n1 < 200 || n2 < n1 + 100);
	if (n1 > n2)
	{
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}
	for (int i = n1; i <= n2; i++)
	{
		goldbach(i);
	}
}

int obrni(int n)
{
	int novi = 0,temp=0;
	while (n > 0)
	{
		temp = n % 10;
		novi = novi * 10 + temp;
		n /= 10;
	}
	return novi;
}
bool palindrom(int n)
{
	if (obrni(n) == n)
		return true;
	return false;
}