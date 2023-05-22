#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int temp1 = stoi(to_string(a) + to_string(b));
    int temp2 = 2 * a * b;
    answer = max(temp1, temp2);
    
    return answer;
}