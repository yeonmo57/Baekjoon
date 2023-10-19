#include <iostream>

using namespace std;

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int n;
	int next;

	int t[1000] = { 0, };
	int p[1000] = { 0, };
	int dp[1000] = { 0, };
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}

	for (int i = n; i > 0; i--)
	{
		next = i + t[i];
		if (next - 1> n) 
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + 1], dp[next] + p[i]);
		}
	}

	cout << dp[1] << endl;
	return 0;
}
