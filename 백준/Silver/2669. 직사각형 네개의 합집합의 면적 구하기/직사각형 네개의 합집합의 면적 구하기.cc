#include <iostream>
using namespace std;

int main() {
    int graph[101][101] = {0}; // 직사각형의 면적을 저장할 배열

    // 직사각형 입력받고 면적 표시
    for (int i = 0; i < 4; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                graph[x][y] = 1;
            }
        }
    }

    // 면적 계산
    int area = 0;
    for (int x = 0; x < 101; x++) {
        for (int y = 0; y < 101; y++) {
            if (graph[x][y] == 1) {
                area++;
            }
        }
    }

    cout << area << endl;

    return 0;
}
