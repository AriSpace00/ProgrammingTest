#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n =0;
    cin >> n;
    
    vector<int> arr(n, 0);
    
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    
    vector<int> lis;
    for(int next : arr)
    {
        vector<int>::iterator iter = lower_bound(lis.begin(), lis.end(), next);
        
        if(iter != lis.end())
        {
            *iter = next;
        }
        else
        {
            lis.push_back(next);
        }
    }
    
    cout << lis.size();
    
    return 0;
}