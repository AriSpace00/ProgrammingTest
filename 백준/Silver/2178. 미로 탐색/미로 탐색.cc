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
		string temp = "";
		cin >> temp;

		vector<int> tempArr;
		for (char c : temp)
		{
			tempArr.push_back(c - '0');
		}

		info.push_back(tempArr);
	}

	// 2. BFS를 위해 변수를 선언한다. 
	
	// 시작지점으로부터 방문한 칸까지의 거리 기록
	vector<vector<int>> distance;
	distance.resize(n, vector<int>(m, -1));
	
	// 방문하고자 하는 방향
	vector<int> dirX = {1, 0, -1, 0};
	vector<int> dirY = {0, 1, 0, -1};

	// 3. info vector를 순회하며 (n, m)까지 이동할 수 있는 경로를 구한다.
	// 경로의 길이를 구하기 위해서는 queue의 pop 횟수를 세면 된다.

	// BFS 시 필요한 큐
	queue<pair<int, int>> bfs;
	
	// BFS : 시작지점으로부터의 거리
	distance[0][0] = 0;
	// BFS : 큐에 삽입
	bfs.push({0, 0});

	// BFS : 해당 시작점으로부터 너비 우선 탐색
	while (!bfs.empty())
	{
		// BFS : 큐의 front를 pop해줌
		pair<int, int> current = bfs.front();
		bfs.pop();

		// BFS : 상하좌우로 인접한 칸에 대해 조사
		for (int dir = 0; dir < 4; dir++)
		{
			int x = current.first + dirX[dir];
			int y = current.second + dirY[dir];

			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;
			if (distance[x][y] >= 0 || info[x][y] != 1)
				continue;

			distance[x][y] = distance[current.first][current.second] + 1;
			bfs.push({ x, y });
		}
	}

	cout << distance[n - 1][m - 1] + 1;

	return 0;
}
