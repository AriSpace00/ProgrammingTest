#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

bool isDestroy(vector<int>& day, int term, vector<int>& today)
{
    day[0] += term/12;
    day[1] += term%12;
    
    if(day[1] > 12)
    {
        day[0] += day[1]/12;
        day[1] = day[1]%12;
    }
    
    if(day[2] > 1)
    {
        day[2] -=1;
    }
    else if(day[2] == 1)
    {
        day[1] -=1;
        day[2] = 28;
    }
    
    if(day[0] == today[0])
    {
        if(day[1] == today[1])
        {
            return day[2] >= today[2] ? false : true;
        }
        else
        {
            return day[1] > today[1] ? false : true;
        }
    }

    return day[0] > today[0] ? false : true;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    stringstream ss(today);
    string temp;
    vector<int> todayInt;
    while(getline(ss, temp, '.'))
    {
        todayInt.push_back(stoi(temp));
    }
    
    map<string, int> termsMap;
    for(int i=0; i<terms.size(); i++)
    {
        ss.str(terms[i]);
        ss.clear();
        string key;
        int value;
        ss >> key >> value;
        termsMap.insert({key, value});
    }
    
    vector<int> answer;
    for(int i=0; i<privacies.size(); i++)
    {
        ss.str(privacies[i]);
        ss.clear();
        string day;
        string key;
        ss >> day >> key;
        
        ss.str(day);
        ss.clear();
        vector<int> dayInt;
        while(getline(ss, temp, '.'))
        {
            dayInt.push_back(stoi(temp));
        }
        
        if(isDestroy(dayInt, termsMap[key], todayInt))
            answer.push_back(i+1);
    }
    
    return answer;
}