#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

int main()
{
	string temp = "";
	cin >> temp;

	list<char> tempArr;
	for (char c : temp)
	{
		tempArr.push_back(c);
	}
	list<char>::iterator cursorIt = tempArr.end();

	int size = 0;
	cin >> size;
	cin.ignore();

	vector<string> commandArr;
	for (int i = 0; i < size; i++)
	{
		getline(cin, temp);
		commandArr.push_back(temp);
	}

	for (int i = 0; i < size; i++)
	{
		if (commandArr[i].length() > 1)
		{
			char addChar = *(commandArr[i].end() - 1);
			list<char>::iterator tempIt = cursorIt;
			tempArr.insert(tempIt, addChar);
		}
		else
		{
			if (commandArr[i] == "L")
			{
				if (cursorIt != tempArr.begin())
					--cursorIt;

			}
			else if (commandArr[i] == "D")
			{
				if (cursorIt != tempArr.end())
					++cursorIt;
			}
			else if (commandArr[i] == "B")
			{
				list<char>::iterator tempIt = cursorIt;
				if (cursorIt != tempArr.begin())
					tempArr.erase(--tempIt);
			}
		}
	}

	for (char& c : tempArr)
	{
		cout << c;
	}

	return 0;
}