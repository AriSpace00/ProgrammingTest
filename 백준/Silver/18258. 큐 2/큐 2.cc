#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size = 0;
    cin >> size;
    cin.ignore();

    queue<int> output;
    for (int i = 0; i < size; i++)
    {
        string command = "";
        getline(cin, command);

        if (command.find("push") != string::npos)
        {
            size_t spacePos = command.find(' ');
            string tempString = command.substr(spacePos + 1, command.size());
            int tempInt = stoi(tempString);
            output.push(tempInt);
        }

        else if (command == "pop")
        {
            if (!output.empty())
            {
                cout << output.front() << "\n";
                output.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
        }

        else if (command == "size")
        {
            cout << output.size() << "\n";
        }

        else if (command == "empty")
        {
            if (output.empty())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        
        else if (command == "front")
        {
            if (!output.empty())
            {
                cout << output.front() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }

        else if (command == "back")
        {
            if (!output.empty())
            {
                cout << output.back() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}
