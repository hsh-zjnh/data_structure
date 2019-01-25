#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long num[1000000];
	for (int i = 0;i < n;i++)
	{
		cin >> num[i];
	}
	long long left = 0, right = n - 1;
	long long max = (right - left)*(num[left] < num[right] ? num[left] : num[right]);
	while (left < right)
	{
		long long temp = (right - left)*(num[left] < num[right] ? num[left] : num[right]);
		if (temp > max)
			max = temp;
		if (num[left] < num[right])
		{
			long long t = num[left];
			while(t>=num[left])
			left++;
		}
		else
		{
			long long t = num[right];
			while (t >= num[right])
				right--;
		}
	}
	cout << max << endl;
//	system("pause");
	return 0;
}