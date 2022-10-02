#include <iostream>
using namespace std;

long long a, b, c, temp;

long long mul(long long b) {
	if (b == 0) return 1;

	temp = mul(b / 2) % c;
	if (b % 2) {
		return (temp * temp) %c * a % c;
	}
	else {
		return (temp * temp) % c;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	
	cin >> a >> b >> c;
	cout << mul(b) << endl;
	return 0;
}

