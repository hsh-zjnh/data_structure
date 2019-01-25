#include<iostream>
using namespace std;

const int MAX_NUM = 100;

struct Edge
{
	int key;
	int head;
	int tail;
};

/*void sift_up(Edge heap[], int n);
void sift_down(Edge heap[], int n);
int find(int parent[MAX_NUM], int i);
void set_union(int parent[MAX_NUM], int root1, int root2);
*/

void sift_up(Edge heap[], int n)
{
	if (n<1)
		return;
	Edge temp = heap[n - 1];
	int i = (n - 2) / 2, j = n - 1;
	while (j > 0)
	{
		if (temp.key < heap[i].key)
		{
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
		else
		{
			break;
		}
	}
	heap[j] = temp;
}

void sift_down(Edge heap[], int n)
{
	if (n<1)
		return;
	Edge temp = heap[0];
	int i = 0, j = 1;
	while (j < n)
	{
		if (heap[j].key>heap[j + 1].key&&j<n)
		{
			j++;
		}
		if (temp.key>heap[j].key)
		{
			heap[i] = heap[j];
			i = j;
			j = j * 2 + 1;
		}
		else
		{
			break;
		}
	}
	heap[i] = temp;
}


int find(int parent[MAX_NUM], int i)
{
	int root = i;
	for (; parent[root] >= 0; root = parent[root]);
	while (root != i)
	{
		int temp = parent[i];
		parent[i] = root;
		i = temp;
	}
	return root;
}

void set_union(int parent[MAX_NUM], int i1, int i2)
{
	int root1 = find(parent, i1), root2 = find(parent, i2);
	if (root1 != root2)
	{
		int temp = parent[root1] + parent[root2];
		if (parent[root1] > parent[root2])
		{
			parent[root1] = root2;
			parent[root2] = temp;
		}
		else
		{
			parent[root2] = root1;
			parent[root1] = temp;
		}
	}
}
int main()
{
	int edge[MAX_NUM][MAX_NUM];
	int n, k;
	bool v[MAX_NUM] = { 0 };
	int count = 0;
	int parent[MAX_NUM];

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> edge[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << a << " " << b << " " << endl;
		if (a != b)
		{
			a--;
			b--;
			v[a] = 1;
			v[b] = 1;
			set_union(parent, a, b);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (v[i])
		{
			count++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int root = find(parent, i);
		if (i != root)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (edge[i][j]<edge[root][j])
				{
					edge[root][j] = edge[i][j];
					edge[j][root] = edge[root][j];
				}
				edge[i][j] = -1;
				edge[j][i] = -1;
			}
		}
	}
	Edge heap[MAX_NUM];
	int e_num = 0;
	int route = 0;

	for (int i = 0; i < n; i++)
	{
		if (v[i] == 1)
		{
			for (int j = 0; j < n; j++)
			{
				if (v[j] == 0)
				{
					heap[e_num].head = i;
					heap[e_num].tail = j;
					heap[e_num].key = edge[i][j];
					e_num++;
					sift_up(heap, e_num);
				}
			}
		}
	}

	while (count < n)
	{
		int u = heap[0].tail;
		v[u] = 1;
		route += heap[0].key;
		count++;

		while (e_num > 0 && heap[0].tail == u)
		{
			e_num--;
			heap[0] = heap[e_num];
			sift_down(heap, e_num);
		}

		if (count < n)
		{
			for (int j = 0; j < n; j++)
			{
				if (v[j] == 0)
				{
					heap[e_num].head = u;
					heap[e_num].tail = j;
					heap[e_num].key = edge[u][j];
					e_num++;
					sift_up(heap, e_num);
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << edge[i][j] << " ";
		}
		cout << endl;
	}
	cout << route;
	system("pause");
	return 0;
}
