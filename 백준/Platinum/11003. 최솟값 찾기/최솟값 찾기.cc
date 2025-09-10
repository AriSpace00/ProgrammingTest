#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n = 0, l = 0;
	cin >> n >> l;

	vector<int> field(n, INT_MAX);
	deque<int> indexs;
	for (int i = 0; i < n; i++)
	{
		cin >> field[i];

		while (!indexs.empty() && indexs.front() <= i - l)
		{
			indexs.pop_front();
		}

		while (!indexs.empty() && field[indexs.back()] >= field[i])
		{
			indexs.pop_back();
		}

		indexs.push_back(i);

		cout << field[indexs.front()] << " ";
	}

	return 0;
}