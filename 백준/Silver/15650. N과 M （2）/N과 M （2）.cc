#include <iostream>

using namespace std;
#define MAX 9

int N,M;
int arr[MAX];

void dfs(int num, int k) {
    if(k==M) { 
        for(auto i =0;i<M;i++)
            cout << arr[i] << " ";
        cout << "\n";
    } else { 
        for(auto i=num; i<=N;i++) {
            arr[k]=i; 
            dfs(i+1,k+1);
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(1,0);
}
