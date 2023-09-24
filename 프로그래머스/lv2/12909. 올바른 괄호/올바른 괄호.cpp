#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<int> temp;
    
    // 스택 제일 최근꺼 조회되는 특성
    // )가 나오면 앞에 (를 없앤다
    // 앞에 )가 있을 리가 없으니까 고려 ㄴ 왜냐면 (을 만나면 스택에 넣지도 않고 쌍을 만들어 pop해버림
    // 앞에 아무것도 없다? return false
    // 
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            temp.push('(');
        }
        else if(s[i] == ')')
        {
            if(temp.empty())
            {
                answer = false;
                return answer;     
            }
            else if(temp.top() == '(')
            {
                temp.pop();
            }
        }
    }

    if(!temp.empty() && temp.top() == '(')
    {
        answer = false;
        return answer;
    }

    return answer;
}