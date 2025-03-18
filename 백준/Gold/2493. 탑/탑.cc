#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int size = 0;
    cin >> size;

    stack<pair<int, int>> info;  
    for (int i = 0; i < size; i++)
    {
        int temp = 0;
        cin >> temp;
        while (!info.empty() && info.top().second < temp)
        {
            info.pop();
        }

        if (info.empty())
        {
            cout << "0 ";
        }
        else
        {
            cout << info.top().first + 1 << " "; 
        }

        info.push(make_pair(i, temp));
    }

    return 0;
}
