#include <iostream>
#include <string>

using namespace std;

int main()
{
    int frequency[26] = {};
    string input;
    cin >> input;

    for (char& temp : input)
    {
        frequency[temp - 'a']++;
    }

    for (int temp : frequency)
    {
        cout << temp << " ";
    }

    return 0;
}