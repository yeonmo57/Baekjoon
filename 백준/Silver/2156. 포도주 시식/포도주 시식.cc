#include <iostream>
#include <vector>
using namespace std;

vector<int>wine;
vector<int> D;

int max(int a, int b) {
	return a > b ? a : b;
}

int DP() {
	for (int i = 3; i < wine.size(); i++) {
		D.push_back(max(max(D[i - 3] + wine[i - 1] + wine[i], D[i - 2] + wine[i]), D[i - 1]));
	}
	return D[wine.size() - 1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < 3; i++) {
		wine.push_back(0);
		D.push_back(0);
	}
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		wine.push_back(k);
	}
	cout << DP() << endl;;
}

