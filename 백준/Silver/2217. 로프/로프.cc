#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> rope(100001);

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> rope[i];
	}

	sort(rope.begin(), rope.begin() + n);

	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		answer = max(answer, rope[n - i] * i);
	}

	cout << answer;
}