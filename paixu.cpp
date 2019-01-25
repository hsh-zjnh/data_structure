#include<iostream>
using namespace std;
#define MAXLEN 100
int main()
{
	int m, n;
	int a[MAXLEN], b[MAXLEN];
	
		cin >> m>>n;
	for (int i = 0;i < m;i++)
		cin >> a[i];
	for (int i = 0;i < n;i++)
		cin >> b[i];
	int c[2 * MAXLEN];
	int na = 0, nb = 0;
	for (int i = 0;i < n + m;i++)
	{
		if (nb == n)
		{
			c[i] = a[na];
			na++;
		}
		else if (na == m)
		{
			c[i] = b[nb];
			nb++;
		}
		else if (a[na] < b[nb])
		{
			c[i] = a[na];
			na++;
		}
		else
		{
			c[i] = b[nb];
			nb++;
		}

	}
	for (int i = 0;i < n + m - 1;i++)
		cout << c[i] << ' ';
	cout << c[n + m - 1] << endl;
	return 0;

}