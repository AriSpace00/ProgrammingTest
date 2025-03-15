#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() 
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    list<int> list;
    for (int i = 0; i < n; ++i)
    {
        list.push_back(i + 1);
    }
    
    auto iter = list.begin();

    cout << "<";
    while (!list.empty())
    {
        for (int i = 0; i < k - 1; ++i)
        { 
            ++iter;

            if (iter == list.end())
            {
                iter = list.begin(); 
            }
        }
        cout << *iter;
        iter = list.erase(iter);

        if (!list.empty())
        {
            cout << ", ";
            if (iter == list.end())
                iter = list.begin();
        }
    }
    cout << ">";

    return 0;
}
