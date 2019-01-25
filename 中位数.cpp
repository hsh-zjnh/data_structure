#include<iostream>
using namespace std;
#define MAX_LEN 1000000
int median(int a[], int b[], int len)
{
	if (len == 1)
	{
		if (a[0]<b[0])
			return a[0];
		else return b[0];
	}
	int t = (len - 1) / 2;
	if (a[t] == b[t])
		return a[t];
	else if (a[t] < b[t])
	{
		if (t == 0)
			return median(&a[t + 1], b, len - 1);
		else
			return median(&a[t], b, len - t);
	}
	else
	{
		if (t == 0)
			return median(a, &b[t + 1], len - 1);
		else
			return median(a, &b[t], len - t);
	}
}
int main()
{
	int a[MAX_LEN], b[MAX_LEN];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	cout << median(a, b, n) << endl;
	//system("pause");
	return 0;
}