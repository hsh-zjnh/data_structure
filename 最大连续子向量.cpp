#include<iostream>
using namespace std;
#define LEN 100000
int main()
{
	int n;
	
	while (cin >> n)
	{
		int a[LEN];
		int k[LEN];int t = 0;
		for (int i = 0;i < n;i++)
			cin >> a[i];
		int sign = a[0] >> 31;
		int sum = 0;int flag = 0;
		for (int i = 0;i < n;i++)//simplify the array. ͬ����λ�������,�õ�һ��������������k
		{
			int s = a[i] >> 31;
			if (s == sign)
			{
					sum += a[i];
				if (i == n - 1 && flag == 0)
				{
					k[0] = sum;t++;
				}
			
			}
			else
			{
				flag = 1;
				k[t] = sum;
				t++;
				sum = a[i];
				sign = s;
				if (i == n - 1)
				{
					k[t] = sum;
					t++;
				}
			}
		}
		
		int m = 0;
		int max = k[0];
		int temp = k[0];
		int MAX = max;//������������������
		while (true)
		{
			m++;
			if (m == t)
				break;
			else {
				int temp = max + k[m];
				if (k[m] > temp&&k[m] > max)//��������max����������ĺͣ�����ǰ��ģ������������ʼ����
					max = k[m];
				else if (temp > max)//���ϵ�ǰ������max����
					max = temp;
				else
				{
					if (max > MAX)//�������ֵ
						MAX = max;
					if (temp < 0)//С���㣬������ֱ�Ӵ���һ��������ʼ��
					{
						
							max = k[m];
					}
					if (temp >= 0)//������������
						max = temp;
				}

			}
		}	cout << MAX << endl;
	
	}
	return 0;
}