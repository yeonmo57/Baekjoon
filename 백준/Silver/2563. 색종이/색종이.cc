#include <iostream>
using namespace std;

bool whitepaper[101][101] = {0, };
int colorpapernumber, ans;

void color(int x, int y)
{
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 10; j++)
		{
			whitepaper[x + i][y + j] = true;
		}
	}
}

int areacalculate(bool graph[101][101])
{
	int area = 0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (graph[i][j])
			{
				area++;
			}
		}
	}

	return area;
}

int main() {
	cin >> colorpapernumber;

	for (int i = 0; i < colorpapernumber; i++)
	{
		int xpoint, ypoint;
		cin >> xpoint >> ypoint;
		color(xpoint, ypoint);
	}

	ans = areacalculate(whitepaper);

	cout << ans;
}