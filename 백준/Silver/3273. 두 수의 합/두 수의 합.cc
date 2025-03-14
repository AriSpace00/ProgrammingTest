#include <iostream>
#include <vector>

using namespace std;

bool visitedArr[1000001];

int main()
{
	// 수열 크기 입력
	int size = 0;
	cin >> size;

	// 수열에 들어갈 숫자 입력
	int temp = 0;
	vector<int> tempArr(size, 0);
	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		tempArr[i] = temp;
	}

	// 두 자연수의 합 입력
	cin >> temp;

	int count = 0;
	for (int i = 0; i < size; i++)
	{
		int complement = temp - tempArr[i];
		if (complement > 0 && complement <= 1000000 && visitedArr[complement])
		{
			count++;
		}

		visitedArr[tempArr[i]] = true;
	}

	cout << count;

	return 0;
}