#include<iostream>
#include<cstring>
using namespace std;
struct node {
	int utype;
	union {
		int ref;
		char ch;
		node *hlink;
	}info;
	node *tlink;
};
void generalized_list(char str[], int k, node *&head, node *&tail, node *&temp)
{
	if (k == strlen(str))
		return;
	else {
		if (head == NULL)
		{
			node *p = new node;
			p->utype = 0;
			p->info.ref = 0;
			p->tlink = NULL;//ͷ���
			head = tail = p;
			k++;
		}
		if (str[k] == '(') {
			node *q = new node;
			q->utype = 2;
			q->info.hlink = NULL;
			q->tlink = NULL;
			tail->tlink = q;
			tail = q;
			node *p = new node;
			p->utype = 0;
			p->info.ref = 1;
			p->tlink = NULL;//newһ���ӱ��ͷ���
			tail->info.hlink = p;
			generalized_list(str, k + 1, head, p, tail);
		}
		else if (str[k] == ',')
		{
			generalized_list(str, k + 1, head, tail, temp);//ֱ�ӵ���һ��Ԫ��
		}
		else if (str[k] == ')')//�ӱ�������ص���һ����β
		{
			tail->tlink = NULL;
			generalized_list(str, k + 1, head, temp, temp);
		}
		else {
			node *p = new node;
			p->utype = 1;
			p->info.ch = str[k];
			p->tlink = NULL;
			tail->tlink = p;
			tail = p;//�����µĽڵ�
			generalized_list(str, k + 1, head, tail, temp);
		}
	}
}
void read_list(node *&head)
{
	if (head->tlink != NULL)
		read_list(head->tlink);
	if (head->utype == 2)             //�ӱ�������ӱ��е�Ԫ��
	{
		read_list(head->info.hlink);
	}
	else if (head->utype == 0)
	{
		if (head->tlink == NULL)//�ձ����'@'
			cout << '@';
	}
	else if (head->utype == 1)//��ԭ�ӣ����
	{
		cout << head->info.ch;
	}

}
void _delete_list(node *head)
{
	if (head->tlink != NULL)
		_delete_list(head->tlink);
	if (head->utype == 2)
	{
		_delete_list(head->info.hlink);
	}
	else if (head->utype == 0)
	{
		if (head->tlink == NULL)
			delete head;
	}
	else if (head->utype == 1)
	{
		delete head;
	}

}
int main()
{
	char str[100];
	while (cin >> str)
	{
		node *head = NULL, *tail = NULL;
		generalized_list(str, 0, head, tail, tail);
		read_list(head);
		_delete_list(head);
		//cout << head->tlink->tlink->tlink->tlink->info.hlink->tlink->info.ch << endl;
	}
	return 0;
}