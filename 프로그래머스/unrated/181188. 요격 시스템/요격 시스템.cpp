#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;

    sort(targets.begin(), targets.end());
    vector<vector<int>> currentTarget;
    currentTarget.push_back({0, 0});
    for(int i = 0; i < targets.size(); i++)
    {
        if(targets[i][0] >= currentTarget[0][1])
        {
            answer++;
            currentTarget[0] = targets[i];
        }
        else
        {
            if(targets[i][0] <= currentTarget[0][0]) 
            {
                currentTarget[0][0] = targets[i][0];
            }
        
            if(targets[i][1] <= currentTarget[0][1])
            {
                currentTarget[0][1] = targets[i][1];
            }
        }
            
        
    }
    
    return answer;
}