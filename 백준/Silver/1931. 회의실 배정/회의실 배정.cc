#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n;
pair<int, int> conference[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int first, second;
		cin >> conference[i].second >> conference[i].first;
	}

	sort(conference, conference + n);

	int t = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (t <= conference[i].second)
		{
			t = conference[i].first;
			count++;
		}
	}

	cout << count;
}