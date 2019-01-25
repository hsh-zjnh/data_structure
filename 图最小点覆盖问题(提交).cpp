#include<iostream>
using namespace std;
#define MAX_LEN 100
int main()
{
	int v, e;
	cin >> v >> e;
	int edge[MAX_LEN][MAX_LEN] = { 0 };
	for (int i = 0;i < e;i++)//edge[i][j]��ʾi��j��·����
	{
		int v1, v2;
		cin >> v1 >> v2;
		edge[v1][v2]++;
		edge[v2][v1]++;
	}
	bool s[MAX_LEN];    //s[i]Ϊtrue��i�㻹δ��ɾȥ
	for (int i = 1;i <= v;i++)
	{
		s[i] = true;
	}
	int count_v = 0;
	int count_e = 0;
	int edge_n[MAX_LEN];//edge_n[i]����i�ڽӵı���
    for (int i = 1;i <= v;i++)//��ʼ��Ϊ0
		{
			edge_n[i] = 0;
		}
	for (int i = 1;i <= v;i++)
		{
			if (s[i] == true)
				for (int j = 1;j < v + 1;j++)
				{
					edge_n[i] += edge[i][j];
				}
		}
	while (true)
	{	
		int max = 0;
		for (int i = 1;i <= v;i++)//�ҵ��ڽӵı����Ķ���
		{
			if (s[i] == true && ((edge_n[max] < edge_n[i])||max==0))
				max = i;
		}
		count_e += edge_n[max];
		count_v++;
		edge_n[max] = 0;
		s[max] = false;//ɾȥ�������������ڽӵı�
		if (count_e == e)
			break;
		for (int j = 1;j <= v;j++)
		{
			if (s[j] == true && edge[j][max] > 0)
			{
				edge[j][max]--;
				edge_n[j]--;
			}
		}
	}
	cout << count_v << endl;
	//	system("pause");
	return 0;
}