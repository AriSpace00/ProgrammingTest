#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k = 0, swapCount = 0;
pair<int, int> answer;

int partition(vector<int>& arr, int start, int end)
{
	int pivotValue = arr[end];
	int newPivot = start - 1;

	for (int j = start; j < end; j++)
	{
		if (arr[j] <= pivotValue)
		{
			++newPivot;
			int temp = arr[newPivot];

			arr[newPivot] = arr[j];
			arr[j] = temp;

			swapCount++;
			if (swapCount == k)
			{
				answer.first = min(arr[newPivot], arr[j]);
				answer.second = max(arr[newPivot], arr[j]);
			}
		}
	}

	if (newPivot + 1 != end)
	{
		int temp = arr[newPivot + 1];

		arr[newPivot + 1] = arr[end];
		arr[end] = temp;

		swapCount++;
		if (swapCount == k)
		{
			answer.first = min(arr[newPivot + 1], arr[end]);
			answer.second = max(arr[newPivot + 1], arr[end]);
		}
	}

	return newPivot + 1;
}

void quick_sort(vector<int>& arr, int start, int end)
{
	if (start < end)
	{
		int pivot = partition(arr, start, end);
		quick_sort(arr, start, pivot - 1);
		quick_sort(arr, pivot + 1, end);
	}
}

int main()
{
	int n;
	cin >> n >> k;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	quick_sort(arr, 0, n - 1);

	if (swapCount < k)
	{
		cout << -1;
	}
	else
	{
		cout << answer.first << " " << answer.second;
	}

	return 0;
}