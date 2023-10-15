#include <string>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int solution(int m, int n, vector<vector<int>> puddles)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[1][0] = 1; 
    
    for (const vector<int>& puddle : puddles)
    {
        dp[puddle[1]][puddle[0]] = -1; 
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dp[i][j] == -1)
            { 
                dp[i][j] = 0;
            } 
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            }
        }
    }

    return dp[n][m];
}