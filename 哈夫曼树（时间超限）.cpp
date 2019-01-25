#include<iostream>
using namespace std;
struct huffman_node {
	int data;
	huffman_node* llink;
	huffman_node* rlink;
	huffman_node* link;
};
int cmp(const void *m, const void *n)
{
	return *(int *)m - *(int *)n;
}
huffman_node *queue(int node[], int n)//按从小到大的顺序创建链表
{
	huffman_node *head = NULL;
	huffman_node *tail = NULL;
	for (int i = 0;i < n;i++)
	{
		huffman_node *p = new huffman_node;
		p->data = node[i];
		p->rlink = NULL;
		p->llink = NULL;
		p->link = NULL;
		if (head == NULL)
		{
			head = tail = p;
		}
		else
			tail->link = p;
		tail = p;
	}
	return head;
}
void insert(huffman_node *&head, huffman_node *p)//把形成的哈夫曼树节点插入链表
{
	if (p->data < head->data)
	{
		p->link = head;
		head = p;
	}
	else
	{
		huffman_node *q = head;
		while (true)
		{
			if (q->link == NULL)
				break;
			if (q->link->data > p->data)
				break;
			q = q->link;
		}
		p->link = q->link;
		q->link = p;
	}
}
void WPL(huffman_node *root, int &ret, int k)
{
	if (root)
	{
		WPL(root->llink, ret, k + 1);
		WPL(root->rlink, ret, k + 1);
		if ((root->llink == NULL) && (root->rlink == NULL))
		{
			ret += k * root->data;
		}
	}
}
huffman_node *creat_huffman(huffman_node *head)
{
	while (true) {
		if (head == NULL)
			return NULL;
		else if (head->link == NULL)
		{
			huffman_node *root = new huffman_node;
			root->llink = root->link = root->rlink = NULL;
			root->data = head->data;
			return root;
		}
		huffman_node *left = head;
		huffman_node *right = head->link;
		huffman_node *root = new huffman_node;
		root->data = left->data + right->data;
		root->llink = left;
		root->rlink = right;
		head = head->link->link;
		if (head == NULL)
			return root;
		insert(head, root);
	}
}
int main()
{
	int n;
	cin >> n;
	int node[100005];
	for (int i = 0;i < n;i++)
		cin >> node[i];
	qsort(node, n, sizeof(int), cmp);
	huffman_node *head = NULL;
	head = queue(node, n);
	huffman_node *root = creat_huffman(head);
	int ret = 0;
	WPL(root, ret, 0);
	cout << ret << endl;
	//system("pause");
	return 0;
}