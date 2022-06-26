#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		vector<pair<int, int>> lank;

		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			lank.push_back({ x,y });
		}
		sort(lank.begin(), lank.end());

		int max = lank[0].second;
		int count = 0;

		for (int i = 0; i < N; i++) {
			if (lank[i].second <= max) {
				count++;
				max = lank[i].second;
			}
		}
		cout << count << "\n";
	}
}