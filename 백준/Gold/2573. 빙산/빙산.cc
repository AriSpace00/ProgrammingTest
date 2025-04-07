#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n = 0, m = 0;
vector<vector<int>> field;
vector<vector<bool>> visited;
vector<int> dirX = { 1, 0, -1, 0 };
vector<int> dirY = { 0, 1, 0, -1 };

void melting()
{
	vector<vector<int>> zero;
	zero.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (field[i][j] > 0)
			{
				for (int d = 0; d < 4; d++)
				{
					int nextX = i + dirX[d];
					int nextY = j + dirY[d];

					if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m)
						continue;
					if (field[nextX][nextY] == 0)
						zero[i][j]++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			field[i][j] = max(0, field[i][j] - zero[i][j]);
		}
	}
}

int status()
{
	int x = 0, y = 0;
	int cnt1 = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (field[i][j] > 0)
			{
				x = i;
				y = j;
				cnt1++;
			}
		}
	}

	if (cnt1 == 0)
		return 0;

	int cnt2 = 0;

	queue<pair<int, int>> bfs;
	bfs.push({x, y});
	visited[x][y] = true;

	while (!bfs.empty())
	{
		pair<int, int> current = bfs.front();
		bfs.pop();

		cnt2++;

		for (int d = 0; d < 4; d++)
		{
			int nextX = current.first + dirX[d];
			int nextY = current.second + dirY[d];

			if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m)
				continue;
			if (field[nextX][nextY] <= 0 || visited[nextX][nextY])
				continue;

			visited[nextX][nextY] = true;
			bfs.push({nextX, nextY});
		}
	}

	if (cnt1 == cnt2)
		return 1;
	return 2;
}

void initVisited()
{
	for (int i = 0; i < visited.size(); i++)
	{
		for (int j = 0; j < visited[i].size(); j++)
		{
			visited[i][j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	field.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> field[i][j];
		}
	}

	int year = 0;
	while (true)
	{
		year++;
		melting();
		initVisited();

		switch (status())
		{
		case 0:
		{
			cout << 0;
			return 0;
		}
		break;
		case 1:
		{
			continue;
		}
		break;
		default:
		{
			cout << year;
			return 0;
		}
		break;
		}
	}

	return 0;
}