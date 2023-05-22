#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string temp1 = to_string(a); 
    string temp2 = to_string(b);
    string str1 = temp1 + temp2;
    string str2 = temp2 + temp1;
    
    if(stoi(str1) >= stoi(str2))
    {
        answer = stoi(str1);
    }
    else
    {
        answer = stoi(str2);
    }
    return answer;
}