#include <iostream>
using namespace std;

int func(int a, int b, int c)
{
    if (b == 1)
        return a % c;

    long long value = func(a, b / 2, c);
    value = value * value % c;

    if (b % 2 == 0)
        return value;

    return value * a % c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    cout << func(a, b, c);

    return 0;
}

