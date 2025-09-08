#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	// 역의 개수
	int stationCount = 0;
	cin >> stationCount;

	// 간선 정보 추가한 그래프 생성
	vector<vector<int>> adj(stationCount);
	vector<int> degree(stationCount, 0);
	for (int i = 0; i < stationCount; i++)
	{
		int left, right;
		cin >> left >> right;
		--left;
		--right;

		adj[left].push_back(right);
		adj[right].push_back(left);

		degree[left]++;
		degree[right]++;
	}

	// 리프 노드 제거
	queue<int> leaf;
	vector<bool> inCycle(stationCount, true);
	for (int i = 0; i < stationCount; i++)
	{
		if (degree[i] == 1)
		{
			inCycle[i] = false;
			leaf.push(i);
		}
	}

	while (!leaf.empty())
	{
		int current = leaf.front();
		leaf.pop();

		for (int next : adj[current])
		{
			if (--degree[next] == 1)
			{
				inCycle[next] = false;
				leaf.push(next);
			}
		}
	}

	// bfs로 사이클 노드까지 최단 거리 도출
	queue<int> bfs;
	vector<int> distance(stationCount, -1);
	for (int i = 0; i < stationCount; i++)
	{
		if (inCycle[i])
		{
			distance[i] = 0;
			bfs.push(i);
		}
	}

	while (!bfs.empty())
	{
		int current = bfs.front();
		bfs.pop();

		for (int next : adj[current])
		{
			if (distance[next] < 0)
			{
				distance[next] = distance[current] + 1;
				bfs.push(next);
			}
		}
	}

	for (int i : distance)
	{
		cout << i << " ";
	}

	return 0;
}