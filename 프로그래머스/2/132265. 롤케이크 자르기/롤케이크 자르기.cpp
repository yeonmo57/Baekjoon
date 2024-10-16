#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int, int> ro1, ro2;
    
    for (int i : topping){
        ro2[i]++;
    }

    for (int i : topping){
        ro1[i]++;
        ro2[i]--;
        
        if (ro2[i] == 0){
            ro2.erase(i);
        } 
        
        if (ro1.size() == ro2.size())
        {
            answer++;
        }

    }

    return answer;
}