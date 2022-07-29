#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001

int n,m;
int map[MAX][MAX] = { 0 };
bool visit[MAX][MAX] = { 0 };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
//queue<pair<int, int>> q;

int main()
{
	cin >> m >> n;
	queue<pair<int, int>> q;
	//토마토 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				q.push({ i,j });
			}
		}
	}

	//bfs
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visit[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && map[nx][ny] == 0 && !visit[nx][ny])
			{
				map[nx][ny] = map[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}

	int max = -1;
	bool check = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				check = false; //덜 익은게 남아있음
			}
			if (map[i][j] > max)
			{
				max = map[i][j]; //가장 멀리까지 온 값
			}
		}
	}

	if (check)
	{
		cout << max - 1 << '\n';
	}
	else 
	{
		cout << -1 << '\n';
	}
	
	return 0;
}