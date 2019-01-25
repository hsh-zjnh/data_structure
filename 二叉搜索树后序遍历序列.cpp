#include<iostream>
using namespace std;
bool is_postorder(int tree[],int start,int end)
{
	if (start < end) {
		int root = tree[end];
		int left = -1;
		int right = -1;#																									2````
		int i;
		for (i = 0;tree[i] < root;i++, left++);
		right = i;
		for (;i < end;i++)
		{
			if (tree[i] < root)
				return false;
		}
		if (is_postorder(tree,0, left) == false)
			return false;
		if (is_postorder(tree, right, end - 1) == false)
			return false;
			return true;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	int tree[20];
	for (int i = 0;i < n;i++)
		cin >> tree[i];
	if (is_postorder(tree, 0, n - 1) == false)
		cout << "false" << endl;
	else
		cout << "true" << endl;
//	system("pause");
	return 0;
}