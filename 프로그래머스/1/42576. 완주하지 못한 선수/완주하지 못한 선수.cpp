#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    unordered_map<string, int> frequency;
    for (string name : completion)
    {
        if (!frequency.empty())
        {
            auto search = frequency.find(name);
            
            if (search != frequency.end())
            {
                search->second++;
                continue;
            }
        }

        frequency.insert({name, 1});
    }
    
    string answer = "";
    for (string name : participant)
    {
        auto search = frequency.find(name);
        if (search != frequency.end())
        {
            search->second--;
            if (search->second < 0)
            {
                answer = name;
                break;
            }
        }
        else
        {
            answer = name;
        }
    }
    
    
    return answer;
}