#include<iostream>
using namespace std;
int soda(int bottle)
{
	if (bottle < 2)
		return 0;
	if (bottle == 2)
		return 1;
	int sum = bottle / 3;
	bottle = bottle%3;
	bottle += sum;
	return sum + soda(bottle);
}
int main()
{
	int n;
	cin >> n;
	while (n!=0)
	{
		
		int count = 0;
		if (n == 0)
			break;
		count =soda(n);
		cout << count << endl;
		cin >> n;
	}
	
	return 0;
}