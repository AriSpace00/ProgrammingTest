#include <iostream>
#include <string>

using namespace std;

int main()
{
	int temp = 0;
	int total = 1;
	int repeatNum = 3;
	for (int i = 0; i < repeatNum; i++)
	{
		cin >> temp;
		total *= temp;
	}

	int frequency[10] = { };
	string totalString = to_string(total);
	for (char& s : totalString)
	{
		frequency[s - '0']++;
	}

	for (int i : frequency)
	{
		cout << i << endl;
	}

	return 0;
}