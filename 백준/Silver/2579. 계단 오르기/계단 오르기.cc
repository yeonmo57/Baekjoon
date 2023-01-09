#include <iostream>
#include <algorithm>
using namespace std;

int dp[301];
int stairs[301];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}
	dp[0] = stairs[0];
	dp[1] = dp[0]+stairs[1];
	dp[2] = max(dp[0] + stairs[2], dp[1] + stairs[2]);
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i]);
	}
	cout << dp[n-1];
}