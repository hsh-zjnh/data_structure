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
	if ((int)strlen(str) == k)
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
void _delete(node *p)
{
	if (p->left == NULL && p->right == NULL)
		delete p;
	if (p->left != NULL)
	{
		_delete(p->left);

	}
	if (p->right != NULL)
	{
		_delete(p->right);
	}


}
void Path(node *&p, node path[], int &len)
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right == NULL)
		{
			path[len] = *p;
			for (int i = len; i >= 0; i--)
			{
				cout << path[i].ch;
			}
			cout << endl;
		}
		else {
			path[len] = *p;
			len++;
			if (path->left)
				Path(p->left, path, len);
			if (path->right)
				Path(p->right, path, len);
			len--;
		}
	}
}
int main()
{
	char str[100];
	while (cin >> str)
	{
		node *head = NULL;
		int k = 0;
		create(head, head, str, k);//����������
		node *p = head;
		node path[50];
		int len = 0;
		Path(p, path, len);
		_delete(head);
	}
	return 0;
}