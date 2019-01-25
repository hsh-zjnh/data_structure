#include<iostream>
using namespace std;
struct node
{
	char sen;
	node *next;
};
node *input(char a[])
{
	node *head = NULL, *tail = NULL;
	for (int i = 0;a[i] != '\0';i++)
	{
		node *p = new node;
		p->next = NULL;
		p->sen = a[i];
		if (head == NULL)
			head = tail = p;
		else
			tail->next = p;
		tail = p;
	}
	tail->next = head;
	return head;
}
int main()
{
	char a[10000];
	while (cin >> a)
	{
		node *head = input(a);//ѭ������
		int d = 0, r = 0;
		node *p = head;
		while (true)
		{	
			if (p->sen == 'D')
			{
				node *q = p;
				int count = 0;
				for (;(q->next->sen != 'R');q = q->next)//����Dʱ������һ��R
				{
					if (q == p)
						count++;
					if (count == 2)
					{
						break;
					}
				}
				if (count == 2)//����һȦû��R��Dʤ
				{
					d = 1;
					break;
				}
				else//�ҵ�R��ɾ������ڵ�
				{
					node *t = q->next;
					q->next = t->next;
					delete t;
				}
				
			}
			else//ͬ��
			{
				node *q = p;
				int count = 0;
				for (;(q->next->sen != 'D');q = q->next)
				{
					if (q == p)
						count++;
					if (count == 2)
					{
						break;
					}
				}
				if (count == 2)
				{
					r = 1;
					break;
				}
				else
				{
					node *t = q->next;
					q->next = t->next;
					delete t;
				}
			}
			p = p->next;
		}
		if (d==1)
			cout << "Dire" << endl;
		else if (r==1)
			cout << "Radiant" << endl;
	}
	return 0;
}