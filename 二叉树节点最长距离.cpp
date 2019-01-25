#include<iostream>
#include<cstring>
using namespace std;
struct node {
	char ch;
	int left_len;
	int right_len;
	node *left;
	node *right;
};
void create(node *&head, node *&cur, char str[], int &k)
{
	if ((int)strlen(str) == k)
		return;
	if (str[k] == '@')//下面没有节点了，返回
	{
		k++;
		return;
	}
	if (head == NULL)//根
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
		if (str[k] != '@')//节点
		{
			node *p = new node;
			p->ch = str[k];
			k++;
			p->left = NULL;
			p->right = NULL;
			cur = p;
			create(head, cur->left, str, k);//先创建左子树，后右子树
			create(head, cur->right, str, k);
		}
	}
}
void find_max(node *&head,int &max)
{
	if (head != NULL)
	{
		if (max < (head->left_len + head->right_len))
		max = head->left_len + head->right_len;
		find_max(head->left,max);
		find_max(head->right,max);
		
	}
}
void _delete(node *p)
{
	if (p)
	{
		_delete(p->left);
		_delete(p->right);
		delete p;
	}
}
int max_path(node *root)
{
	if (root->left)
		root->left_len = max_path(root->left) + 1;
	else
		root->left_len = 0;
	if (root->right)
		root->right_len = max_path(root->right) + 1;
	else
		root->right_len = 0;
	if (root->left == NULL && root->right == NULL)
		return 0;
	return (root->left_len > root->right_len) ? root->left_len : root->right_len;
}
int main()
{
	int lenth;
	cin >> lenth;
	char str[100];
	cin >> str;
	node *head = NULL;
	int k = 0;
	create(head, head, str, k);//创建二叉树
	max_path(head);
	int len=0;
	find_max(head, len);
	_delete(head);
	cout << len << endl;
	//system("pause");
	return 0;
}