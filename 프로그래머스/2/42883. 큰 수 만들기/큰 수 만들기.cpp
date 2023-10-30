#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int n = number.size();
    int keep = n - k; // 남겨야 하는 숫자의 개수
    
    int start = 0; // 현재 선택할 숫자의 시작 인덱스
    
    for (int i = 0; i < keep; i++) {
        char maxDigit = number[start]; // 현재 범위에서 가장 큰 숫자
        int maxIndex = start;
        
        for (int j = start; j <= n - keep + i; j++) {
            if (number[j] > maxDigit) {
                maxDigit = number[j];
                maxIndex = j;
            }
        }
        
        start = maxIndex + 1; // 다음 범위의 시작을 조정
        answer += maxDigit;
    }
    
    return answer;
}
