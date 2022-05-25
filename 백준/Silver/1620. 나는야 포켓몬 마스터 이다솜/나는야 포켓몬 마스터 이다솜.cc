#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	//숫자를 이용해 문자열
	unordered_map<int, string> mapNum;
	//문자열을 키로 사용해 숫자를 가져오기 위한 맵(딕셔너리)
	unordered_map<string, int> mapStr;
	
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		mapNum[i] = name;
		mapStr[name] = i;
	}

	while (m--) {
		char test[21];
		cin >> test;
		if (test[0] < 'A') {
			cout << mapNum[atoi(test)] << '\n';
		}
		else {
			cout << mapStr[test] << '\n';
		}
	}
	return 0;
}

