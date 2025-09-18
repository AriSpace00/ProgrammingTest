#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) 
{
    vector<vector<int>> adj(n);
    for (int i=0; i<computers.size(); i++)
    {
        for(int j =0; j<computers[i].size(); j++)
        {
            if(i == j || computers[i][j] == 0)
                continue;

            adj[i].push_back(j);
        }
    }
    
    queue<int> bfs;
    vector<bool> visited(n, false);
    
    int answer = 0;
    
    for(int i=0; i<adj.size(); i++)
    {
        if (visited[i])
            continue;
        
        bfs.push(i);
        visited[i] = true;
        
        while (!bfs.empty())
        {
            int current = bfs.front();
            bfs.pop();
        
            for (int next : adj[current])
            {
                if (visited[next])
                    continue;
                
                visited[next] = true;
                bfs.push(next);
            }
        }
        
        answer++;
    }
    
    return answer;
}