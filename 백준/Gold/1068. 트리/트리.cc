#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int nodeCount = 0;
	cin >> nodeCount;

	vector<vector<int>> adj(nodeCount);
	int rootNode = -1;
	for (int i = 0; i < nodeCount; i++)
	{
		int parent = 0;
		cin >> parent;

		if (parent != -1)
		{
			adj[parent].push_back(i);
		}
		else
		{
			rootNode = i;
		}
	}

	int removeNode = 0;
	cin >> removeNode;
	
	vector<bool> isRemove(nodeCount, false);
	queue<int> removeBfs;
	removeBfs.push(removeNode);

	while (!removeBfs.empty())
	{
		int current = removeBfs.front();
		isRemove[current] = true;
		removeBfs.pop();

		for (int next : adj[current])
		{
			if (!isRemove[next])
			{
				removeBfs.push(next);
			}
		}
	}

	if (removeNode == rootNode)
	{
		cout << 0;
		return 0;
	}

	int leafCount = 0;

	queue<int> leafBfs;
	leafBfs.push(rootNode);
	
	while (!leafBfs.empty())
	{
		int current = leafBfs.front();
		leafBfs.pop();

		int childCount = 0;
		for (int next : adj[current])
		{
			if (!isRemove[next])
			{
				leafBfs.push(next);
				childCount++;
			}
		}

		if (childCount == 0)
		{
			leafCount++;
		}
	}
	
	cout << leafCount;

	return 0;
}