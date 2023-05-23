#include <iostream>
using namespace std;

int right_x;
int right_y;
int left_x;
int left_y;
int cnt = 0;
bool graph[101][101];

void calculate_area(int _left_x, int _left_y, int _right_x, int _right_y)
{
	for (int i = _left_x; i < _right_x; i++)
	{
		for (int j = _left_y; j < _right_y; j++)
		{
			if (graph[i][j] == true) 
			{
				continue;
			}
			graph[i][j] = true; 
			cnt++;
		}
	}
}
int main() 
{
	for (int i = 0; i < 4; i++)
	{
		cin >> left_x >> left_y >> right_x >> right_y;
		calculate_area(left_x, left_y, right_x, right_y);
	}
	cout << cnt << endl;
	return 0;
}