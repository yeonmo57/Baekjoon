#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int c;
		cin >> c;
		
		int q = c / 25;
		int temp = c % 25;

		int d = temp / 10;
		temp %= 10;

		int n = temp / 5;
		temp %= 5;

		int p = temp;

		cout << q << " " << d << " " << n << " " << p << endl;
	}
}