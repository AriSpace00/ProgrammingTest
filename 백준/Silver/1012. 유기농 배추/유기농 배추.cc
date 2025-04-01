#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int m, n, k = 0;
		cin >> m >> n >> k;

		vector<vector<int>> field;
		field.resize(m, vector<int>(n, 0));

		vector<vector<bool>> visited;
		visited.resize(m, vector<bool>(n, false));

		for (int j = 0; j < k; j++)
		{
			int x, y = 0;
			cin >> x >> y;

			field[x][y] = 1;
		}

		vector<int> dirX = {1, 0, -1, 0};
		vector<int> dirY = {0, 1, 0, -1};

		int count = 0;

		for (int t1 = 0; t1 < m; t1++)
		{
			for (int t2 = 0; t2 < n; t2++)
			{
				if (visited[t1][t2] || field[t1][t2] != 1)
					continue;

				queue<pair<int, int>> bfs;

				visited[t1][t2] = true;
				bfs.push({ t1, t2 });

				count++;

				while (!bfs.empty())
				{
					pair<int, int> current = bfs.front();
					bfs.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = current.first + dirX[dir];
						int ny = current.second + dirY[dir];

						if (nx < 0 || nx >= m || ny < 0 || ny >= n)
							continue;
						if (visited[nx][ny] || field[nx][ny] != 1)
							continue;

						visited[nx][ny] = true;
						bfs.push({nx, ny});
					}
				}
			}
		}
		cout << count << "\n";
	}

	return 0;
}