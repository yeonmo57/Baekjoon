#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    // bfs로.
    // 노드를 양방향 그래프로 구현
    // 큐에 출발 점을 넣는다.
    // 출발점에서 갈 수 있는 점들을 탐색한다.
    // 방문체크
    int answer = 0;
    
    vector<vector<int>> graph(n + 1);
    for(auto e:edge)
    {
        int a = e[0]; 
        int b = e[1];
        graph[a].push_back(b); // 이거 하려면 동적할당 ㄴㄴ
        graph[b].push_back(a);
    }
    
    vector<bool> visited(n + 1, false);
    queue<int> q;
    vector<int> dist(n+1, 0);
    // 1번 노드에서 시작
    q.push(1);
    visited[1] = true;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i];
            
            if(visited[next] == false)
            {
                // 방문체크를 까먹었군
                visited[next] = true;
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
    
    int max_dist = 0;
    
    for(int i = 0; i < dist.size(); i++)
    {
        if(max_dist < dist[i])
            max_dist = dist[i];
    }
    
    for(int i = 0; i < dist.size(); i++)
    {
        if(dist[i] == max_dist)
            answer++;
    }
    
    return answer;
}
