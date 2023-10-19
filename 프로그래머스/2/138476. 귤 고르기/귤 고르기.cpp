#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {    
    unordered_map<int, int> map;
    for (int i = 0; i < tangerine.size(); i++)
    {
        map[tangerine[i]]++;
    }
    
    vector<pair<int, int>> v(map.begin(), map.end());
    sort(v.begin(), v.end(), cmp);
    
    int tNum = 0;
    int tSize = 0;
    for(int i = 0; i < v.size(); i++)
    {
        tNum += v[i].second;
        tSize++;
        
        if(tNum >= k)
        {
            return tSize;
        }
    }
}