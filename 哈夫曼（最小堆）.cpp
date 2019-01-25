#include<iostream>
using namespace std;
struct huffman_node {
	long long data;
	huffman_node* llink;
	huffman_node* rlink;
};
int cmp(const void *m, const void *n)
{
	return *(int *)m - *(int *)n;
}
void siftdown(huffman_node *heap[], int pos, int size)
{
	int root = pos;
	int child = 2 * pos + 1;
	while (child < size)
	{
		int right_child = child + 1;
		if (right_child < size&&heap[right_child]->data < heap[child]->data)
			child = right_child;
		if (heap[root]->data > heap[child]->data)
		{
			huffman_node *temp = heap[root];
			heap[root] = heap[child];
			heap[child] = temp;
			root = child;
			child = 2 * child + 1;
		}
		else break;
	}
}
void siftup(int start, huffman_node *heap[])
{
	int j = start, i = (j - 1) / 2;
	huffman_node *temp = heap[j];
	while (j > 0)
	{
		if (heap[i] <= temp)break;
		else
		{
			heap[j] = heap[i];j = i;
			i = (i - 1) / 2;
		}
		heap[j] = temp;
	}
}
void removemin(huffman_node *&x, huffman_node *heap[], int &size)
{
	x = heap[0];
	heap[0] = heap[size - 1];
	size--;
	siftdown(heap, 0, size );
}
void insert(huffman_node *heap[], huffman_node *x, int &size)
{
	
	heap[size] = x;
	siftup(size, heap);
	size++;
}
void WPL(huffman_node *root, long long &ret, int k)
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
/*void print(huffman_node *root)
{
	if (root)
	{
		cout << root->data << ' ';
		print(root->llink);
		print(root->rlink);
	}
}*/
huffman_node *creat_huffman(int n, huffman_node *heap[], int &k)
{
	
	for (int i = 0;i < n - 1;i++)
	{

		huffman_node *first, *second;
		removemin(first, heap, k);
		removemin(second, heap, k);
		huffman_node *root = new huffman_node;
		root->llink = first;
		root->rlink = second;
		root->data = first->data + second->data;
		insert(heap, root, k);
	}
	return heap[0];
}
int main()
{
	int n;
	cin >> n;
	huffman_node *heap[100005];
	
	for (int i = 0;i < n;i++)
	{
		heap[i] = new huffman_node;
		cin>>heap[i]->data;
		heap[i]->llink = NULL;
		heap[i]->rlink = NULL;
	}
	int pos = (n - 2) / 2;
	while (pos >= 0)
	{
		siftdown(heap, pos, n);
		pos--;
	}

	int k = n;
	long long ret = 0;
	huffman_node *root = creat_huffman(n, heap, k);
	WPL(root, ret, 0);
	cout << ret << endl;
	//system("pause");
	return 0;
}