#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size(); 
    int turn = n - 1;
    for (int i = 0; i < name.size(); i++)
    {
        char temp = name[i] - 'A';

        if (temp > 13)
        {
            temp = 26 - temp;
        }
        answer += temp;
        
        int ind = i + 1;
        while(ind < n && name[ind] == 'A') ind++;
        
        turn = min(turn, i + n - ind + min(i, n - ind));
    }

    answer += turn;
    return answer;
}