#include<iostream>
using namespace std;
struct avlnode {
	int bf;
	int data;
	avlnode *left;
	avlnode *right;
};
void rotateL(avlnode *&ptr)
{
	avlnode *subl = ptr;
	ptr = subl->right;
	subl->right = ptr->left;
	ptr->left = subl;
	ptr->bf = subl->bf = 0;
}
void rotateR(avlnode *&ptr)
{
	avlnode *subr = ptr;
	ptr = subr->left;
	subr->left = ptr->right;
	ptr->right = subr;
	ptr->bf = subr->bf = 0;
}
void rotateLR(avlnode *&ptr)
{
	avlnode *subr = ptr, *subl = subr->left;
	ptr = subl->right;
	subl->right = ptr->left;
	ptr->left = subl;
	if (ptr->bf <= 0)
		subl->bf = 0;
	else
		subl->bf = -1;
	subr->left = ptr->right;
	ptr->right = subr;
	if (ptr->bf == -1)
		subr->bf = 1;
	else
		subr->bf = 0;
	ptr->bf = 0;
}
void rotateRL(avlnode *&ptr)
{
	avlnode *subl = ptr, *subr = subl->right;
	ptr = subr->left;
	subr->left = ptr->right;
	ptr->right = subr;
	if (ptr->bf >= 0)
		subr->bf = 0;
	else
		subr->bf = 1;
	subl->right = ptr->left;
	ptr->left = subl;
	if (ptr->bf == 1)
		subl->bf = -1;
	else
		subl->bf = 0;
	ptr->bf = 0;
}
bool insert(avlnode *&root, int data)
{
	avlnode *stack[1000];
	int st = 0;//
	avlnode *pr = NULL, *p = root, *q;
	int d;
	while (p != NULL)//�ҵ������λ��
	{
		if (data == p->data)
			return false;
		pr = p;
		stack[st] = pr;//�Ѳ���·��������ջ��
		st++;
		if (data < p->data)
			p = p->left;
		else
			p = p->right;
	}
	p = new avlnode;//�½�Ҷ�ڵ�
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	p->bf = 0;
	if (pr == NULL)
	{
		root = p;
		return true;
	}
	if (data < pr->data)
		pr->left = p;
	else
		pr->right = p;
	while (st) //����ƽ�⻯
	{
		pr = stack[st - 1];//POP(pr):ȡ���ڵ�
		stack[st - 1] = NULL;
		st--;
		if (p == pr->left)//�²���Ľڵ�����������bf--,����++
			pr->bf--;
		else
			pr->bf++;
		if (pr->bf == 0)//bf==0 ����Ľڵ��bf����仯���˳�ѭ��
			break;
		if (pr->bf == -1 || pr->bf == 1)//bfΪ-1��1 ���������޸�bf
			p = pr;
		else
		{
			d = (pr->bf < 0) ? -1 : 1;
			if (p->bf == d) //p��pr��bf��ͬ��һ��ֱ���ϣ��� ����ת  
			{
				if (d == -1)
					rotateR(pr);
				else
					rotateL(pr);
			}
			else     //p��pr��bf��ͬ��˫��ת
			{
				if (d == -1)
					rotateLR(pr);
				else
					rotateRL(pr);
			}
			break;
		}
	}
	if (st == 0)//       �����������
		root = pr;
	else
	{
		q = stack[st - 1];//�����û���������������Ӷ�����
		if (q->data > pr->data)
			q->left = pr;
		else
			q->right = pr;
	}
	return true;
}
void print(avlnode *root,int &n)
{
	if (root != NULL)
	{
		n--;
		if (n)
			cout << root->data << ' ';
		else
			cout << root->data << endl;
		print(root->left,n);
		print(root->right,n);
	}
}
int main()
{
	int n;
	cin >> n;
	int num;
	avlnode *root = NULL;
	for (int i = 0;i < n;i++)
	{
		cin >> num;
		insert(root, num);
	}
	print(root, n);
	system("pause");
	return 0;
}