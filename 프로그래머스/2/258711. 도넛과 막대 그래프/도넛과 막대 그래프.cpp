#include <vector>
#include <algorithm>
using namespace std;

void dfs(int current, vector<vector<int>>& adj, vector<int>& visited, int& vertex, int& edge)
{
    visited[current] = true;
    
    vertex++;
    for(int next : adj[current])
    {
        edge++;
        if(!visited[next])
        {
            dfs(next, adj, visited, vertex, edge);
        }
    }
}

vector<int> solution(vector<vector<int>> edges) 
{   
    vector<int> answer(4, 0);
    
    int nodeCount = 0;
    for (auto& info : edges) 
        nodeCount = max(nodeCount, max(info[0], info[1]));
        
    vector<int> inDegree(nodeCount+1);
    vector<int> outDegree(nodeCount+1); 
    vector<vector<int>> adj(nodeCount+1);
    
    for (auto& info : edges) 
    {
        int from = info[0];
        int to   = info[1];
        
        adj[from].push_back(to);
        
        outDegree[from]++;
        inDegree[to]++;
    }
    
    int totalGraphs = 0;

    for (int i = 1; i <= nodeCount; i++) 
    {
        if (inDegree[i] == 0 && outDegree[i] >= 2) 
        {
            answer[0] = i;
            totalGraphs = outDegree[i];
            break;
        }
    }

    vector<int> visited(nodeCount+1, false);
    for (int current : adj[answer[0]]) 
    {
        int vertex =0;
        int edge =0;
        
        dfs(current, adj, visited, vertex, edge);
        
        if (vertex == edge) 
            answer[1]++; 
        else if (vertex - 1 == edge) 
            answer[2]++; 
        else
            answer[3]++;
    }

    return answer;
}
