#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int arr[51][51];
int visit[51][51];
int n;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

typedef pair<int, pair<int, int> > p;

void BFS() {
    priority_queue<p, vector<p>, greater<p> > pq;
    pq.push(p(0, make_pair(1, 1)));
    memset(visit, 10000, sizeof(visit));
    visit[1][1] = 0;

    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(x==n && y==n) return;

        for(int i=0 ; i<4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<=0 || nx>n || ny<=0 || ny>n) continue;
            int tmp = 1-arr[nx][ny];
            if(visit[nx][ny] > visit[x][y] + tmp) {
                visit[nx][ny] = visit[x][y] + tmp;
                pq.push(p(visit[nx][ny], make_pair(nx,ny)));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        string s;
        cin >> s;
        for(int j=1 ; j<=s.size() ; j++) {
            arr[i][j] = s[j-1] - '0';
        }
    }
    BFS();
    cout << visit[n][n] << "\n";
}