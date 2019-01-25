#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while (cin >> n >> m)
	{
		char *s1=new char[1000], *s2=new char[1000];
		cin >> s1 >> s2;
		int s[100] ;
		int k = 0;
		if (n == 0)
			cout << "-1" << endl;
		else {
			for (int i = 0;i <= n - m;i++)
			{
				int f = 0;
				for (int j = 0;j < m;j++)
				{
					if (s1[i + j] != s2[j])
					{
						f = 1;
						break;
					}
				}
				if (m == 0)
					f = 1;
				if (f == 0)
				{
					s[k] = i;
					k++;
				}
			}
			if (k == 0)
				cout << "-1" << endl;
			else
			{
				for (int i = 0;i < k - 1;i++)
					cout << s[i] << ' ';
				cout << s[k - 1] << endl;
			}
		}
	}
	return 0;
}