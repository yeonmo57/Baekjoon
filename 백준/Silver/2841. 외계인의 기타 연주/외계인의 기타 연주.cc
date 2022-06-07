#include <iostream>
#include <stack>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	stack<int> s[7];
	int n, p, cnt=0;
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		while (!s[x].empty()) {
			if (s[x].top() > y) {
				s[x].pop();
				cnt++;
			}
			else break;
		}

		if (!s[x].empty()) {
			if (s[x].top() == y) {
				continue;
			}
		}

		s[x].push(y);
		cnt++;
	}
	cout << cnt;
	return 0;
}