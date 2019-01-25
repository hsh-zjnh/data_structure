#include<iostream>
#include<cstring>
using namespace std;
struct node {
	char ch;
	node *left;
	node *right;
};
void create(node *&head, node *&cur, char str[], int &k)
{
	if (strlen(str) == k)
		return;
	if (str[k] == '@')//����û�нڵ��ˣ�����
	{
		k++;
		return;
	}
	if (head == NULL)//��
	{
		node *p = new node;
		p->ch = str[k];
		k++;
		p->left = NULL;
		p->right = NULL;
		head = p;
		create(head, head->left, str, k);
		create(head, head->right, str, k);
	}
	else {
		if (str[k] != '@')//�ڵ�
		{
			node *p = new node;
			p->ch = str[k];
			k++;
			p->left = NULL;
			p->right = NULL;
			cur = p;
			create(head, cur->left, str, k);//�ȴ�������������������
			create(head, cur->right, str, k);
		}
	}
}
void print_tree(node *&head)
{
	if (head != NULL)
	{
		print_tree(head->left);
		print_tree(head->right);
		cout << head->ch;
	}
}
void _delete(node *p)
{
//	if (p->left == NULL && p->right == NULL)
	//	delete p;
//	else {
	if (p)
	{
		_delete(p->left);
		_delete(p->right);
		delete p;
	}
//	}
}
int main()
{
	char str[100];
	while (cin >> str)
	{
		node *head = NULL;
		int k = 0;
		create(head, head, str, k);//����������
		print_tree(head);//�������
		_delete(head);
	}
	return 0;
}