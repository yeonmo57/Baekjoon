#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    sort(dungeons.begin(), dungeons.end());
    
    do{
        int count = 0;
        int temp = k;
        
        for(int i=0; i<dungeons.size(); i++){
             if(temp>=dungeons[i][0]){
                 temp-=dungeons[i][1];
                 count++;
             }
        }
        answer = max(count, answer);
        
    }while (next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}