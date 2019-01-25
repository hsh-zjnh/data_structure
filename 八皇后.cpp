#include<iostream>
using namespace std;
bool valid(int *p, int row, int col)
{
	for (int i = 0;i < row;i++)
	{
		if (p[i] == col)//ͬһ��
			return false;
		if (row - i == col - p[i] || row - i == p[i] - col)//ͬһб��
			return false;
	}
	return true;//����Ҫ��
}
void queen(int *p,int row)
{
	if (row == 7)//row��ʾ�Ѿ��¹����ӵ�������ǰ7�ж������Ӿ����
	{
		for (int i = 0;i < 8;i++)
			cout << p[i];
		cout << endl;
	}
	else 
	for (int i = 1;i < 9;i++)
	{
		if (valid(p, row + 1, i) == 1)//i��ʾ���ܵ��У�����Ϸ������½�һ�����̡�
		{
			int *q = new int[8];
	        for (int i = 0;i < 8;i++)//���Ƶ�ǰ����
		    q[i] = p[i];
			q[row+1] = i;//��(row+2,i)���λ�÷�����(�±�row+1)
			queen(q, row + 1);
			delete q;
		}
	}

}
int main()
{
	int col;
	while (cin >> col)
	{
		int *p;
		p = new int[8];//���±��ʾ��������ָ���ֵ��ʾ����
		p[0] = col;
		for (int i = 1;i < 8;i++)
			p[i] = 0;
		queen(p, 0);
		delete p;
	}
	return 0;
}