#include<iostream>
using namespace std;
#define MAX_LEN 100
bool match(int i, int v, bool s[], int m[], int adj[][MAX_LEN])
{
	for (int j = 1;j <= v;j++)
	{
		if (adj[i][j+v]==1 && s[j+v])
		{
			s[j+v] = false;
			if (m[j+v] == 0 || match(m[j+v], v, s, m, adj))
			{
				m[j+v] = i;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int adj[MAX_LEN][MAX_LEN] = { 0 };
	
	int v, e;
	cin >> v >> e;
	for (int i = 0;i < e;i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1][v2+v] = 1;//看作两个点
		adj[v2][v1 + v] = 1;
	}
	bool complete = true;
	for (int i = 1;i <=  v;i++)
	{
		for (int j = v + 1;j <= 2 * v;j++)
			if (adj[i][j] == 0 && i + v != j)
			{
				complete = false;
				break;
			}
	}
	if (complete)//完全图
	{
		cout << v - 1 << endl;
	}
	else {
		int count = 0;
		bool s[MAX_LEN];
		int m[MAX_LEN];
		for (int i = 1;i <= 2 * v;i++)
		{
			m[i] = 0;
		}

		for (int i = 1;i <= v;i++)
		{
			for (int j = 1;j <= 2 * v;j++)
			{
				s[j] = true;
			}
			if (match(i, v, s, m, adj, complete))
				count++;
		}
		if (count % 2 == 1)//向上取整
			count++;
		cout << count / 2 << endl;
	}
	system("pause");
	return 0;
}