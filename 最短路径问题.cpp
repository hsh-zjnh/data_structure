#include<iostream>
using namespace std;
#define LEN 1000
#define QLEN 10000
struct position
{
	int valid;
	int count;
	int row;
	int col;
};
bool enter(int *rear, position p[LEN][LEN], int row, int col, int count, position &finish, position queue[QLEN], int n, int m)
{
	if (p[row][col].valid == 0)
		return false;
	if (col == finish.col && row == finish.row)//����Ŀ�ĵ�
	{

		finish.count = count + 1;
		return true;
	}

	if ((row >= 0) && (row < n) && (col >= 0) && (col < m) && p[row][col].valid == 1)
	{
		*rear += 1;
		queue[*rear].col = col;
		queue[*rear].row = row;
		queue[*rear].count = count + 1;
		p[row][col].count = count + 1;
		p[row][col].valid = 0;
		queue[*rear].valid = 0;//�õ�û�б����������
	}
	return false;
}
bool findpath(int *rear, int front, position p[LEN][LEN], position &finish, position queue[QLEN], int n, int m)
{
	do {

		front++;
		bool t1, t2, t3, t4;
		t1 = enter(rear, p, queue[front].row - 1, queue[front].col, queue[front].count, finish, queue, n, m);//��

		t2 = enter(rear, p, queue[front].row + 1, queue[front].col, queue[front].count, finish, queue, n, m);//��

		t3 = enter(rear, p, queue[front].row, queue[front].col - 1, queue[front].count, finish, queue, n, m);//��

		t4 = enter(rear, p, queue[front].row, queue[front].col + 1, queue[front].count, finish, queue, n, m);//��

		if (t1||t2||t3||t4)//����һ���������յ㷵��1
		{
			return true;
		}
	} while (front<*rear);
	return false;
}
int main()
{
	int n, m;
	position queue[QLEN];
	int front = 0;
	int *rear = new int;
	char map[LEN][LEN];
	position p[LEN][LEN];
	position start, finish;
	while (cin >> n >> m)
	{
		

		for (int i = 0;i<n;i++)//����ͼ
			for (int j = 0;j < m;j++)
			{
				cin >> map[i][j];
			}
		for (int i = 0;i<n;i++)
			for (int j = 0;j < m;j++)
			{
				p[i][j].count = 0;//�����ľ��붼��Ϊ1
				p[i][j].col = j;
				p[i][j].row = i;
				if (map[i][j] == 'o' || map[i][j] == 'd' || map[i][j] == 'z')//'x'���������ǺϷ���
				{
					p[i][j].valid = 1;
				}
				else
					p[i][j].valid = 0;
				if (map[i][j] == 'd')
				{
					finish.valid = 1;
					finish.row = i;
					finish.col = j;
					finish.count = 0;

				}
				if (map[i][j] == 'z')
				{
					start.valid = 0;
					start.row = i;
					start.col = j;
					start.count = 0;
					*rear = 1;
					queue[*rear] = start;//�����������
					
				}
			}//end
		int f = findpath(rear, front, p, finish, queue, n, m);
		if (f == 1)
			cout << finish.count << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}
