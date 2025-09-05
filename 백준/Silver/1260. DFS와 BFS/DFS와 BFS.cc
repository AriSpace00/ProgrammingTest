#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> bfs(vector<vector<int>>& adj, int start)
{
	vector<bool> visited(adj.size(), false);
	vector<int> result;

	queue<int> q;
	visited[start] = true;
	q.push(start);

	while (!q.empty())
	{
		int current = q.front();
		result.push_back(current);
		q.pop();

		for (int next : adj[current])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}

	return result;
}

void dfsRecursion(vector<vector<int>>& adj, vector<bool>& visited, int start, vector<int>& result)
{
	visited[start] = true;
	result.push_back(start);

	for (int next : adj[start])
	{
		if (!visited[next])
		{
			dfsRecursion(adj, visited, next, result);
		}
	}
}

vector<int> dfs(vector<vector<int>>& adj, int start)
{
	vector<bool> visited(adj.size(), false);
	vector<int> result;

	dfsRecursion(adj, visited, start, result);
	
	return result;
}

void addEdge(vector<vector<int>>& adj, int left, int right)
{
	adj[left].push_back(right);
	adj[right].push_back(left);
}

int main()
{
	int nodeCount = 0, edgeCount = 0, startNode = 0;
	cin >> nodeCount >> edgeCount >> startNode;
	vector<vector<int>> adj(nodeCount);

	vector<vector<int>> edges(edgeCount, vector<int>(2));
	for (int i = 0; i < edgeCount; i++)
	{
		int left = 0, right = 0;
		cin >> left >> right;

		edges[i][0] = left - 1;
		edges[i][1] = right - 1;
	}

	for (auto& e : edges)
	{
		addEdge(adj, e[0], e[1]);
	}

	for (vector<int>& arr : adj)
	{
		sort(arr.begin(), arr.end());
	}

	vector<int> dfsResult = dfs(adj, startNode - 1);
	for (int i = 0; i < dfsResult.size(); i++)
	{
		cout << dfsResult[i] + 1 << " ";
	}

	cout << "\n";

	vector<int> bfsResult = bfs(adj, startNode - 1);
	for (int i = 0; i < bfsResult.size(); i++)
	{
		cout << bfsResult[i] + 1 << " ";
	}

	return 0;
}