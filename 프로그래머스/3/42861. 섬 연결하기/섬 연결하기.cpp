#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> island(101);

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int findParent(int idx)
{
    if(island[idx] == idx)
        return idx;
    return island[idx] = findParent(island[idx]);
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    
    for(int i=0; i<n; i++)
    {
        island[i] = i;
    }

    sort(costs.begin(), costs.end(), cmp);
    
    for(int i=0; i<costs.size(); i++)
    {
        int start = findParent(costs[i][0]);
        int end = findParent(costs[i][1]);
        int cost = costs[i][2];
        
        if(start!=end)
        {
            answer+=cost;
            island[end] = start;
        }
        
    }
    
    return answer;
}