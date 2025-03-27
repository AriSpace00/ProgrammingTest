#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        string temp = "";
        getline(cin, temp);
        if (temp == ".")
            break;
        
        bool isValid = true;
        stack<char> pairs;
        for (char c : temp)
        {
            switch (c)
            {
                case('(') :
                {
                    pairs.push(c);
                }
                break;
                case('['):
                {
                    pairs.push(c);
                }
                break;
                case(')'):
                {
                    if (!pairs.empty() && pairs.top() == '(')
                        pairs.pop();
                    else
                        isValid = false;
                }
                break;
                case(']'):
                {
                    if (!pairs.empty() && pairs.top() == '[')
                        pairs.pop();
                    else
                        isValid = false;
                }
                break;
            }

            if (!isValid)
                break;
        }

        if (isValid && pairs.empty())
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}