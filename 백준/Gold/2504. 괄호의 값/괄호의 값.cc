#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string temp = "";
	cin >> temp;

	char previous = '\0';

	stack<char> pairs;

	// 더해질 값
	int sum = 0;

	// 곱해질 값
	int num = 1;

	for (char current : temp)
	{
		switch (current)
		{
		case('('):
		{
			num *= 2;
			pairs.push(current);
		}
		break;
		case('['):
		{
			num *= 3;
			pairs.push(current);
		}
		break;
		case(')'):
		{
			if (pairs.empty() || pairs.top() != '(')
			{
				cout << 0;
				return 0;
			}

			if (previous == '(')
				sum += num;
			pairs.pop();
			num /= 2;
		}
		break;
		case(']'):
		{
			if (pairs.empty() || pairs.top() != '[')
			{
				cout << 0;
				return 0;
			}

			if (previous == '[')
				sum += num;
			pairs.pop();
			num /= 3;
		}
		break;
		}

		previous = current;
	}

	if (pairs.empty())
		cout << sum;
	else
		cout << 0;

	return 0;
}