#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer, cost(n + 1, -1), map[100001];
    for(auto road : roads)
    {
        map[road[0]].push_back(road[1]);
        map[road[1]].push_back(road[0]);
    }
    
    queue<pair<int, int>> q;
    q.push({destination, 0}); // 시작 지점, 누적 cost
    cost[destination] = 0;
    
    while(!q.empty())
    {
        int curPos = q.front().first;
        int curCost = q.front().second;
        q.pop();
        
        for(auto nextPos : map[curPos])
        {
            if (cost[nextPos] == -1 || cost[nextPos] > curCost + 1)
            {
                q.push({nextPos, curCost + 1});
                cost[nextPos] = curCost + 1;
            }
        }
    }
    
    for (auto src : sources) answer.push_back(cost[src]);
    return answer;
}