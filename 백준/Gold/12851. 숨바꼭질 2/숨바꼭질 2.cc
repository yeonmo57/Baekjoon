#include <stdio.h>
#include <queue>
using namespace std;

int visit[100005];

int main(){
	int n,k;
	int ans1 = 987654321;
	int	ans2 = 0;
	queue<pair<int,int> > q;
	
	scanf("%d %d",&n,&k);

	q.push(make_pair(n,0));
	
	while(!q.empty()){
		int x = q.front().first;
		int num = q.front().second;
		q.pop();
		
		visit[x] = 1;
		
		if(ans1<num) break;
		
		if(x==k){
			ans1 = num;
			ans2++;
			continue;
		}
		
		if(x-1>=0 && !visit[x-1])
			q.push(make_pair(x-1,num+1));
		if(x+1<=100000 && !visit[x+1])
			q.push(make_pair(x+1,num+1));
		if(x*2<=100000 && !visit[x*2])
			q.push(make_pair(x*2,num+1));
	}
	
	printf("%d\n%d",ans1,ans2);
	
	return 0;
}