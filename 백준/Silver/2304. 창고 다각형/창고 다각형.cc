#include<iostream>
#include<algorithm>
#include <stack>

using namespace std;

stack<int> height;
stack<int> width;
int n;
int arr[1001];
int x, y;
int l, r;
int ans;

int main() {
	height.push(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr[x] = y;

		if (height.top() < y) {
			width.push(x);
			height.push(y);
		}
	}

	for (int i = 1; i < width.top(); i++) {
		l = max(l, arr[i]);
		ans += l;
	}
	for (int i = 1000; i > width.top(); i--) {
		r = max(r, arr[i]);
		ans += r;
	}
	cout << ans + height.top();
}