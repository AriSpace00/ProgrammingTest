#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n =0;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> minQueue;
    for(int i=0; i<n; i++)
    {
        int command = -1;
        cin >> command;
        
        if (command == 0)
        {
            if(!minQueue.empty())
            {
                cout << minQueue.top() << "\n";
                minQueue.pop();
            }
            else
            {
                cout << "0\n";
            }
        }
        else
        {
            minQueue.push(command);
        }
    }
    return 0;
}