#include <iostream>
#include <queue>

using namespace std;

const int MAX_POSITION = 100000;
bool visited[MAX_POSITION + 1] = { false };

int startPosition, target;

void VisitNextPosition(queue<pair<int, int>>& q, int position, int time)
{
	if (position >= 0 && position <= MAX_POSITION && !visited[position])
	{
		q.push(make_pair(position, time));
		visited[position] = true;
	}
}

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

		VisitNextPosition(map, currentPosition - 1, currentTime + 1);
		VisitNextPosition(map, currentPosition + 1, currentTime + 1);
		VisitNextPosition(map, currentPosition * 2, currentTime + 1);
	}
}

int main()
{
	cin >> startPosition >> target;
	
	int result = bfs();
	cout << result;

	return 0;
}