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
   
    int left = 0;
    int right = 0;

    while (true)
    {
        if (total >= m)
        {
            if (total == m)
            {
                count++;
            }

            total -= temp[left];
            left++;
        }
        else if (right == n)
        {
            break;
        }
        else
        {
            total += temp[right];
            right++;
        }
    }

    cout << count;

    return 0;
}