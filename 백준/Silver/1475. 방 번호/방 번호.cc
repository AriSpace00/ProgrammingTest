#include <iostream>
#include <string>

using namespace std;

int main()
{
	int input = 0;
	cin >> input;

	string inputString = to_string(input);
	int frequency[10] = {};
	for (char& c : inputString)
	{
		frequency[c - '0']++;
	}

	for (int i = 0; i < sizeof(frequency) / sizeof(int); i++)
	{
		if (i == 9)
		{
			int temp = (frequency[i] + frequency[6]) / 2 + (frequency[i] + frequency[6]) % 2;
			frequency[6] = temp;
			frequency[i] = temp;
				
		}
	}

	int max = 0;
	for (int i : frequency)
	{
		if (max < i)
		{
			max = i;
		}
	}

	cout << max;

	return 0;
}