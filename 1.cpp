#include<iostream>
#include<cstring>
using namespace std;

char *fun(char *str,int *flag)
{
	int len= strlen(str);
	char *p = str;
	char *q = str + 1;
	int pos = 1;
	*flag = 0;
	while(pos<=len)
	{
		if ((((*q-*p)==1)||(*p-*q)==1)&&*q!='*'&&*p!='*'&&*q!='\0'&&*p!='\0')
		{
			*flag = 1;
			*q = '*';
			*p = '*';
			q++;p++;
			char *temp = p;
			while (true)
			{
				if (*p == '*')
				{
					p--;
					if (p == str)
					{
						p = temp;
						break;
					}
				}
					else {
						if ((((*q - *p) == 1) || (*p - *q) == 1) && *q != '*'&&*p != '*'&&*q != '\0'&&*p != '\0')
						{
							*q = '*';
							*p = '*';
							q++;p--;
							pos++;
							if (p == str)
							{
								p = temp;
								break;
							}
						}
					}
				if (p == str || !(abs(*q - *p) == 1 && *q != '*'&&*p != '*'&&*q != '\0'&&*p != '\0'))
				{
					p = temp;
					break;
				}

			}
			pos++;
		}
		else
		{
			p++;
			q++;
			pos++;
		}
	}
	char *t = new char[100000];
	int k = 0;
	for (int i = 0;i <=len;i++)
	{
		if (*(str + i) != '*'&&*(str + i) != '\0')
		{		
			*(t + k) = *(str + i);
			k++;
		}
	}
	*(t + k) = '\0';
	delete str;
	return t;
}

int main()
{
	char *str = new char[100000];
	cin >> str;
	int len = strlen(str);
	*(str + len) = '\0';
	int *flag = new int;
	*flag = 1;
	while (*(str) != '\0')
	{
		str = fun(str,flag);
		if (*flag == 0)
			break;
	}
	if (*str == '\0')
		cout << "sad" << endl;
	else
	cout <<str<<endl;
	delete str;
	delete flag;
	//system("pause");
	return 0;
}