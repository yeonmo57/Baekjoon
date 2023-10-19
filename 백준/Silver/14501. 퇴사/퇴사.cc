#include <iostream>
 
using namespace std;
 
int t[1000] = { 0, };
int p[1000] = { 0, };
int dp[1000] = { 0, };
 
int max(int x, int y)
{
    return x > y ? x : y;
}
 
int main()
{
    int N;
    int next;
 
    cin >> N;
 
    for (int i = 1;i <= N;i++) {
        cin >> t[i] >> p[i];
    }
 
    for (int i = N;i > 0;i--) {
        next = i + t[i];
        if (next > N + 1) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i + 1], dp[next] + p[i]);
        }
 
    }
 
    cout << dp[1] << endl;
 
    return 0;
}