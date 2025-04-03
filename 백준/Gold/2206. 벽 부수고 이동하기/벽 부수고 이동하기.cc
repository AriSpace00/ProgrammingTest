#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct state
{
	int x = 0, y = 0;
	bool broken = false;

	state(int inX, int inY, bool inBroken)
		: x(inX)
		, y(inY)
		, broken(inBroken)
	{}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 0, m = 0;
	cin >> n >> m;

	vector<vector<char>> field;
	field.resize(n, vector<char>(m, '\0'));

	vector<vector<vector<int>>> distance;
	distance.resize(n, vector<vector<int>>(m, vector<int>(2, -1)));

	for (int i = 0; i < n; i++)
	{
		int j = 0;

		string temp = "";
		cin >> temp;
		cin.ignore();

		for (char c : temp)
		{
			field[i][j] = c;
			j++;
		}
	}

	queue<state> bfs;
	bfs.push(state(0, 0, false));
	distance[0][0][0] = 1;

	while (!bfs.empty())
	{
		state current = bfs.front();

		if (current.x == n - 1 && current.y == m - 1)
		{
			cout << distance[current.x][current.y][current.broken];
			return 0;
		}

		bfs.pop();

		vector<int> dirX = { 1, 0, -1, 0 };
		vector<int> dirY = { 0, 1, 0, -1 };
		for (int i = 0; i < 4; i++)
		{
			int nextX = current.x + dirX[i];
			int nextY = current.y + dirY[i];

			if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m)
				continue;

			// 벽을 부수지 않았을 때
			if (field[nextX][nextY] == '0' && distance[nextX][nextY][current.broken] == -1)
			{
				distance[nextX][nextY][current.broken] = distance[current.x][current.y][current.broken] + 1;
				bfs.push(state(nextX, nextY, current.broken));
			}

			// 벽을 부수었을 때
			if (!current.broken && field[nextX][nextY] == '1' && distance[nextX][nextY][1] == -1)
			{
				distance[nextX][nextY][1] = distance[current.x][current.y][current.broken] + 1;
				bfs.push(state(nextX, nextY, true));
			}
		}
	}

	cout << "-1\n";

	return 0;
}