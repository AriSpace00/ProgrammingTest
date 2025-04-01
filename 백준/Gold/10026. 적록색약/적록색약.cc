#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<char>> temp;
vector<vector<bool>> visited;
queue<pair<int, int>> bfs;
vector<int> dirX = { 1, 0, -1, 0 };
vector<int> dirY = { 0, 1, 0, -1 };
int n = 0;

void bfsAlgorithm(int i, int j)
{
	bfs.push({ i,j });
	visited[i][j] = true;

	while (!bfs.empty())
	{
		pair<int, int> current = bfs.front();
		bfs.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int x = current.first + dirX[dir];
			int y = current.second + dirY[dir];

			if (x < 0 || x >= n || y < 0 || y >= n)
				continue;
			if (visited[x][y] || temp[x][y] != temp[current.first][current.second])
				continue;

			visited[x][y] = true;
			bfs.push({ x, y });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	temp.resize(n, vector<char>(n, 'T'));
	visited.resize(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char t = '\0';
			cin >> t;
			temp[i][j] = t;
		}
	}

	int count = 0, count_rg = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j])
				continue;

			count++;
			bfsAlgorithm(i, j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = false;
			if (temp[i][j] == 'R')
				temp[i][j] = 'G';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j])
				continue;

			count_rg++;
			bfsAlgorithm(i, j);
		}
	}

	cout << count << " " << count_rg;

	return 0;
}