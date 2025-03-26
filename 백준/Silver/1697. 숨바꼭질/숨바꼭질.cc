#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K = 0;
	cin >> N >> K;

	queue<int> bfs;

	vector<int> distance;
	distance.resize(100001, -1);

	distance[N] = 0;
	bfs.push(N);

	while (distance[K] == -1)
	{
		int currentN = bfs.front();
		bfs.pop();

		for (int next : {currentN - 1, currentN + 1, currentN * 2})
		{
			if (next < 0 || next > 100000)
				continue;
			if (distance[next] != -1)
				continue;

			distance[next] = distance[currentN] + 1;
			bfs.push(next);
		}
	}

	cout << distance[K];

	return 0;
}
