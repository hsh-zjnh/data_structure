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
		insert(num, ptr->left);//ֵ�ȸ�С������ߣ��ȸ�������ұ�
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
		queque[rear] = root;//��������
		rear++;
		while (front < rear)
		{
			root = queque[front];//�Ӷ�����ȡһ��������
			front++;
			count--;
			if (count == 0)
				cout << root->data << endl;
			else
		     	cout << root->data << " ";
			if (root->left)//��������������ӣ�������ͬ��
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
	while (n--)//����n������ÿ������Ͳ���һ�����
	{
		cin >> num;
		insert(num, root);
	}
	LevelOrder(root, queque, count2);//�������
	print_InOrder(root, count);//����
	//system("pause");
	return 0;
}