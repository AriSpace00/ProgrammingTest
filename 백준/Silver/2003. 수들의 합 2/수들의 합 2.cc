#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;

    vector<int> temp(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    int total = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        total += temp[i];

        if (total == m)
        {
            count++;
            total = 0;
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            total += temp[j];

            if (total == m)
            {
                count++;
                break;
            }
            else if (total > m)
            {
                break;
            }
        }
        
        total = 0;
    }

    cout << count;

    return 0;
}