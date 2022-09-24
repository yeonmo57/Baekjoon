#include <iostream>
#define INF 987654321
using namespace std;

int n; //도시
int m; //버스
int arr[101][101] = { 0 };
int x, y, z;

int main() {
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = INF;

	for (int i = 1; i <= n; i++)
		arr[i][i] = 0;

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;

		if (arr[x][y] > z)
			arr[x][y] = z;
	}

	//중간 노드
	for (int k = 1; k <= n; k++) {
		//시작 노드
		for (int i = 1; i <= n; i++) {
			//도착 노드
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == INF) {
				cout << "0 ";
			}
			else {
				cout << arr[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}
