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
		c = c1 / c2;        //c是组合数
		for (int i = 0;i < n;i++)
			a[i] = i + 1;//设一个数组，从0到n-1保存数列1,2,...,n
		while (c--)
		{
			for (int m = 0;m < k - 1;m++)
				cout << a[m] << ' ';
			cout << a[k - 1] << endl;//把前k项输出
			int p = k - 1;
			if (a[p] == n)//如果第k项为n,就把它之前的第k-1项加一，以此类推
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
			else a[p]++;//第k项小于n就直接加一
		}
	}
	//system("pause");
	return 0;
}