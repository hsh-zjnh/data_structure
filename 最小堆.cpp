#include<iostream>
using namespace std;
void siftdown(int heap[100], int pos, int size)
{
	int root = pos;
	int child = 2 * pos + 1;
	int temp = heap[pos];
	while (child < size)
	{
		int right_child = child + 1;
		if (right_child < size&&heap[right_child] < heap[child])
			child = right_child;
		if (heap[root] > heap[child])
		{
			int temp = heap[root];
			heap[root] = heap[child];
			heap[child] = temp;
			root = child;
			child = 2 * child + 1;
		}
		else break;
	}
}
int main()
{
	int heap[1000];
	int k = 0;
	while (cin >> heap[k])
	{
		k++;
	}
	int pos = (k - 2) / 2;
	while (pos >= 0)
	{
		siftdown(heap,pos, k);
		pos--;
	}
	for (int i = 0;i < k-1;i++)
		cout << heap[i] << ' ';
	cout << heap[k - 1] << endl;
	return 0;
}