#include<iostream>
using namespace std;
#define MAX_LEN 2000
#define MAX_NUM 0x7FFFFFFF 
#define LENGTH 2000
int prim(int n, int edge_weight[][LENGTH])
{
	int sum = 0;
	bool vmst[MAX_LEN];
	for (int i = 1;i <= n;i++)
		vmst[i] = false;
	vmst[1] = true;
	int cost[MAX_LEN];
	for (int i = 1;i <= n;i++)
	{
		cost[i] = edge_weight[1][i];
	}
	for (int i = 0; i<n-1; i++)//ѭ��n-1�Σ�n-1����
	{
		int min = MAX_NUM;
		int v = -1;
		for (int j = 1; j<=n; j++)
			if (!vmst[j] && min>cost[j])
			{
				min = cost[j];
				v = j;
			}
		sum += min;
		vmst[v] = true;//����������
		for (int j = 1; j<=n; j++)
			if (!vmst[j] && cost[j]>edge_weight[v][j])//�������v-j
				cost[j] = edge_weight[v][j];
	}
	return sum;
}
int main()
{
	
		int n, k;
		cin >> n >> k;
		int edge_weight[LENGTH][LENGTH];
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				cin >> edge_weight[i][j];
			}
		}
		for (int i = 0;i < k;i++)
		{
			int a, b;
			cin >> a >> b;

			edge_weight[a][b] = edge_weight[b][a] = 0;

		}
		
		cout << prim(n, edge_weight) << endl;
	
//	system("pause");
	return 0;
}