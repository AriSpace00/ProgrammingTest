#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<int>& numbers, int target, int index, int sum)
{
    if (index == numbers.size())
    {
        if (sum == target)
        {
            return 1;
        }
    
        return 0;
    }
    
    return dfs(numbers, target, index + 1, sum+numbers[index]) + dfs(numbers, target, index+1, sum-numbers[index]);
}

int solution(vector<int> numbers, int target)
{
    return dfs(numbers, target, 0, 0);
}