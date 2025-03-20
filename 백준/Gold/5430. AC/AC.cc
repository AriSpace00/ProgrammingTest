#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string command = "";
		cin >> command;

		int size = 0;
		cin >> size;
		cin.ignore();

		string tempString = "";
		cin >> tempString;

		stringstream ss(tempString);

		int tempInt = 0;
		char tempChar;
		deque<int> info;

		while (ss >> tempChar)
		{
			if (isdigit(tempChar))
			{
				ss.unget();
				ss >> tempInt;
				info.push_back(tempInt);
			}
		}

		bool isReversed = false;
		bool isError = false;
		for (char c : command)
		{
			switch (c)
			{
			case 'R':
			{
				isReversed = !isReversed;
			}
			break;
			case 'D':
			{
				if (!info.empty())
				{
					if (!isReversed)
						info.pop_front();
					else
						info.pop_back();
				}
				else
				{
					isError = true;
					break;
				}
			}
			break;
			}
		}

		if (!isError)
		{
			cout << "[";
			if (!info.empty())
			{
				if (!isReversed)
				{
					cout << info.front();
					info.pop_front();
					while (!info.empty())
					{
						cout << "," << info.front();
						info.pop_front();
					}
				}
				else {
					cout << info.back();
					info.pop_back();
					while (!info.empty())
					{
						cout << "," << info.back();
						info.pop_back();
					}
				}
			}
			cout << "]\n";
		}
		else
		{
			cout << "error\n";
		}
	}

	return 0;
}
