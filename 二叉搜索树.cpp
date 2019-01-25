#include<iostream>
using namespace std;
struct node {
	int data;
	node *left;
	node *right;
};
void insert(int num, node *&ptr)
{
	if (ptr == NULL) {
		ptr = new node;
		ptr->data = num;
		ptr->left = NULL;
		ptr->right = NULL;
	}
	else if (num < ptr->data)
		insert(num, ptr->left);//值比根小插在左边，比根大插在右边
	else if (num > ptr->data)
	insert(num, ptr->right);
}
void print_InOrder(node *root,int &count)
{
	if (root) {
		print_InOrder(root->left,count);
		count--;
		if (count == 0)
			cout << root->data << endl;
		else
			cout << root->data << ' ';
		print_InOrder(root->right,count);
	}
}
void LevelOrder(node *root, node *queque[],int &count)
{
	int front =0, rear = 0;
	if (root != NULL)
	{
		queque[rear] = root;//根结点入队
		rear++;
		while (front < rear)
		{
			root = queque[front];//从队列中取一个结点输出
			front++;
			count--;
			if (count == 0)
				cout << root->data << endl;
			else
		     	cout << root->data << " ";
			if (root->left)//左子树存在则入队，右子树同理
			{
				queque[rear] = root->left;
				rear++;
			}
			if (root->right)
			{
				queque[rear] = root->right;
				rear++;
			}

		}
	}

}
int main()
{
	int n;
	cin >> n;
	int num;
	node *root = NULL;
	int count = n, count2 = n;
	node *queque[100000];
	int front = 0;
	int rear = 0;
	while (n--)//输入n个数，每次输入就插入一个结点
	{
		cin >> num;
		insert(num, root);
	}
	LevelOrder(root, queque, count2);//广度优先
	print_InOrder(root, count);//中序
	//system("pause");
	return 0;
}