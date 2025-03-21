#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r, c = 0;
	cin >> r >> c;

	vector<vector<char>> maze;
	maze.resize(r, vector<char>(c, 0));

	vector<vector<int>> fireDistance;
	fireDistance.resize(r, vector<int>(c, -1));

	vector<vector<int>> personDistance;
	personDistance.resize(r, vector<int>(c, -1));

	queue<pair<int, int>> bfsFire;
	queue<pair<int, int>> bfsPerson;

	for (int i = 0; i < r; i++)
	{
		string temp = "";
		cin >> temp;

		int j = 0;

		for (char c : temp)
		{
			maze[i][j] = c;

			if (c == 'F')
			{
				bfsFire.push({ i, j });
				fireDistance[i][j] = 0;
			}

			else if (c == 'J')
			{
				bfsPerson.push({ i, j });
				personDistance[i][j] = 0;
			}

			j++;
		}
	}

	vector<int> dirX = { 1, 0, -1, 0 };
	vector<int> dirY = { 0, 1, 0, -1 };

	while (!bfsFire.empty())
	{
		pair<int, int> front = bfsFire.front();
		bfsFire.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = front.first + dirX[i];
			int y = front.second + dirY[i];

			if (x < 0 || x >= r || y < 0 || y >= c)
				continue;
			if (maze[x][y] == '#' || fireDistance[x][y] >= 0)
				continue;

			fireDistance[x][y] = fireDistance[front.first][front.second] + 1;
			bfsFire.push({ x, y });
		}
	}

	while (!bfsPerson.empty())
	{
		pair<int, int> front = bfsPerson.front();
		bfsPerson.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = front.first + dirX[i];
			int y = front.second + dirY[i];

			if (x < 0 || x >= r || y < 0 || y >= c)
			{
				cout << personDistance[front.first][front.second] + 1;
				return 0;
			}
			if (maze[x][y] == '#' || personDistance[x][y] >= 0)
				continue;
			if (fireDistance[x][y] != -1 && fireDistance[x][y] <= personDistance[front.first][front.second] + 1)
				continue;

			personDistance[x][y] = personDistance[front.first][front.second] + 1;
			bfsPerson.push({ x, y });
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}
