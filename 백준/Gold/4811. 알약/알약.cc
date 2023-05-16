#include <iostream>
using namespace std;

long long dp[31][31];
long long solve(int w, int h)
{
	if (h == -1) return 0;
	if (w == 0) return 1;
	long long& ret = dp[w][h];
	if (ret)
		return dp[w][h];

	ret = solve(w - 1, h + 1) + solve(w, h - 1);

	return ret;
}

int main()
{
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		cout << solve(n, 0) << endl;
	}
}