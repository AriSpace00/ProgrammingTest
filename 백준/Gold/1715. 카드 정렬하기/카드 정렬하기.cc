#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    priority_queue <long long , vector<long long>, greater<long long>> minQueue;
    for (int i = 0; i < n; i++)
    {
        long long temp = 0;
        cin >> temp;
        minQueue.push(temp);
    }

    long long sum = 0;
    while (minQueue.size() > 1)
    {
        long long current = 0;
        for (int i = 0; i < 2; i++)
        {
            current += minQueue.top();
            minQueue.pop();
        }
        
        sum += current;
        minQueue.push(current);
    }

    cout << sum;

    return 0;
}