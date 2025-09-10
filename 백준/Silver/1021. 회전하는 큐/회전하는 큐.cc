#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	deque<int> field;
	for (int i = 0; i < n; i++)
	{
		field.push_back(i);
	}

	int totalCount = 0;
	for (int i = 0; i < m; i++)
	{
		int current = 0;
		cin >> current;
		--current;

		int currentIndex = find(field.begin(), field.end(), current) - field.begin();
		int leftCount = currentIndex;
		int rightCount = field.size() - currentIndex;

		// 왼쪽으로 회전
		if (leftCount <= rightCount)
		{
			while (field.front() != current)
			{
				field.push_back(field.front());
				field.pop_front();
				totalCount++;
			}
		}
		else
		{
			while (field.front() != current)
			{
				field.push_front(field.back());
				field.pop_back();
				totalCount++;
			}
		}
		
		field.pop_front();
	}

	cout << totalCount;

	return 0;
}