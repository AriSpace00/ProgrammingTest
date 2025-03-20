#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 1. info vector에 입력값을 넣는다.
	int n, m = 0;
	cin >> n;
	cin >> m;
	
	vector<vector<int>> info;
	for (int i = 0; i < n; i++)
	{
		vector<int> tempArr;
		for (int j = 0; j < m; j++)
		{
			int temp = 0;
			cin >> temp;
			tempArr.push_back(temp);
		}

		info.push_back(tempArr);
	}

	// 2. BFS를 위해 변수를 선언한다. 
	
	// 방문한 칸의 좌표를 기록
	vector<vector<int>> visited;
	visited.resize(n, vector<int>(m, 0));
	
	// 방문하고자 하는 방향
	vector<int> dirX = {1, 0, -1, 0};
	vector<int> dirY = {0, 1, 0, -1};

	// 3. info vector를 순회하며 그림의 최댓값, 그림의 수를 구한다.
	// 그림의 최대 길이를 구하기 위해서는 queue의 pop 횟수를 세면 된다.
	// 그림의 개수를 구하기 위해서는 info vector를 순회하며 시작할 수 있는 지점을 찾으면 된다.

	int maxLength = 0;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 칸에 그림이 없거나, 이미 방문했을 경우 현재 루프문(j)을 건너뛴다.
			if (info[i][j] == 0 || visited[i][j])
				continue;
			
			// 시작할 수 있는 지점이므로 그림 개수 +1
			num++;

			// BFS 시 필요한 큐
			queue<pair<int, int>> bfs;
			
			// BFS : 방문 표시
			visited[i][j] = 1;
			// BFS : 큐에 삽입
			bfs.push({i, j});

			// 그림의 길이 기록할 변수
			int length = 0;

			// BFS : 해당 시작점으로부터 너비 우선 탐색
			while (!bfs.empty())
			{
				// BFS : 큐의 front를 pop해줌
				pair<int, int> current = bfs.front();
				bfs.pop();
				length++;

				// BFS : 상하좌우로 인접한 칸에 대해 조사
				for (int dir = 0; dir < 4; dir++)
				{
					int x = current.first + dirX[dir];
					int y = current.second + dirY[dir];

					if (x < 0 || x >= n || y < 0 || y >= m)
						continue;
					if (visited[x][y] || info[x][y] != 1)
						continue;

					visited[x][y] = 1;
					bfs.push({ x, y });
				}
			}

			maxLength = max(maxLength, length);
		}
	}

	cout << num << "\n" << maxLength;

	return 0;
}
