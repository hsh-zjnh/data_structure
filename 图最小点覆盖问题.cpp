#include<iostream>
using namespace std;
#define MAX_LEN 100
int main()
{
	int v, e;
	cin >> v >> e;
	int edge[MAX_LEN][MAX_LEN] = { 0 };
	for (int i = 0;i < e;i++)//edge[i][j]表示i到j的路径数
	{
		int v1, v2;
		cin >> v1 >> v2;
		edge[v1][v2]++;
		edge[v2][v1]++;
	}
	bool s[MAX_LEN] ;    //s[i]为true则i点还未被删去
	for (int i = 1;i <= v;i++)
	{
		s[i] = true;
	}
	int count_v = 0;
	int count_e = 0;
	int edge_n[MAX_LEN];//edge_n[i]是与i邻接的边数
	
	while (true)
	{
		for (int i = 1;i <= v;i++)//每次循环都初始化为0
	{
		edge_n[i] = 0;
	}
		for (int i = 1;i <= v;i++)
		{
			if(s[i]==true)
				for (int j = 1;j < v + 1;j++)
				{
					edge_n[i] += edge[i][j];
				}
		}
		int max = 1;
		for (int i = 1;i <= v;i++)
		{
			if (s[i]==true&&(edge_n[max] < edge_n[i]))
				max = i;
		}
		count_e += edge_n[max];
		count_v++;
		edge_n[max] = 0;
		s[max] = false;
		if (count_e == e)
			break;
		for(int j=1;j<=v;j++)
		{
			if (s[j] == true && edge[j][max] > 0)
				edge[j][max]--;
		}
		
	}
	cout << count_v << endl;
//	system("pause");
	return 0;
}