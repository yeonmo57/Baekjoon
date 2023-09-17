#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n + 1, 1); // 학생 배열 초기화, 0번 인덱스는 사용하지 않음

    for (int r : reserve) {
        student[r] = 2; // 여벌 체육복을 가진 학생 표시
    }

    for (int l : lost) {
        student[l] -= 1; // 도난당한 학생 표시
    }

    for (int i = 1; i <= n; i++) {
        if (student[i] == 0 && student[i - 1] == 2) {
            student[i - 1] = 1;
            student[i] = 1;
            continue;
        }
        if (student[i] == 0 && i < n && student[i + 1] == 2) {
            student[i + 1] = 1;
            student[i] = 1;
        }
    }

    for (int s : student) {
        if (s > 0) {
            answer++;
        }
    }

    return answer-1;
}
