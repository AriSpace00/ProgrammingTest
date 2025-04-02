#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct vector3
{
	int x = 0, y = 0, z = 0;

	vector3(int inX, int inY, int inZ)
		: x(inX)
		, y(inY)
		, z(inZ)
	{}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int raw = 0, column = 0, height = 0;
	cin >> raw >> column >> height;

	// z, y, x 순서
	vector<vector<vector<int>>> field;
	field.resize(height, vector<vector<int>>(column, vector<int>(raw, -1)));

	vector<vector<vector<int>>> distance;
	distance.resize(height, vector<vector<int>>(column, vector<int>(raw, -1)));

	queue<vector3> bfs;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < column; j++)
		{
			for (int k = 0; k < raw; k++)
			{
				int temp = 0;
				cin >> temp;
				field[i][j][k] = temp;

				if (temp == 1)
				{
					bfs.push(vector3(k, j, i));
					distance[i][j][k] = 0;
				}
			}
		}
	}

	vector<int> dirX = {1, 0, -1, 0, 0, 0};
	vector<int> dirY = {0, 1, 0, -1, 0, 0};
	vector<int> dirZ = {0, 0, 0, 0, 1, -1};

	while (!bfs.empty())
	{
		vector3 current = bfs.front();
		bfs.pop();

		for (int d = 0; d < 6; d++)
		{
			int nextX = current.x + dirX[d];
			int nextY = current.y + dirY[d];
			int nextZ = current.z + dirZ[d];

			if (nextX < 0 || nextY < 0 || nextZ < 0 || nextX >= raw || nextY >= column || nextZ >= height)
				continue;
			if (distance[nextZ][nextY][nextX] >= 0 || field[nextZ][nextY][nextX] == -1)
				continue;

			distance[nextZ][nextY][nextX] = distance[current.z][current.y][current.x] + 1;
			bfs.push(vector3(nextX, nextY, nextZ));
		}
	}
				
	int maxValue = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < column; j++)
		{
			for (int k = 0; k < raw; k++)
			{
				if (field[i][j][k] == 0 && distance[i][j][k] == -1)
				{
					cout << -1;
					return 0;
				}
				
				maxValue = max(maxValue, distance[i][j][k]);
			}
		}
	}

	cout << maxValue;

	return 0;
}