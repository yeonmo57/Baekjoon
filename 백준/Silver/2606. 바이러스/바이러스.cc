#include <iostream>
#include <vector>

using namespace std;

int map[101][101] = { 0 };
int visit[101] = { 0 };
int num, ans = 0;

void dfs(int n) {
	ans++;
	visit[n] = 1; //어떤 컴퓨터를 방문했는지
	for (int i = 1; i <= num; i++) 
	{
		if (map[n][i] && !visit[i]) //방문한 적 없으며 연결되어있으면
			dfs(i); //방문한다
	}
}

int main() 
{
	int n;
	int x, y;
	cin >> num >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}

	dfs(1);
	cout << ans - 1;
}
