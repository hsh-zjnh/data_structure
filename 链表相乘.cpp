#include<iostream>
#include<cmath>
using namespace std;
struct node
{
	int num;
	node *next;
};
node *input(char line[])
{
	node *head=NULL, *tail = NULL;
	int i = 0;
	while (line[i]!='\0')
	{
		if (line[i] != ' ')
		{
			node *p = new node;
			p->num = line[i] - 48;
			p->next = NULL;
			if (head == NULL)
				head = tail = p;
			else
			{
				tail->next = p;
				tail = p;
			}
		
		}
		i++;
	}
	return head;
}
void _delete(node *head)
{
	while (head)
	{
		node *t = head;
		head = head->next;
		delete t;
	}
}
int main()
{
	node *multiplier = NULL;
	node *multiplicand = NULL;
	char line1[50];char line2[50];
	
	
	while(cin.getline(line1, 49)&&cin.getline(line2,49))
	{
		multiplier = input(line1);
		multiplicand = input(line2);
		int product[50] = { 0 };
		int m = 0, n = 0;
		for (node *p = multiplier;p != NULL;p = p->next, m++)
		{
			n = m;
			for (node *q = multiplicand;q != NULL;q = q->next)
			{
				product[n] += q->num*p->num;
				n++;
			}
		}
		int i = 0;
		while (true)
		{
			int temp = product[i];
			product[i] = temp % 10;
			i++;
			product[i] += temp / 10;
			if (i >= n && product[i] < 10)
			{
				if (product[i] == 0)
					i--;
				break;
			}

		}
		for (;i >= 0;i--)
			cout << product[i];
		cout << endl;
		_delete(multiplier);
		_delete(multiplicand);
	}
		system("pause");
	return 0;
}