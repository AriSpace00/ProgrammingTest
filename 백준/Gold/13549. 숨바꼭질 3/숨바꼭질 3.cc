#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n = 0, k = 0;
	cin >> n >> k;

	vector<int> visited;
	visited.resize(100001, -1);

	queue<int> bfs;
	bfs.push(n);
	visited[n] = 0;

	while (!bfs.empty())
	{
		int current = bfs.front();
		bfs.pop();

		if (current == k)
		{
			cout << visited[current];
			return 0;
		}

		if (current * 2 <= 100000 && visited[current * 2] == -1)
		{
			visited[current * 2] = visited[current];
			bfs.push(current * 2);
		}

		for (int next : {current - 1, current + 1})
		{
			if (next >= 0 && next <= 100000 && visited[next] == -1)
			{
				visited[next] = visited[current] + 1;
				bfs.push(next);
			}

		}
	}

	return 0;
}