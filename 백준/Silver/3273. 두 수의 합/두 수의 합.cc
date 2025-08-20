#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool frequency[1000001] = {};
    for (int i = 0; i < n; i++)
    {
        frequency[arr[i]] = true;
    }

    int add = 0;
    cin >> add;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int complement = add - arr[i];
        if (complement > 0 && complement <= 1000000 && frequency[complement])
        {
            count++;
        }
    }

    cout << count / 2;

    return 0;
}