#include <iostream>
#include <algorithm>
using namespace std;

int n;
int sequence[11];
int operatorArr[4];
int maxResult = -1e9;  
int minResult = 1e9;  

void Calculate(int idx, int result, int plus, int minus, int multiply, int divide)
{
	if (idx == n)
	{
		maxResult = max(maxResult, result);
		minResult = min(minResult, result);
		return;
	}

	if (plus > 0)
		Calculate(idx + 1, result + sequence[idx], plus - 1, minus, multiply, divide);
	if (minus > 0)
		Calculate(idx + 1, result - sequence[idx], plus, minus - 1, multiply, divide);
	if (multiply > 0)
		Calculate(idx + 1, result * sequence[idx], plus, minus, multiply - 1, divide);
	if (divide > 0)
		Calculate(idx + 1, result / sequence[idx], plus, minus, multiply, divide - 1);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> sequence[i];

	for (int i = 0; i < 4; i++)
		cin >> operatorArr[i];

	Calculate(1, sequence[0], operatorArr[0], operatorArr[1], operatorArr[2], operatorArr[3]);

	cout << maxResult << endl;
	cout << minResult << endl;

	return 0;
}
