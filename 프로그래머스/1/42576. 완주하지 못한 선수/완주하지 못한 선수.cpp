#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> runner;
    
    for(auto p:participant)
    {
        runner[p]++;
    }
     
    for(auto c:completion)
    {
        runner[c]--;
    }
    
    for(auto r:runner)
    {
        if(r.second == 1)
        {
            answer = r.first;
        }
    }
    
    return answer;
}