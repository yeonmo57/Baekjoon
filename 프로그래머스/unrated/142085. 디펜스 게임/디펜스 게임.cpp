#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    // 우선 순위 큐
    priority_queue<int> pq;
    
    for(int i = 0; i < enemy.size(); i++)
    {
        if(n >= enemy[i])
        {
            n -= enemy[i];
            pq.push(enemy[i]);
        }
        else if(n < enemy[i] && k > 0)
        {
            n -= enemy[i];
            pq.push(enemy[i]);
            n += pq.top();
            pq.pop();
            k--;
        }
        else if (k <= 0)
        {
            return i;
        }        
    }
    return enemy.size();
}