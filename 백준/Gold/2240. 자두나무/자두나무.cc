#include <iostream>
#include <algorithm>
using namespace std;

//dp[이동횟수][자두의 위치][흐른 시간] = 받은 자두의 수
int dp[31][2][1001];
int list[1001];
int t, w, ans;

int main() {
	cin >> t >> w;
	for (int i = 1; i <= t; i++) {
		cin >> list[i];
	}
	//이동
	for (int j = 0; j <= w; j++) {
		//시간
		for (int i = 1; i <= t; i++) {
			if (j == 0) {
				dp[j][0][i] = dp[j][0][i - 1] + (list[i] == 1);
			}
			else {
				dp[j][0][i] = max(dp[j][0][i - 1] + (list[i] == 1), dp[j - 1][1][i - 1] + (list[i] == 1));
				dp[j][1][i] = max(dp[j][1][i - 1] + (list[i] == 2), dp[j - 1][0][i - 1] + (list[i] == 2));
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= w; j++) {
			ans = max(ans, dp[j][i][t]);
		}
	}
	cout << ans;
}