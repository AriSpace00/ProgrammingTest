#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n = 0;
	cin >> m;
	cin >> n;

	vector<vector<int>> tomatoInfo;
	tomatoInfo.resize(n, vector<int>(m, -1));

	queue<pair<int, int>> bfs;

	vector<vector<int>> distance;
	distance.resize(n, vector<int>(m, -1));

	for (int i = 0; i < tomatoInfo.size(); i++)
	{
		for (int j = 0; j < tomatoInfo[i].size(); j++)
		{
			int temp = 0;
			cin >> temp;
			tomatoInfo[i][j] = temp;

			if (temp == 1)
			{
				bfs.push({ i, j });
				distance[i][j] = 0;
			}
		}
	}

	vector<int> dirX = {1, 0, -1, 0};
	vector<int> dirY = {0, 1, 0, -1};

	while (!bfs.empty())
	{
		pair<int, int> front = bfs.front();
		bfs.pop();

		for (int d = 0; d < 4; d++)
		{
			int x = front.first + dirX[d];
			int y = front.second + dirY[d];

			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;
			if (tomatoInfo[x][y] == -1 || distance[x][y] >= 0)
				continue;

			distance[x][y] = distance[front.first][front.second] + 1;
			bfs.push({ x, y });
		}
	}

	int maxValue = 0;
	for (int i = 0; i < tomatoInfo.size(); i++)
	{
		for (int j = 0; j < tomatoInfo[i].size(); j++)
		{
			if (tomatoInfo[i][j] == 0 && distance[i][j] == -1)
			{
				cout << -1;
				return 0;
			}

			maxValue = max(maxValue, distance[i][j]);
		}
	}

	cout << maxValue;

	return 0;
}
