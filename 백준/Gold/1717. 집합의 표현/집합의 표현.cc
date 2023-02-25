#include<iostream>
using namespace std;

int n, m;
int arr[1000001];

int find(int x)
{
	if (arr[x] == x)
		return x;
	arr[x] = find(arr[x]);
	return arr[x];
}

void setUnion(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	arr[y] = x;
}

void isUnion(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) 
		cout << "YES" << "\n";
	else 
		cout << "NO" << "\n";
}

int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int op, a, b;
		scanf("%d%d%d", &op, &a, &b);
		if (op == 0)
		{
			setUnion(a, b);
		}
		else if (op == 1)
		{
			isUnion(a, b);
		}	
	}
}