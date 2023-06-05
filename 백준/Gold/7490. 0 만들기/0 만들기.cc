#include<iostream>
#include<string>
using namespace std;
int N;
void solve(int sum, int sign, int num, int n, string str)
{
    if (n == N)
    {
        sum += (num * sign);
        if (sum == 0)
        {
            cout << str << '\n';
        }
    }
    else
    {
        solve(sum, sign, num * 10 + (n + 1), n + 1, str + ' ' + char(n + 1 + '0'));
        solve(sum + (sign*num), 1, n + 1, n + 1, str + '+' + char(n + 1 + '0'));
        solve(sum + (sign*num), -1, n + 1, n + 1, str + '-' + char(n + 1 + '0'));
    }
}
int main()
{
    int test_case;
    char test;
    scanf("%d", &test_case);
    for (int i = 0; i < test_case; i++)
    {
        scanf("%d", &N);
        solve(0, 1, 1, 1, "1");// sum, sign, num, n, str
        printf("\n");
    }
    return 0;
}
