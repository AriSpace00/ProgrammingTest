#include <string>
#include <vector>
#include <queue>

using namespace std;

bool canChange(const string& source, const string& target)
{
    int diff = 0;
    for(int i=0; i<source.size(); i++)
    {
        if(source[i] != target[i])
            diff++;
        if(diff > 1)
            return false;
    }
    
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) 
{    
    vector<bool> visited(words.size(), false);
    
    queue<pair<string, int>> bfs;
    bfs.push({begin, 0});
    
    while(!bfs.empty())
    {
        string currentString = bfs.front().first;
        int currentLength = bfs.front().second;
        bfs.pop();
        
        if (currentString == target)
            return currentLength;
        
        for (int i=0; i<words.size(); i++)
        {
            if (!canChange(currentString, words[i]) || visited[i])
                continue;
            
            visited[i] = true;
            bfs.push({words[i], currentLength + 1});
        }
    }
    
    return 0;
}