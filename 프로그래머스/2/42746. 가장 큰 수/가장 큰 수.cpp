#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct 
{
    bool operator()(string a, string b) const {return a+b > b+a;}
} 
compareString;


string solution(vector<int> numbers) 
{
    vector<string> numbers_string;
    for(int i : numbers)
    {
        string newNumber = to_string(i);
        numbers_string.push_back(newNumber);
    }
    
    sort(numbers_string.begin(), numbers_string.end(), compareString);
    
    if(numbers_string[0] == "0")
    {
        return "0";
    }
    
    string answer;
    for(string s : numbers_string)
    {
        answer += s;
    }
    
    return answer;
}