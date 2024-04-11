#include <iostream>
using namespace std;

int recur(int, int);

void main()
{
	int n;  while (cout << "Unesite neki broj: ", cin >> n, n < 0);
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
	cout << "Najmanji prirodni broj je: " << recur(k, l)<<endl;
	system("pause>0");
}
int recur(int k, int l)
{
	if (l == 1) return k;
	return k * recur(k, l - 1);
}