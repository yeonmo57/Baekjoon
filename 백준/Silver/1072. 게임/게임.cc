#include <iostream>

using namespace std;
#define MAX 1000000000
int target = 0;
long long x, y, z;

int BinarySearch(int start, int end, int key) {
	if (start > end) {
		return start;
	}

	int mid = (start + end) / 2;
	target = ((y + mid) * 100) / (x + mid);

	if (target > z) {
		return BinarySearch(start, mid - 1, z);
	}
	else if (target <=z) {
		return BinarySearch(mid + 1, end, z);
	}
}

int main() {
	cin >> x >> y;
	z = (y * 100) / x;
	
	if (z >= 99) {
		cout << -1 << "\n";
		return 0;
	}

	int ans = BinarySearch(0, MAX, z);
	
	cout <<  ans << '\n';
}

