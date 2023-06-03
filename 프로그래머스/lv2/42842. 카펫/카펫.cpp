#include <string>
#include <vector>

using namespace std;


vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = brown + yellow;
    for(int i = 3; i <= area; i++)
    {
        if(area % i == 0)
        {
            int width = area / i;
            if((width - 2) * (i - 2) == yellow)
            {
                answer.push_back(width);
                answer.push_back(i);
                break;
            }
        }
    }
    
    return answer;
}