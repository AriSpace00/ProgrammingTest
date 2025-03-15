#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() 
{
    int size = 0;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        list<char> tempList = {};
        auto cursorIt = tempList.begin();

        string temp;
        cin >> temp;
        for (auto c : temp)
        {
            if (c == '<')
            {
                if (cursorIt != tempList.begin())
                {
                    --cursorIt;
                }
            }
            else if (c == '>')
            {
                if (cursorIt != tempList.end())
                {
                    ++cursorIt;
                }
            }
            else if (c == '-')
            {
                if (cursorIt != tempList.begin())
                {
                    --cursorIt;
                    cursorIt = tempList.erase(cursorIt);
                }
            }
            else
            {
                tempList.insert(cursorIt, c);
            }
        }

        for (auto c : tempList)
        {
            cout << c;
        }

        cout << endl;
    }

    return 0;
}
