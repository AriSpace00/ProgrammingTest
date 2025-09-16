#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) 
{  
    unordered_set<string> numbers(phone_book.begin(), phone_book.end());
    
    for (string number : phone_book)
    {
        for (int i = 1; i < number.size(); i++)
        {
            string subNumber = number.substr(0, i);
            
            if (numbers.find(subNumber) != numbers.end())
            {
                return false;
            }
        }
    }
    
    return true;
}