#include <iostream>

using namespace std;

void hanoi(int N, int start, int to, int bypass) {
	//어떤 장대를 지나쳐서 가는지:bypass
	if (N == 1) {
		printf("%d %d\n", start, to);
	}
	else {
		hanoi(N - 1, start, bypass, to);
		printf("%d %d\n", start, to);
		hanoi(N - 1, bypass, to, start);
	}
}

int main() {
	int N;
	cin >> N;
	cout << (1 << N) - 1 << "\n";
	hanoi(N, 1, 3, 2);
}