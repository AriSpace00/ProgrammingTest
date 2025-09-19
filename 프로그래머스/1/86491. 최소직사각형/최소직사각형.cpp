#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int maxWidth = 0, maxHeight = 0;
    
    for (int i=0; i<sizes.size(); i++)
    {
        auto info = sizes[i];
        
        if (info[0] < info[1])
            swap(info[0], info[1]);
        
        if (maxWidth < info[0])
            maxWidth = info[0];
        
        if (maxHeight < info[1])
            maxHeight = info[1];
    }

    return maxWidth * maxHeight;
}