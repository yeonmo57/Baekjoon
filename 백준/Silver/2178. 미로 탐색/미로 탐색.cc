#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int graph[101][101];
int visit[101][101];
int cnt[101][101];
queue<pair<int, int>> q;
int n, m;
void bfs(int a, int b) {
	visit[a][b] = true;
	cnt[a][b] = 1;
	q.push({ a,b });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && !visit[nx][ny] && graph[nx][ny] == 1) {
				visit[nx][ny] = true;
				cnt[nx][ny] = cnt[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++) {
			graph[i][j] = input[j] - '0';
		}
	}
	
	bfs(0, 0);
	cout << cnt[n - 1][m - 1];
	return 0;
}