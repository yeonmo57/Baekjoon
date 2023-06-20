#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<pair<int, int>> tower; // 인덱스, 높이
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		while (!tower.empty())
		{
			if (tower.top().second > t)
			{
				printf("%d ", tower.top().first);
				break;
			}
			tower.pop();
		}
		if (tower.empty())
		{
			cout << "0 ";
		}
		tower.push(make_pair(i, t));
	}
}