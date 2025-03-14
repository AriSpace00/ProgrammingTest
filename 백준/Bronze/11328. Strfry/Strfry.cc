#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int size = 0;
	cin >> size;

	string temp1 = "";
	string temp2 = "";

	vector<vector<string>> tempArr;
	tempArr.resize(size);

	for (int i = 0; i < size; i++)
	{
		tempArr[i] = { "","" };
	}

	for (int i = 0; i < size; i++)
	{
		cin >> temp1;
		cin >> temp2;

		tempArr[i][0] = temp1;
		tempArr[i][1] = temp2;
	}

	vector<int> frequency1(26, 0);
	vector<int> frequency2(26, 0);
	for (int i = 0; i < size; i++)
	{
		for (char& c : tempArr[i][0])
		{
			frequency1[c - 'a']++;
		}

		for (char& c : tempArr[i][1])
		{
			frequency2[c - 'a']++;
		}

		bool isPossible = true;
		for (int i = 0; i < frequency1.size(); i++)
		{
			if (frequency1[i] != frequency2[i])
			{
				isPossible = false;
			}
		}

		if (isPossible)
			cout << "Possible" << endl;
		else
			cout << "Impossible" << endl;

		frequency1.assign(frequency1.size(), 0);
		frequency2.assign(frequency2.size(), 0);
	}

	return 0;
}