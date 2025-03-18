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
    for (int i = 1; i <= size; i++)
    {
        output.push(i);
    }

    while (output.size() > 1)
    {
        output.pop();
        output.push(output.front());
        output.pop();
    }

    cout << output.front();
    
    return 0;
}
