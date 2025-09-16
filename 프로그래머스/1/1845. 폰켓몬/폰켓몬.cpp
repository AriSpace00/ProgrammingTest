#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> frequency;
    for(int i : nums)
    {
        frequency[i]++;
    }
    
    if (frequency.size() <= nums.size() / 2)
    {
        return frequency.size();
    }
    
    return nums.size() / 2;
}