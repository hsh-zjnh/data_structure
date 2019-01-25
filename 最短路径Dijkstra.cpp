#include<iostream>
using namespace std;
#define MAX_LEN 1000
#define MAX_VALUE 100000
void Dijkstra(int edge[MAX_LEN][MAX_LEN], int dist[MAX_LEN], int path[MAX_LEN], int v, int n)
{
	bool s[MAX_LEN];
	int min, w;
	for (int i = 0;i < n;i++)
	{
		dist[i] = edge[v][i];
		s[i] = false;
		if (i != v && dist[i] < MAX_VALUE)
			path[i] = v;
		else
			path[i] = -1;
	}
	
	s[v] = true;
	dist[v] = 0;
	for (int i = 0;i < n - 1;i++)
	{
		min = MAX_VALUE;
		int u = v;
		for (int j = 0;j < n;j++)
		{
			if (s[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		s[u] = true;
		for (int k = 0;k < n;k++)
		{ 
			w = edge[u][k];
			if (s[k] == false && w < MAX_VALUE&&dist[u] + w < dist[k])
			{
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	
	}
}
void print_path(int u, int v, int path[MAX_LEN])
{
	int d[MAX_LEN];
	int k = 0;
	int j = v;
	while (u != j)
	{
		d[k++] = j;
		j = path[j];
	}
	d[k] = u;
	while (k > 0)
		cout << d[k--] << "->";
	cout <<d[k]<< endl;
}
int main()
{
	int n, u, v;
	cin >> n >> u >> v;
	int edge[MAX_LEN][MAX_LEN];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			cin >> edge[i][j];
	int dist[MAX_LEN];
	int path[MAX_LEN];
	Dijkstra(edge, dist, path, u, n);
	if (dist[v] == MAX_VALUE)
		cout << "NAN" << endl;
	else
	{
		cout << dist[v] << endl;
		print_path(u, v, path);
	}
	//system("pause");
	return 0;
}