#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int x[1000005];
vector<int> tmp, uni;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		uni.push_back(x[i]);
	}
	sort(uni.begin(), uni.end());
	uni.erase(unique(uni.begin(), uni.end()), uni.end());
	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
	}
}