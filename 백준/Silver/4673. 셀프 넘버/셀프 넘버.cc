#include <iostream>
using namespace std;

int d(int n) {
	int num = n;
	while (n != 0)
	{
		num += n % 10;
		n = n / 10;
	}
	return num;
}

int main() {
	bool a[10001] = { false };

	for (int i = 1; i < 10001; i++)
	{
		int x = d(i);
		if (x < 10001)
			a[x] = true;
	}
	for (int j = 1; j < 10001; j++)
	{
		if (!a[j])
			cout << j << endl;
	}
}
