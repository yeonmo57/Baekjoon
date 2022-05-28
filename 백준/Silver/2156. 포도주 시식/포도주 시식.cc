#include <iostream>

using namespace std;

int arr[10000];
int dp[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (dp[i] < dp[i - 2] + arr[i]) {
			dp[i] = dp[i - 2] + arr[i];
		}
		if (dp[i] < dp[i - 3] + arr[i - 1] + arr[i]) {
			dp[i] = dp[i - 3] + arr[i - 1] + arr[i];
		}
	}
	cout << dp[n] << '\n';
}

