#include <iostream>
#include <vector>
using namespace std;

int sum(int num) {
	vector<int> DP(11,0);
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	for (int i = 4; i <=num; i++) {
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	}
	return DP[num];
}

int main() {
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << sum(n) << "\n";
	}
}
