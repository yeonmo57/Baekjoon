#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define MAX 25
 
int N;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int cnt;
 
vector<int> cnt_vec;
 
void dfs(int x, int y){
    cnt++;
    visited[x][y] = true;
 
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(arr[nx][ny] == 1 && visited[nx][ny] == false)
            dfs(nx, ny);
    }
}
 
 
int main(int argc, const char * argv[]) {
    string line;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> line;
        for(int j = 0; j < N; j++){
            arr[i][j] = line[j] - '0';
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] == 1 && visited[i][j] == false){
                cnt = 0;
                dfs(i, j);
                cnt_vec.push_back(cnt);
            }
        }
    }
    
    sort(cnt_vec.begin(), cnt_vec.end());
    cout << cnt_vec.size() << '\n';
    for(int i = 0; i < cnt_vec.size(); i++)
        cout << cnt_vec[i] << '\n';
    
    return 0;
}
