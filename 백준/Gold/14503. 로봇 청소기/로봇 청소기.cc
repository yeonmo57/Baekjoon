#include <iostream>
using namespace std;

int n, m;
int room[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int start_x, start_y, start_d;
int cnt = 0;

int find_direction(int _d)
{
    if (_d == 0)
    {
        return 3;
    }
    else
    {
        return _d - 1;
    }
}

void clean(int x, int y, int d)
{
    if (room[x][y] == 0)
    {
        room[x][y] = 2;
        cnt++;
    }
    
    for (int i = 0; i < 4; i++)
    {
        int nd = find_direction(d);
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        
        if (room[nx][ny] == 0)
        {
            clean(nx, ny, nd);
            return;
        }
        
        d = nd;
    }
    
    int back_d = find_direction(find_direction(d));
    int nx = x + dx[back_d];
    int ny = y + dy[back_d];
    
    if (room[nx][ny] != 1)
    {
        clean(nx, ny, d);
    }
}

int main()
{
    cin >> n >> m;
    cin >> start_x >> start_y >> start_d;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> room[i][j];
        }
    }
    
    clean(start_x, start_y, start_d);
    cout << cnt << endl;
    return 0;
}
