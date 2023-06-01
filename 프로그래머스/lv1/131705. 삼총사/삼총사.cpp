#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(vector<int>& numbers, int sum, int cnt, int index)
{
    if(cnt == 3)
    {
        if(sum == 0)
        {
            answer++;
        }
        return;
    }
    
    for(int i = index; i < numbers.size(); i++)
    {
        dfs(numbers, sum + numbers[i], cnt + 1, i + 1);
    }
}

int solution(vector<int> number) {
    
    for(int i = 0; i < number.size(); i++)
    {
        dfs(number, number[i], 1, i + 1);
    }
    return answer;
}