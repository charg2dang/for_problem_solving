#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int t{};
    int counter{};

    vector<int> cs;

    for (int n = 0; n <= 1000; ++n)
    {
        t = N - (n * 5);
        if (t < 0)
        {
            break;
        }

        if (t % 3 == 0)
        {
            counter = n;
            counter += (t / 3);

            cs.push_back(counter);
        }
        
        if (counter <= 0)
        {
            counter = -1;
        }
    }

    if (cs.empty() == true)
    {
        cout << -1;
    }
    else
    {
        cout << *min_element(cs.begin(), cs.end());
    }

    return 0;
}
