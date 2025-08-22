#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0;
    cin >> n;
    
    stack<pair<int, int>> st;
    for (int i=0; i<n; i++)
    {
        int temp = 0;
        cin >> temp;
        
        while (!st.empty() && st.top().second < temp)
        {
            st.pop();
        }
        
        if (st.empty())
        {
            cout << "0 ";
        }
        else
        {
            cout << st.top().first + 1 << ' ';
        }
        
        st.push(make_pair(i, temp));
    }
    
    return 0;
}
    