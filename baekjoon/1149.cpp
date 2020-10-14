#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;
    
    vector<vector<int>> costs(N, vector<int>());
    int dp[3][1001]{};


    for (int n{}; n < N; ++n)
    {
        int r, g, b;
        cin >> r >> g >> b;

        costs[0].push_back(r);
        costs[1].push_back(g);
        costs[2].push_back(b);
    }

    dp[0][0] = costs[0][0];
    dp[1][0] = costs[1][0];
    dp[2][0] = costs[2][0];

    int n{ 1 };
    for (; n <= N; ++n)
    {
        dp[0][n] = min(dp[1][n - 1], dp[2][n - 1]) + costs[0][n];
        dp[1][n] = min(dp[0][n - 1], dp[2][n - 1]) + costs[1][n];
        dp[2][n] = min(dp[0][n - 1], dp[1][n - 1]) + costs[2][n];
    }

    cout << min(dp[0][n-1], min(dp[1][n - 1], dp[2][n - 1]) )  << "\n";
    
    return 0;
}
