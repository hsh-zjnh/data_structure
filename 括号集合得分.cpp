#include<iostream>
#include<cstring>
using namespace std;
struct bracket
{
	char lr;
	int point;
};
void _delete(bracket a[], int k, int len)
{
	for (int i = k;i < len - 1;i++)
		a[i] = a[i + 1];
	a[len - 1].lr = '\0';
}
void merge(bracket a[], int &len)
{
	for (int i = 0;a[i + 1].lr != '\0';i++)
	{
		if (a[i].lr == '*'&&a[i + 1].lr == '*')
		{
			a[i].point += a[i + 1].point;
			_delete(a, i + 1, len);
			len--;
			i--;
		}
	}
}
void remove_brac(bracket a[], int &len)
{
	for (int i = 0;a[i + 2].lr != '\0';i++)
	{
		if (a[i].lr == '('&&a[i + 1].lr == '*'&&a[i + 2].lr == ')')
		{
			a[i].lr = '*';
			a[i].point = a[i + 1].point * 2;
			_delete(a, i + 1, len);
			len--;
			_delete(a, i + 1, len);
			len--;
		}
	}
}
int main()
{
	char str[100];
	int len;
	while (cin >> len)
	{
		cin >> str;
		bracket a[100];
		for (int i = 0;i < len;i++)//������ȫ�����ڽṹ����
		{
			a[i].lr = str[i];
			a[i].point = 0;
		}
		a[len].lr = '\0';
		for (int i = 0;i < len - 1;i++)//ȥ��()������
		{
			if (a[i].lr == '('&&a[i + 1].lr == ')')
			{
				a[i].point = 1;
				a[i].lr = '*';
				_delete(a, i + 1, len);
				len--;
			}
		}
		while (len > 1)//����ʣ���ŵ�ʱ��ѭ�����ϲ�������ٰ�����(x)�����Ϊ����2*x�Ĳ�����
		{
			merge(a, len);
			remove_brac(a, len);
		}
		cout << a[0].point << endl;
	}
	return 0;
}