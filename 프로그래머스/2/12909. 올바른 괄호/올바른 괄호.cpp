#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string question)
{
    stack<int> st;
    for (char c : question)
    {
        if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            if (st.empty())
            {
                return false;
            }
            else if (st.top() == '(')
            {
                st.pop();
            }
        }
    }
    
    if(st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}