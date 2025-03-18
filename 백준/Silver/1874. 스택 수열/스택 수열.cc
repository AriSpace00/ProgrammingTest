#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int size = 0;
	cin >> size;

	vector<int> tempArr(size, 0);
	for (int i = 0; i < size; i++)
	{
		int temp = 0;
		cin >> temp;
		tempArr[i] = temp;
	}

	stack<int> tempStack;
	vector<string> output;
	int pushNum = 0;
	for (int i = 0; i < tempArr.size(); i++)
	{
		while (tempArr[i] > pushNum)
		{
			pushNum++;
			tempStack.push(pushNum);
			output.push_back("+");
		}
		
		if (!tempStack.empty() && tempStack.top() == tempArr[i])
		{
			tempStack.pop();
			output.push_back("-");
		}
		else
		{
			cout << "NO" << "\n";
			return 0;
		}
	}

	for (string s : output)
	{
		cout << s << "\n";
	}

	return 0;
}
