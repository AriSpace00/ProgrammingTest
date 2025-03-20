#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M = 0;
    cin >> N;
    cin >> M;

    deque<int> dequeArr;
    for (int i = 0; i < N; i++)
    {
        dequeArr.push_back(i + 1);
    }

    int count = 0;
    for (int i = 0; i < M; i++)
    {
        int temp = 0;
        cin >> temp;

        int index = find(dequeArr.begin(), dequeArr.end(), temp) - dequeArr.begin();
        int leftMoves = index;
        int rightMoves = dequeArr.size() - index;

        if (leftMoves <= rightMoves)
        {
            for (int j = 0; j < leftMoves; j++)
            {
                dequeArr.push_back(dequeArr.front());
                dequeArr.pop_front();
            }

            count += leftMoves;
        }
        else
        {
            for (int j = 0; j < rightMoves; j++)
            {
                dequeArr.push_front(dequeArr.back());
                dequeArr.pop_back();
            }

            count += rightMoves;
        }

        dequeArr.pop_front();
    }

    cout << count;
    
    return 0;
}
