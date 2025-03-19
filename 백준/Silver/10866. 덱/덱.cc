#include <iostream>
#include <string>

using namespace std;

const int MX = 10000;
int dequeArr[2 * MX + 1];
int head = MX, tail = MX;

bool empty()
{
    if (head == tail)
        return true;
    else
        return false;
}

void push_front(int x)
{
    if (head > 0)
    {
        head--;
        dequeArr[head] = x;
    }
}

void push_back(int x)
{
    if (tail < 2 * MX)
    {
        dequeArr[tail] = x;
        tail++;
    }
}

int front()
{
    if (!empty())
    {
        return dequeArr[head];
    }
    else
    {
        return -1;
    }
}

int back()
{
    if (!empty())
    {
        return dequeArr[tail - 1];
    }
    else
    {
        return -1;
    }
}

void pop_front()
{
    if (!empty())
    {
        cout << front() << "\n";
        head++;
    }
    else
    {
        cout << -1 << "\n";
    }
}

void pop_back()
{
    if (!empty())
    {
        cout << back() << "\n";
        tail--;
    }
    else
    {
        cout << -1 << "\n";
    }
}

int sizeFunc()
{
    return tail - head;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size = 0;
    cin >> size;
    cin.ignore();

    for (int i = 0; i < size; i++)
    {
        string command = "";
        getline(cin, command);

        if (command.find("push_back") != string::npos)
        {
            size_t spacePos = command.find(' ');
            string tempString = command.substr(spacePos, command.size());
            int tempInt = stoi(tempString);
            push_back(tempInt);
        }

        else if (command.find("push_front") != string::npos)
        {
            size_t spacePos = command.find(' ');
            string tempString = command.substr(spacePos, command.size());
            int tempInt = stoi(tempString);
            push_front(tempInt);
        }

        else if (command.find("pop_back") != string::npos)
        {
            pop_back();
        }

        else if (command.find("pop_front") != string::npos)
        {
            pop_front();
        }

        else if (command.find("front") != string::npos)
        {
            cout << front() << "\n";
        }

        else if (command.find("back") != string::npos)
        {
            cout << back() << "\n";
        }

        else if (command.find("size") != string::npos)
        {
            cout << sizeFunc() << "\n";
        }

        else if (command.find("empty") != string::npos)
        {
            cout << empty() << "\n";
        }
    }
    
    return 0;
}
