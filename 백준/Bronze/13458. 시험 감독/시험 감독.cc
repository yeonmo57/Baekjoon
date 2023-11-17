#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, b, c;

vector<int> a;


int main()
{
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a.push_back(temp);
	}

	cin >> b >> c;

	long long answer = 0;

	for (int i = 0; i < n; i++)
	{
		int subSupervisor = a[i] - b;
		if (subSupervisor <= 0)
		{
			answer++;
		}
		else
		{
			if (subSupervisor % c == 0)
			{
				answer += (subSupervisor / c) + 1;
			}
			else
			{
				answer += (subSupervisor / c) + 2;
			}
		}
	}

	cout << answer;
}