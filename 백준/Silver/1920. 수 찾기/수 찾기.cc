#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	vector<int> v;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int target;
		scanf("%d", &target);

		if (binary_search(v.begin(), v.end(), target))
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
}