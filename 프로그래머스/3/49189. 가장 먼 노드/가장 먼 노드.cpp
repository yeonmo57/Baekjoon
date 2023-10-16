#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, 0);
    
    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1); 
    visited[1] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if (!visited[next]) {
                visited[next] = true;
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
    
    int max_dist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == max_dist) {
            answer++;
        }
    }
    
    return answer;
}
