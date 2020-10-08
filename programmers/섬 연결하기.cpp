#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

int solution()
{
    int n{};
    int m{};
    int k{};

    cin >> n;
    cin >> m;
    cin >> k;

    vector<int> ns;

    for (int i{}; i < n; ++i)
    {
        int input{};
        cin >> input;
        ns.push_back(input);
    }

    std::sort(ns.begin(), ns.end(), greater<int>());

    int c{};
    int sum{};

    int first = ns[0];
    int second = ns[1];

    int first_count = m / (k + 1) * k;
    first_count += m % (k + 1);

    sum += (first_count * first);
    sum += (m - first_count) * second;

    return sum;
}



void main()
{
    cout << solution();
}

