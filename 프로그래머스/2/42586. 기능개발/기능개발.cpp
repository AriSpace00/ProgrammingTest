#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    queue<int> days;
    
    for (int i=0; i<progresses.size(); i++)
    {
        int day = 0;
        int diff = 100 - progresses[i];
        while (diff > speeds[i] * day)
        {
            day++;
        }
        
        days.push(day);
    }
    
    vector<int> answer;
    
    int minDay = days.front();
    answer.push_back(1);
    days.pop();
    
    while(!days.empty())
    {
        if (minDay < days.front())
        {
            minDay = days.front();
            answer.push_back(1);
            days.pop();
        }
        else
        {
            answer[answer.size() - 1]++;
            days.pop();
        }
    }
    
    return answer;
}