#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;
	
	string apparel, name;

	
	while (t--) {
		map<string, int> m;
		cin >> n;
		while (n--) {
			cin >> name >> apparel;
			//해당 종류가 존재하지 않을 때
			if (m.find(apparel) == m.end()) {
				m.insert({ apparel, 1 });
			}
			else {
				//이미 있을 경우에는 개수 1 증가
				m[apparel]++;
			}
		}

		int ans = 1;
		auto iter = m.begin();
		while (iter != m.end()) {
			ans *= (iter->second + 1);

			iter++;
		}
		ans -= 1;
		cout << ans << "\n";
	}
	return 0;
}