#include<iostream>
using namespace std;
bool valid(int *p, int row, int col)
{
	for (int i = 0;i < row;i++)
	{
		if (p[i] == col)//同一列
			return false;
		if (row - i == col - p[i] || row - i == p[i] - col)//同一斜线
			return false;
	}
	return true;//符合要求
}
void queen(int *p,int row)
{
	if (row == 7)//row表示已经下过棋子的行数，前7行都有棋子就输出
	{
		for (int i = 0;i < 8;i++)
			cout << p[i];
		cout << endl;
	}
	else 
	for (int i = 1;i < 9;i++)
	{
		if (valid(p, row + 1, i) == 1)//i表示可能的列，如果合法，就新建一个棋盘。
		{
			int *q = new int[8];
	        for (int i = 0;i < 8;i++)//复制当前棋盘
		    q[i] = p[i];
			q[row+1] = i;//在(row+2,i)这个位置放棋子(下标row+1)
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
		p = new int[8];//用下标表示行数，用指向的值表示列数
		p[0] = col;
		for (int i = 1;i < 8;i++)
			p[i] = 0;
		queen(p, 0);
		delete p;
	}
	return 0;
}