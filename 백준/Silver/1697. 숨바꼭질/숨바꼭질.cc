#include <iostream>
#include <queue>

using namespace std;

const int MAX_POSITION = 100000;
bool visited[MAX_POSITION + 1] = { false };

int startPosition, target;

int bfs()
{
	queue<pair<int, int>> map;
	map.push(make_pair(startPosition, 0));
	visited[startPosition] = true;

	while (!map.empty())
	{
		int currentPosition = map.front().first;
		int currentTime = map.front().second;
		map.pop();

		if (currentPosition == target)
		{
			return currentTime;
		}

		if (currentPosition - 1 >= 0 && !visited[currentPosition - 1])
		{
			map.push(make_pair(currentPosition - 1, currentTime + 1));
			visited[currentPosition - 1] = true;
		}
		if (currentPosition + 1 <= MAX_POSITION && !visited[currentPosition + 1])
		{
			map.push(make_pair(currentPosition + 1, currentTime + 1));
			visited[currentPosition + 1] = true;
		}
		if (currentPosition * 2 <= MAX_POSITION && !visited[currentPosition * 2])
		{
			map.push(make_pair(currentPosition * 2, currentTime + 1));
			visited[currentPosition * 2] = true;
		}
	}
}

int main()
{
	cin >> startPosition >> target;
	
	int result = bfs();
	cout << result;

	return 0;
}