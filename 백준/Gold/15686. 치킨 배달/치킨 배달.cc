#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int map[51][51];
int n, m;
vector<pair<int, int>> chicken; // 치킨집 위치 저장
vector<pair<int, int>> house; // 집 위치 저장
vector<bool> selected; // 선택된 치킨집 표시
int answer = INF; // 최소 도시의 치킨 거리

// 치킨 거리 계산
int calculateDistance() {
    int totalDistance = 0; // 도시의 치킨 거리 합

    for (const auto& h : house) {
        int dist = INF; // 각 집의 치킨 거리 초기화

        for (int i = 0; i < chicken.size(); i++) {
            if (selected[i]) {
                int chickenDist = abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second);
                dist = min(dist, chickenDist);
            }
        }

        totalDistance += dist; // 도시의 치킨 거리 합산
    }

    return totalDistance;
}

// 치킨집 선택을 위한 조합
void selectChicken(int idx, int cnt) {
    if (cnt == m) { // m개의 치킨집을 선택한 경우
        int distance = calculateDistance(); // 도시의 치킨 거리 계산
        answer = min(answer, distance); // 최소 도시의 치킨 거리 갱신
        return;
    }

    if (idx == chicken.size()) { // 더 이상 선택할 치킨집이 없는 경우
        return;
    }

    // 현재 치킨집 선택
    selected[idx] = true;
    selectChicken(idx + 1, cnt + 1);

    // 현재 치킨집 선택하지 않음
    selected[idx] = false;
    selectChicken(idx + 1, cnt);
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];

            if (map[i][j] == 1) { // 집인 경우
                house.push_back({ i, j });
            } else if (map[i][j] == 2) { // 치킨집인 경우
                chicken.push_back({ i, j });
            }
        }
    }

    selected.resize(chicken.size(), false); // 선택된 치킨집을 표시하기 위한 벡터 초기화
    selectChicken(0, 0); // 치킨집 선택

    cout << answer << endl;

    return 0;
}
