#include <iostream>
using namespace std;

int arr[1000001];
int start, end;
int n, k;
int idx, cnt, ans;
int x, y;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr[y] = x;
	}

	for (int i = 0; i < 1000001; i++) {
		if (i < 2 * k + 1) {
			cnt += arr[i];
			ans = cnt;
		}
		else {
			cnt = cnt - arr[i - 2 * k - 1] + arr[i];
			ans = max(ans, cnt);
		}
	}

	cout << ans;
}