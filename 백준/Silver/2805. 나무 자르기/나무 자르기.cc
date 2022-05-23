#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m;

	long long temp = 0;
	int max = 0; 
	int ans = 0;
	vector <int> tree;

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		tree.push_back(a);
		if (a >= max) {
			max = a;
		}
	}

	int left = 0;
	int right = max;

	while (left <= right) {
		int mid = (left + right) / 2;
		temp = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > mid) temp += tree[i] - mid;
		}
	
		if (temp >= m) {
			if (ans < mid) {
				ans = mid;
			}
			left = mid + 1;

		}
		else {
			right = mid - 1;
		}
	}

	cout << ans << '\n';
}

