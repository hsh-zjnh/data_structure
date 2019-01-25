#include<iostream>
using namespace std;
int backpack(int s,int bag[], int k,int n)
{
	int sum = 0;
	for (int i = k;i < n;i++)
	{
		if (bag[i] == s)
		{
			sum++;
		}
		else if (bag[i] < s)
		{
			sum += backpack(s - bag[i], bag, i + 1, n);
		}
	}
	return sum;
}
int main()
{
	int s, n;
	while (cin >> s >> n)
	{
		int bag[1000];
		for (int i = 0;i < n;i++)
			cin >> bag[i];
		int sum = backpack(s, bag, 0,n);
		cout << sum << endl;
	}
	
	return 0;
}