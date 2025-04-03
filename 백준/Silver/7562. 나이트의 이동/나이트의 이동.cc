#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int num = 0;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int length = 0;
		cin >> length;

		vector<vector<int>> distance;
		distance.resize(length, vector<int>(length, -1));

		queue<pair<int, int>> bfs;

		int startX = 0, startY = 0;
		cin >> startX >> startY;

		bfs.push({startX, startY});
		distance[startX][startY] = 0;

		int finishX = 0, finishY = 0;
		cin >> finishX >> finishY;

		vector<int> dirX = { -2, -1, 1, 2, 2, 1, -1, -2 };
		vector<int> dirY = { 1, 2, 2, 1, -1, -2, -2, -1 };

		while (!bfs.empty())
		{
			pair<int, int> current = bfs.front();
			bfs.pop();

			for (int d = 0; d < 8; d++)
			{
				int nextX = current.first + dirX[d];
				int nextY = current.second + dirY[d];

				if (nextX < 0 || nextY < 0 || nextX >= length || nextY >= length)
					continue;
				if (distance[nextX][nextY] >= 0)
					continue;

				distance[nextX][nextY] = distance[current.first][current.second] + 1;
				bfs.push({ nextX, nextY });
			}
		}

		cout << distance[finishX][finishY] << "\n";
	}

	return 0;
}