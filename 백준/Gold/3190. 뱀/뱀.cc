#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool map[101][101];
int n, k, l; // 보드 크기, 사과 개수, 방향 변환 횟수
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

bool apple[101][101];
int dir[10001];
int d;
int main()
{
    // 뱀은 큐. 뱀의 길이가 선입 선출
    queue<pair<int, int>> snake;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        apple[x][y] = true;
    }
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int x;
        string s;
        cin >> x >> s;
        if (s == "L")
        {
            dir[x] = -1; // 왼쪽으로 회전
        }
        else
        {
            dir[x] = 1; // 오른쪽으로 회전
        }
    }

    int time = 0;
    snake.push(make_pair(1, 1));
    map[1][1] = true;
    d = 0;
    while (1)
    {
        time++;
        int x = snake.back().first;
        int y = snake.back().second;

        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 1 || nx > n || ny < 1 || ny > n)
        {
            break;
        }

        snake.push(make_pair(nx, ny));

        if (dir[time] == 1)
        {
            d += 1;
            if (d == 4) d = 0;
        }

        else if (dir[time] == -1)
        {
            d -= 1;
            if (d == -1) d = 3;
        }

        if (apple[nx][ny])
        {
            apple[nx][ny] = false;
        }
        else
        {
            if (map[nx][ny])
            {
                break;
            }
            map[snake.front().first][snake.front().second] = false;
            snake.pop();
        }

        map[nx][ny] = true;
    }
    cout << time;
    return 0;
}
