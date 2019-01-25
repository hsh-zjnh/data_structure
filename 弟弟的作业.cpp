#include<iostream>
#include<cmath>
using namespace std;
bool if_number(char c)
{
	if (c <= 57 && c >= 48)
		return 1;
	else
		return 0;
}
int number(int k,char ex[])
{
	int count = 0;
	int i;
	for (i = k;ex[i] <= 57 && ex[i] >= 48;i++)
	{
		count++;
	}
	int n=0;
	for (;count > 0;count--)
	{
		n += (ex[k]-48)* pow(10, count - 1);
		k++;
	}
	return n;
}
int main()
{
	char expression[100];
	int count = 0;
	cin.getline(expression, 99);
	while (expression[0] != '\0')
	{
		int k = 0, flag = 0;
		int a = number(k, expression);
		while (if_number(expression[k]) == 1)
		{
			k++;
		}
		if (expression[k] == '-')
			flag = 1;
		k++;
		int b= number(k, expression);
		while (if_number(expression[k]) == 1)
		{
			k++;
		}
		k++;
		if (expression[k] != '?')
		{
			int c = number(k, expression);
			if (flag == 0)
			{
				if (a + b == c)
					count++;
			}
			else
			{
				if (a - b == c)
					count++;
			}
		}
		else;
		cin.getline(expression, 100);
	}
	cout << count << endl;

	return 0;
}