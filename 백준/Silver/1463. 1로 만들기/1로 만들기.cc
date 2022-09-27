#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> dp(n + 1);

	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		//3으로 나누어 떨어질 때
		if (!(i % 3)) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		//2로 나누어 떨어질 때
		if (!(i % 2)) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}

	cout << dp[n] << endl;
	return 0;
}