
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution()
{
    int x{};
    cin >> x;

    vector<int> d(30001, 0);

    for (int n{2}; n < x+1; ++n)
    {
        d[n] = d[n - 1] + 1;

        if ( n % 2 == 0)
        {
            d[n] = min(d[n], d[n/2] + 1);
        }

        if (n % 3 == 0)
        {
            d[n] = min(d[n], d[n / 3] + 1);
        }

        if (n % 5 == 0)
        {
            d[n] = min(d[n], d[n / 5] + 1);
        }
    }

    return d[x];
}



void main()
{
    cout << solution();
}

