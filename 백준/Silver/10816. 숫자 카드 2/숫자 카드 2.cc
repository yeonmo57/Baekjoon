#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[500001];

int lower_idx(int target, int n)
{
	int st = 0;
	int ed = n;

	while (st < ed)
	{
		int mid = (st + ed) / 2;
		if (a[mid] < target)
		{
			st = mid + 1;
			mid = (st + ed) / 2;
		}
		else if (a[mid] >= target)
		{
			ed = mid;
		}
	}
	return st;
}

int upper_idx(int target, int n)
{
	int st = 0;
	int ed = n;

	while (st < ed)
	{
		int mid = (st + ed) / 2;
		if (a[mid] <= target)
		{
			st = mid + 1;
		}
		else if (a[mid] > target)
		{
			ed = mid;
		}
	}
	return st;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		cout << upper_idx(t, n) - lower_idx(t, n) << '\n';
	}
}