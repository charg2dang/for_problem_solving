#include <vector>
#include <iostream>

using namespace std;

int solution()
{
    int number;
    cin >> number;

    vector<int> ns;
    ns.reserve(number);
    for (int n{}; n < number; ++n)
    {
        int a;
        cin >> a;
        ns.emplace_back(a);
    }

    int dp[100]{};

    dp[0] = ns[0];
    dp[1] = max(ns[0], ns[1]);
    for (int n{ 2 }; n < number; ++n)
    {
        dp[n] = max(dp[n - 1], dp[n - 2] + ns[n]);
    }

    return dp[number - 1];
}


int main()
{
    cout << solution();
    return 0;
}
