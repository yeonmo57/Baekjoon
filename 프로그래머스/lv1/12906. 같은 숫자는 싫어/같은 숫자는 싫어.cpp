#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> s;
    vector<int> answer;
    
    s.push(arr[0]);
    answer.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++)
    {
        if(s.top() != arr[i])
        {
            s.push(arr[i]);
            answer.push_back(arr[i]);
        }
    }

    return answer;
}