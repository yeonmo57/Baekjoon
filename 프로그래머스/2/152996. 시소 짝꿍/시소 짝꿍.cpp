#include <string>
#include <vector>
#include <map>
using namespace std;
int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
long long solution(vector<int> weights) {
    map<int, int> m;
    long long answer = 0;
    for(int i:weights)
        m[i]++;
    for(auto i:m){
        for(int f=0; f<i.second-1; f++)
            for(int s=f+1; s<i.second; s++)
                answer++;//같은 몸무게인 사람이 여러명일 때 그 사람들끼리의 쌍의 수
        for(auto j:m){
            if(i.first != j.first){
                int LCM = lcm(i.first, j.first);
                if(LCM == j.first){//최소공배수가 조합중의 한값일때
                    LCM *= 2;
                }
                if(LCM/min(i.first, j.first)<5){
                    answer+=i.second*j.second;
                }
            }
        }
        m.erase(i.first);
    }

    return answer;
}