#include <iostream>
using namespace std;

bool han (int n)
{
	int a = 0, b = 0, c = 0;
	a = n / 100;
	b = (n % 100) / 10;
	c = n % 10;

	int temp1, temp2;
	temp1 = a - b;
	temp2 = b - c;
	if (n < 100 || temp1 == temp2) return true;
	else return false;
}

int main() {
	int n;
	cin >> n;

	int num = 0;

	for (int i = 1; i < n+1; i++)
	{
		if (han(i) == true)
			num += 1;
	}

	cout << num << endl;

	return 0;
}