#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;

int check(int num, vector<bool>& broken)
{
	if (num == 0)
	{
		if (broken[0])
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	while (num > 0)
	{
		int digit = num % 10;
		if (broken[digit])
		{
			return false;
		}
		
		num /= 10;
		
	}
	return true;
}

int main()
{
	cin >> n >> m;
	vector<bool> broken(10, false);
	for (int i = 0; i < m; i++)
	{
		int button;
		cin >> button;
		broken[button] = true;
	}


	int answer = abs(n - 100);

	for (int i = 0; i <= 1000000; i++)
	{
		int len = to_string(i).size();
		if (check(i, broken))
		{
			int press = abs(i - n);
			answer = min(answer, press + len);
		}
	}
	cout << answer;
}