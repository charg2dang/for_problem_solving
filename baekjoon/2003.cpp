#include <vector>
#include <iostream>

using namespace std;

int main()
{
       int n, m;
    vector<int> ns;

    cin >> n >> m;
    for (int a{}; a < n; ++a)
    {
        int input;
        cin >> input;
        ns.push_back(input);
    }

    int lower_bound{};
    int upper_bound{};
    int s{};
    int counter{};

    while(lower_bound < n)
    {
        if (m > s && upper_bound != n)
        {
            s += ns[upper_bound];
            upper_bound += 1;
        }
        else
        {
            s -= ns[lower_bound];
            lower_bound += 1;
        }

        if (m == s)
        {
            counter += 1;
        }

    }

    cout << counter << endl;
    return 0;
}
