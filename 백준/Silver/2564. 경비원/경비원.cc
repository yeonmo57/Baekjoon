#include <iostream>
#include <vector>
using namespace std;

int width, height;
int store_num;
int dkDirection; 
int dkLocation;
int ans, dkPosition;
int calculatePosition(int d, int l)
{
	int pos;
	if (d == 1)
	{
		pos = 2 * (height + width) - l;
	}
	else if (d == 2)
	{
		pos = height + l;
	}
	else if (d == 3)
	{
		pos = l;
	}
	else
	{
		pos = height * 2 + width - l;
	}
	return pos;
}

int main()
{
	vector<pair<int, int>> store;
	cin >> width >> height;
	cin >> store_num;
	for (int i = 0; i < store_num; i++)
	{
		int direction, location;
		cin >> direction >> location;
		store.push_back(make_pair(direction, location));
	}
	cin >> dkDirection >> dkLocation;

	dkPosition = calculatePosition(dkDirection, dkLocation);

	for (int i = 0; i < store_num; i++)
	{
		int storePosition = calculatePosition(store[i].first, store[i].second);
		int distanceClockwise = abs(dkPosition - storePosition);
		int distanceCounterClockwise = abs(2 * (width + height) - distanceClockwise);
		ans += min(distanceClockwise, distanceCounterClockwise);
	}

	cout << ans;
}