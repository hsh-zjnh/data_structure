#include<iostream>
using namespace std;
struct node {
	int y;
	int x;
	node *link;
};
void insert(node *hash[],node *&p,int num)
{
	if (hash[num] == NULL)
		hash[num] = p;
	else
	{
		node *q = hash[num];
		while (true)
		{
			if (q->link == NULL)
			{
				q->link=p;
				p->link = NULL;
				break;
			}
			q = q->link;
			if (q == NULL)
				break;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	node *hash[100000] = {NULL};
	node *left = NULL;
	node *right = NULL;
	long long max = 0;
	int ymax = 0;
	for (int i = 0;i < n;i++)
	{
		int num;
		cin >> num;
		if (num > ymax)
			ymax = num;
		node *p = new node;
		p->x = i;
		p->y = num;
		p->link = NULL;
	    insert(hash, p,num);
	}
	int y = ymax;
	left = hash[y];
	node *q = hash[y];
	if (q->link != NULL)
	{
		for (;q->link != NULL;q = q->link);
		right = q;
	}
	if(right)
	max = y * (right->x - left->x);
	
	while (--y)
	{
		node *q = hash[y];
		if (q != NULL)
		{
			if (right == NULL)
			{
				if (q->x > left->x)
					right = q;
				else
				{
					right = left;
					left = q;
				}
				max = y * (right->x - left->x);
			}
			for (;q != NULL;q = q->link)
			{
			
					if (q->x > right->x)
				{
					if (((q->x - left->x)*q->y) > max)
						max = (q->x - left->x)*q->y;
				}
				else if (q->x < left->x)
				{
					if (((right->x - q->x)*q->y) > max)
						max = (right->x-q->x)*q->y;
				}

			}
		}
	}
	cout << max << endl;
//	system("pause");
	return 0;
}