#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int num = 0;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int width = 0, height = 0;
		cin >> width >> height;
		cin.ignore();

		vector<vector<char>> field;
		field.resize(width, vector<char>(height, '\0'));

		vector<vector<int>> distanceFire;
		distanceFire.resize(width, vector<int>(height, -1));

		vector<vector<int>> distancePerson;
		distancePerson.resize(width, vector<int>(height, -1));

		queue<pair<int, int>> bfsFire;
		queue<pair<int, int>> bfsPerson;

		for (int k = 0; k < height; k++)
		{
			string temp = "";
			getline(cin, temp);

			int j = 0;

			for (char c : temp)
			{
				field[j][k] = c;

				if (c == '*')
				{
					bfsFire.push({ j, k });
					distanceFire[j][k] = 0;
				}
				else if (c == '@')
				{
					bfsPerson.push({ j, k });
					distancePerson[j][k] = 0;
				}

				j++;
			}
		}

		vector<int> dirX = { 1, 0, -1, 0 };
		vector<int> dirY = { 0, 1, 0, -1 };

		while (!bfsFire.empty())
		{
			pair<int, int> current = bfsFire.front();
			bfsFire.pop();

			for (int d = 0; d < 4; d++)
			{
				int nextX = current.first + dirX[d];
				int nextY = current.second + dirY[d];

				if (nextX < 0 || nextY < 0 || nextX >= width || nextY >= height)
					continue;
				if (field[nextX][nextY] == '#' || distanceFire[nextX][nextY] >= 0)
					continue;

				distanceFire[nextX][nextY] = distanceFire[current.first][current.second] + 1;
				bfsFire.push({ nextX, nextY });
			}
		}

		bool isEscaped = false;
		while (!bfsPerson.empty() && !isEscaped)
		{
			pair<int, int> current = bfsPerson.front();
			bfsPerson.pop();

			for (int d = 0; d < 4; d++)
			{
				int nextX = current.first + dirX[d];
				int nextY = current.second + dirY[d];

				if (nextX < 0 || nextY < 0 || nextX >= width || nextY >= height)
				{
					isEscaped = true;
					break;
				}
				if (field[nextX][nextY] == '#' || distancePerson[nextX][nextY] >= 0)
					continue;
				if (distanceFire[nextX][nextY] != -1 && distancePerson[current.first][current.second] + 1 >= distanceFire[nextX][nextY])
					continue;

				distancePerson[nextX][nextY] = distancePerson[current.first][current.second] + 1;
				bfsPerson.push({ nextX, nextY });
			}

			if (isEscaped)
			{
				cout << distancePerson[current.first][current.second] + 1 << "\n";
				break;
			}
		}

		if (!isEscaped)
			cout << "IMPOSSIBLE\n";
	}

	return 0;
}