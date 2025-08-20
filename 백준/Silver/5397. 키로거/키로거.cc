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
        list<char> output;
        auto cursor = output.begin();

        string str;
        cin >> str;

        for (char c : str)
        {
            switch (c)
            {
            case '<':
            {
                if (cursor != output.begin())
                {
                    cursor--;
                }
            }
            break;
            case '>':
            {
                if (cursor != output.end())
                {
                    cursor++;
                }
            }
            break;
            case '-':
            {
                if (cursor != output.begin())
                {
                    cursor--;
                    cursor = output.erase(cursor);
                }
            }
            break;
            default:
            {
                output.insert(cursor, c);
            }
            break;
            }
        }

        for (char c : output)
        {
            cout << c;
        }

        cout << "\n";
    }

    return 0;
}