#include<iostream>
#include<cstring>
using namespace std;
void num(char str[10], int &p)
{
	for (int i = 0;str[i] != '\0';i++)
	{
		p = p * 10 + (str[i] - 48);
	}
}
int find_parent(int p, int parent[])
{
	int k = p;
	while (parent[k] >= 0)
		k = parent[k];
	while (k != p)
	{
		int temp = parent[p];
		parent[p] = k;
		p = temp;
	}
	return k;
}
void Union(int n1, int n2, int parent[])
{
	int r1 = find_parent(n1,parent), r2 = find_parent(n2,parent);
	int temp;
	if (r1 != r2)
	{
		temp = parent[r1] + parent[r2];
		if (parent[r2] < parent[r1])
		{
			parent[r1] = r2;
			parent[r2] = temp;
		}
		else
		{
			parent[r2] = r1;
			parent[r1] = temp;
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	int parent[10010];
	for (int i = 0;i <= n;i++)
	{
		parent[i] = -1;
	}
	while (k--)
	{
		char str[3][10];
		for (int i = 0;i < 3;i++)
			cin >> str[i];
		int i = 0, j = 0;
		num(str[1], i);
		num(str[2], j);
		if ((strcmp(str[0], "Check") == 0))
		{
			int p1 = find_parent(i, parent);
			int p2 = find_parent(j, parent);
			if (p1 == p2)
				cout << "True" << endl;
			else
				cout << "False" << endl;
		}
		else if (strcmp(str[0], "Union") == 0)
		{
			Union(i, j, parent);
		}

	}
	//	system("pause");
	return 0;
}