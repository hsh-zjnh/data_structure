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
		for (int i = 0;i < n;i++)//simplify the array. 同符号位的数相加,得到一个数保存在数组k
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
		int MAX = max;//保存最大的连续子向量
		while (true)
		{
			m++;
			if (m == t)
				break;
			else {
				int temp = max + k[m];
				if (k[m] > temp&&k[m] > max)//向量大于max与这个向量的和，舍弃前面的，从这个向量开始计算
					max = k[m];
				else if (temp > max)//加上当前向量后，max增大
					max = temp;
				else
				{
					if (max > MAX)//保存最大值
						MAX = max;
					if (temp < 0)//小于零，舍弃，直接从下一个向量开始算
					{
						
							max = k[m];
					}
					if (temp >= 0)//是正数，留下
						max = temp;
				}

			}
		}	cout << MAX << endl;
	
	}
	return 0;
}