#include<iostream>
using namespace std;
int main()
{
	int a[100];
	int n, k;
	while (cin >> n >> k)
	{
		int c = 0, c1 = n, c2 = 1;
		for (int i = 2, j = n - 1;i <= k;i++, j--)
		{
			c1 *= j;
			c2 *= i;
		}
		c = c1 / c2;        //c�������
		for (int i = 0;i < n;i++)
			a[i] = i + 1;//��һ�����飬��0��n-1��������1,2,...,n
		while (c--)
		{
			for (int m = 0;m < k - 1;m++)
				cout << a[m] << ' ';
			cout << a[k - 1] << endl;//��ǰk�����
			int p = k - 1;
			if (a[p] == n)//�����k��Ϊn,�Ͱ���֮ǰ�ĵ�k-1���һ���Դ�����
				while (p > 0)
				{
					p--;
					if (a[p] < p + n - k + 1)
					{
						a[p]++;
						for (int i = p + 1;i < k;i++)
							a[i] = a[i - 1] + 1;
						break;
					}
				}
			else a[p]++;//��k��С��n��ֱ�Ӽ�һ
		}
	}
	//system("pause");
	return 0;
}