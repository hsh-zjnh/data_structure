#include<iostream>
using namespace std;
void _next(int next[],char p[])
{
	int j = 0, k = -1;
	next[0] = -1;
	while (j < (int)strlen(p))
	{
		if (k == -1 || p[j] == p[k])
		{
			j++;k++;
			next[j] = k;
		}
		else k = next[k];
	}
}
int main() {
	int next[100];
	char t[100];
	char p[100];
	while (cin >> t)
	{
		cin >> p;
		_next(next, p);
		int posp = 0, post = 0;
		int lent = strlen(t), lenp = strlen(p);
		while (posp < lenp&&post < lent)
		{
			if (posp == -1 || p[posp] == t[post])
			{
				posp++;
				post++;
			}
			else posp = next[posp];
		}if (posp < lenp) cout << "-1"<<endl;
		else cout << post - lenp << endl;
	}
	return 0;
}