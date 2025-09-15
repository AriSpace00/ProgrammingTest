#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    // 중간값 이하 요소를 내림차순 정렬
    priority_queue<int> leftQueue;

    // 중간값 이상 요소를 오름차순 정렬
    priority_queue<int, vector<int>, greater<int>> rightQueue;

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;

        if (leftQueue.empty() || temp <= leftQueue.top())
        {
            leftQueue.push(temp);
        }
        else
        {
            rightQueue.push(temp);
        }

        if (leftQueue.size() > rightQueue.size() + 1)
        {
            rightQueue.push(leftQueue.top());
            leftQueue.pop();
        }
        else if (rightQueue.size() > leftQueue.size())
        {
            leftQueue.push(rightQueue.top());
            rightQueue.pop();
        }

        cout << leftQueue.top() << "\n";
    }

    return 0;
}