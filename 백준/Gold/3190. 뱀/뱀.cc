#include <iostream>
#include <queue>

using namespace std;

bool Is_There_Snake[101][101];
int n, k, l; // 보드 크기, 사과 개수, 방향 변환 횟수
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool board[101][101];
char dir[10001];
int now_Direction;
int main()
{
	// 뱀은 큐. 뱀의 길이가 선입 선출
	queue<pair<int, int>> snake;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = true;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		dir[x] = c;
	}

	int answer_Time = 0;
	snake.push(make_pair(1, 1));
	Is_There_Snake[1][1] = true;
	now_Direction = 0;
	while (1)
	{
		answer_Time++;

		int next_col = snake.back().first + dy[now_Direction];
		int next_row = snake.back().second + dx[now_Direction];

		if (next_col < 1 || next_col > n || next_row < 1 || next_row > n)
		{
			break;
		}

		snake.push(make_pair(next_col, next_row));

		if (dir[answer_Time] == 'D') //L
		{
			now_Direction += 1;
			if (now_Direction == 4) now_Direction = 0;
		}
		else if (dir[answer_Time] == 'L')
		{
			now_Direction -= 1;
			if (now_Direction == -1) now_Direction = 3;
		}


		if (board[next_col][next_row] == 1)
		{
			board[next_col][next_row] = 0;
		}
		else
		{
			if (Is_There_Snake[next_col][next_row] == 1)
			{
				break;
			}
			Is_There_Snake[snake.front().first][snake.front().second] = false;
			snake.pop();
		}

		if (Is_There_Snake[next_col][next_row] == 1)
		{
			break;
		}
		else
		{
			Is_There_Snake[next_col][next_row] = 1;
		}
	}
	cout << answer_Time;
}