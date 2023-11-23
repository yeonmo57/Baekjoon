#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
vector<int> graph[32001];
int inDegree[32001];
int N, M;
 
void TopologicalSort(void){
    queue<int> q;
    
    for(int i = 1; i <= N; i++)
        if(!inDegree[i])
            q.push(i);
        
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int i = 0; i < graph[cur].size(); i++){
            inDegree[graph[cur][i]]--;
            if(!inDegree[graph[cur][i]])
                q.push(graph[cur][i]);
        }
    }
}
 
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }
    
    TopologicalSort();
    
    return 0;
}
 
