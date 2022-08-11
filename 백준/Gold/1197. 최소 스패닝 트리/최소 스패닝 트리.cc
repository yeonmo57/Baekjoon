#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000 + 1
using namespace std;

int Vertex; //정점의 개수
int E; //간선의 개수
int Answer;
int Parent[MAX];
//<가중치, pair<노드1,노드2>> 가중치에 대해 오름차순 정렬
vector<pair<int, pair<int, int>>> V;

void Input()
{
	cin >> Vertex >> E;
	for (int i = 0; i < E; i++)
	{
		int From, To, Cost;
		cin >> From >> To >> Cost;

		V.push_back(make_pair(Cost, make_pair(From, To)));
	}

	sort(V.begin(), V.end());
}

int Find(int x)
{
	//노드 x의 부모를 찾는 함수
	if (Parent[x] == x) return x;
	else return Parent[x] = Find(Parent[x]);
}

void Union(int x, int y)
{
	//서로 다른 부모일 경우, 두 개의 노드를 연결해주는 함수
	x = Find(x);
	y = Find(y);
	if (x != y) Parent[y] = x;
}

bool SameParent(int x, int y)
{
	//서로 같은 부모를 갖는지 판단해주는 함수
	x = Find(x);
	y = Find(y);

	if (x == y) return true;
	else return false;
}

void Solution()
{
	for (int i = 1; i <= Vertex; i++)
	{
		Parent[i] = i;
	}

	for (int i = 0; i < E; i++)
	{
		//가중치가 낮은 노드부터 
		if (SameParent(V[i].second.first, V[i].second.second) == false)
		{
			//노드의 부모가 다른 경우, 연결
			Union(V[i].second.first, V[i].second.second);
			Answer = Answer + V[i].first; //가중치 더함
		}
	}
}

void Solve()
{
	Input();
	Solution();
	
	cout << Answer << '\n';
}

int main(void)
{
	Solve();
	return 0;
}