#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string temp = "";
    getline(cin, temp);

    stack<char> pairs;
    char previous = '\0';
    int count = 0;
    for (char current : temp)
    {
        switch (current)
        {
        case('(') :
        {
            pairs.push(current);
        }
        break;
        case(')'):
        {
            if (pairs.empty())
                break;

            pairs.pop();

            if (previous == '(')
            {
                count += pairs.size();
            }
            else
            {
                count++;
            }
        }
        break;
        }

        previous = current;
    }

    cout << count;

    return 0;
}