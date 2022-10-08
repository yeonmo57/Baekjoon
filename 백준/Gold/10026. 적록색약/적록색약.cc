#include <iostream>
#include <cstring>

using namespace std;

int n, cnt = 0;
char graph[101][101];
bool is_visited[101][101] = {{false}};
int nx, ny;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void DFS(int x, int y)
{
    is_visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (!is_visited[nx][ny] && graph[x][y] == graph[nx][ny])
        {
            DFS(nx, ny);
        }
    }
}

int main(int argc, char* argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }

    //적록색약이 아님
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!is_visited[i][j])
            {
                DFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";

    //적록색약
    cnt = 0;
    memset(is_visited, false, sizeof(is_visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 'G') graph[i][j] = 'R';
            else continue;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!is_visited[i][j])
            {
                DFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";

    return 0;
}
