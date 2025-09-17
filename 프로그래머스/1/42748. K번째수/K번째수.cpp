#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    
    for (int i=0; i<commands.size(); i++)
    {
        int start = commands[i][0];
        int end = commands[i][1];
        int size = commands[i][2];
        
        --start;
        --end;
        
        priority_queue<int, vector<int>, greater<int>> sub;
        for(int j=start; j<=end; j++)
        {
            sub.push(array[j]);
        }
        
        while(size > 1)
        {
            sub.pop();
            --size;
        }
        
        answer.push_back(sub.top());
    }
    
    return answer;
}