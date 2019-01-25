#include<iostream>
using namespace std;
 struct node {
	int num;
	node *right;
	node *left;
};
node *input(int n)
{
	int k = 1;
	node *head=NULL, *tail=NULL;
	for (;k <= n;k++)
	{
		node *p = new node;
		p->num = k;
		p->left = NULL;
		p->right = NULL;
		if (head == NULL)
		{
			head = tail = p;
			head->right = tail;
			tail->left = head;
		}
		else
		{
			tail->right = p;
			p->left = tail;
			tail = p;
		}
		if (k == n)
		{
			tail->right = head;
			head->left = tail;
		}
	}
	return head;
}
int main()
{
	int n, k, m; 
	while (cin >> n >> m >> k)//n个人数到m编号k开始
	{
		node *clockwise = input(n);
		node *counter = input(n);
		node *right = clockwise;//顺
		node *left = counter;//逆
		while (right->num != k)
			right = right->right;
		while (left->num != k)
			left = left->left;
		int people = n,count=1;
		while (people)
		{
			if (count == m)
			{
				if(people>1)
				cout << right->num << ' ';
				else
				cout << right->num<<endl;
				node *p = right->left;
				right->right->left = p;
				p->right = right->right;
				delete right;
				people--;
				right = p->right;
				count = 1;
			}
			else
			{
				right = right->right;
				count++;
			}
		}

	    people = n, count = 1;
		while (people)
		{
			if (count == m)
			{
				if (people>1)
					cout << left->num << ' ';
				else
					cout << left->num << endl;
				node *p = left->right;
				left->left->right = p;
				p->left = left->left;
				delete left;
				people--;
				left = p->left;
				count = 1;
			}
			else
			{
				left = left->left;
				count++;
			}
		}
	}
	return 0;
}
