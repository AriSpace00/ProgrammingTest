#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; i++)
    {
        cin >> permutation[i];
    }

    stack<int> st;
    vector<char> output;
    int current = 0;
    for (int i = 0; i < n; i++)
    {
        while (current < permutation[i])
        {
            st.push(++current);
            output.push_back('+');
        }

        if (st.top() == permutation[i])
        {
            st.pop();
            output.push_back('-');
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    if (!output.empty())
    {
        for (char c : output)
        {
            cout << c << '\n';
        }
    }

    return 0;
}