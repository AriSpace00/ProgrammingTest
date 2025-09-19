#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) 
{
    vector<vector<int>> adj(n);
    for(int i=0; i<edge.size(); i++)
    {
        int from = edge[i][0];
        int to = edge[i][1];
        
        --from;
        --to;
        
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    for(int i=0; i<adj.size(); i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    
    vector<int> distance(n, -1);
    
    queue<int> bfs;
    bfs.push(0);
    distance[0] = 0;

    while(!bfs.empty())
    {
        int current = bfs.front();
        bfs.pop();
        
        for(int next : adj[current])
        {
            if(distance[next] != -1)
                continue;
            
            distance[next] = distance[current] + 1;
            bfs.push(next);
        }
    }
    
    int answer = 0;
    int maxDistance = *max_element(distance.begin(), distance.end());
    
    for(int i =0; i<distance.size(); i++)
    {
        if(distance[i] == maxDistance)
            answer++;
    }
    
    return answer;
}