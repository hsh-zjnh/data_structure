#include<iostream>
using namespace std;
#define MAX_LEN 200
#define LENGTH 200
struct edge
{
	int head;
	int tail;
	int value;
};

void siftdown(edge *heap[], int pos, int size)
{

	int root = pos;
	int child = 2 * pos + 1;
	while (child < size)
	{
		int right_child = child + 1;
		if (right_child < size && (heap[right_child]->value < heap[child]->value))
			child = right_child;
		if (heap[root]->value > heap[child]->value)
		{
			edge *temp = heap[root];
			heap[root] = heap[child];
			heap[child] = temp;
			root = child;
			child = 2 * child + 1;
		}
		else break;
	}
}
void siftup(int start, edge *heap[])
{

	int j = start, i = (j - 1) / 2;
	edge *temp = heap[j];
	while (j > 0)
	{
		if (heap[i]->value <= temp->value)break;

		else {
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
		heap[j] = temp;
	}
}
void removemin(edge *&x, edge *heap[], int &size)
{
	x = heap[0];
	heap[0] = heap[size - 1];
	size--;
	siftdown(heap, 0, size);
}
void insert(edge *heap[], edge *x, int &size)
{

	heap[size] = x;
	siftup(size, heap);
	size++;
}
int getneighbor(int u, bool vmst[], int v, int n)
{
	//int i = (u > v + 1) ? (u + 1) : (v + 1);
	for (int i = v + 1;i <= n;i++)
	{
		if ((vmst[i] == false) && (u != i))
			return i;
	}
	return -1;
};
void prim(int n, int u, int &heap_size, int edge_weight[][LENGTH], edge *heap[], edge *tree[], int &tree_size)
{

	bool vmst[MAX_LEN];
	for (int i = 0;i <= n;i++)
		vmst[i] = false;
	vmst[u] = true;

	int count = 1;
	do {
		int v = 1;
		while (v <= n)
		{
			if (vmst[v] == false)
			{
				edge *e = new edge;
				e->head = v;
				e->tail = u;
				e->value = edge_weight[u][v];
				insert(heap, e, heap_size);
			}
			v++;
		}

		while (heap_size > 0 && count < n)
		{
			edge *ed = NULL;
			removemin(ed, heap, heap_size);

			if (vmst[ed->head] == false&&vmst[ed->tail]==true)
			{
				tree[tree_size] = ed;
				tree_size++;
				u = ed->head;
				vmst[u] = vmst[ed->tail]=true;
				count++;
				break;
			}
		}
	
	} while (count < n);
}
int path(edge *tree[], int &tree_size, int edge_weight[][LENGTH])
{
	int sum = 0;
	for (int i = 0;i < tree_size;i++)
	{
		sum += tree[i]->value;
	}
	return sum;
}
int main()
{
	while (true) {
		int n, k;
		cin >> n >> k;

		edge *heap[MAX_LEN];int heap_size = 0;
		edge *tree[MAX_LEN];
		int tree_size = 0;

		int edge_weight[LENGTH][LENGTH];
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				cin >> edge_weight[i][j];
			}
		}


		for (int i = 0;i < k;i++)
		{
			int a, b;
			cin >> a >> b;

			edge_weight[a][b] = edge_weight[b][a] = 0;

		}

		prim(n, 3, heap_size, edge_weight, heap, tree, tree_size);
		if (tree_size != n - 1)
			cout << -1 << endl;
		else
			cout << path(tree, tree_size, edge_weight) << endl;

		/*for (int i = 0;i < n;i++)
		{

			edge *e = new edge;
			cin >> e->value ;
			insert(heap,e, heap_size);
		}
		for (int i = 0;i < n;i++)
		{
			edge *e = NULL;
			removemin( e,heap, heap_size);
			cout << e->value << endl;
		}*/
	}
	system("pause");
	return 0;
}