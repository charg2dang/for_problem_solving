#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[501][501];

int main()
{
    int N;
    cin >> N;

    vector<int> ns;
    ns.reserve(N);

    for (int n{}; n < N; ++n)
    {
        for (int m{}; m <= n; ++m)
        {
            int i;
            cin >> i;
            ns.push_back(i);
        }
    }
    
    dp[0][0] = ns[0];
    
    int ns_idx{1};

    int y{1};
    for (; y < N; ++y)
    {
        dp[y][0] = dp[y - 1][0] + ns[ns_idx];
        ns_idx += 1;
        
        for (int x{ 1 }; x <= y; ++x)
        {
            dp[y][x] = max(dp[y-1][x], dp[y - 1][x-1]) + ns[ns_idx];
            ns_idx += 1;
        }
    }

    y -= 1;

    cout << *max_element(begin(dp[y]), end(dp[y]));

    return 0;
}
