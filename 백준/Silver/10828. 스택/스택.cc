#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int size = 0;
	cin >> size;
	cin.ignore();

	vector<string> commandArr(size, "");
	for (int i = 0; i < size; i++)
	{
		string temp = "";
		getline(cin, temp);
		commandArr[i] = temp;
	}

	stack<int> output;
	for (int i = 0; i < commandArr.size(); i++)
	{
		if (commandArr[i].find("push") != string::npos)
		{
			size_t spacePos = commandArr[i].find(' ');
			string tempString = commandArr[i].substr(spacePos + 1, commandArr[i].size());
			int tempInt = stoi(tempString);
			output.push(tempInt);
		}

		else if (commandArr[i].find("top") != string::npos)
		{
			if (output.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << output.top() << endl;
			}
		}

		else if (commandArr[i].find("size") != string::npos)
		{
			cout << output.size() << endl;
		}

		else if (commandArr[i].find("empty") != string::npos)
		{
			cout << output.empty() << endl;
		}

		else if (commandArr[i].find("pop") != string::npos)
		{
			if (output.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << output.top() << endl;
				output.pop();
			}
		}
	}

	return 0;
}
