#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int nodeCount = 0, edgeCount = 0;
	cin >> nodeCount >> edgeCount;

	vector<vector<int>> adj(nodeCount);
	for (int i = 0; i < edgeCount; i++)
	{
		int left = 0, right = 0;
		cin >> left >> right;

		adj[left - 1].push_back(right - 1);
		adj[right - 1].push_back(left - 1);
	}

	int count = 0;
	vector<bool> visited(nodeCount, false);
	for (int i = 0; i < nodeCount; i++)
	{
		if (visited[i])
		{
			continue;
		}

		count++;

		queue<int> bfs;
		bfs.push(i);
		visited[i] = true;

		while (!bfs.empty())
		{
			int current = bfs.front();
			bfs.pop();

			for (int next : adj[current])
			{
				if (!visited[next])
				{
					visited[next] = true;
					bfs.push(next);
				}
			}
		}
	}

	cout << count;

	return 0;
}