#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int size = 0;
	cin >> size;

	stack<int> output;
	for (int i = 0; i < size; i++)
	{
		int temp = 0;
		cin >> temp;

		if (temp != 0)
		{
			output.push(temp);
		}
		else
		{
			if (!output.empty())
			{
				output.pop();
			}
		}
	}

	int total = 0;
	while (!output.empty())
	{
		total += output.top();
		output.pop();
	}
	
	cout << total;

	return 0;
}
