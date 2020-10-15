#include <iostream>

using namespace std;

int dp[(size_t)10e6 + 1];

int main()
{
    int N;
    cin >> N;

    dp[2] = 1;
    dp[3] = 1;
    
    for (int n{4}; n <= N; ++n)
    {
        int a = 10'000'000;
        int b = 10'000'000;
        int c = 10'000'000;

        if (n % 3 == 0)
        {
            a = dp[n / 3] + 1;
        }
        
        if (n % 2 == 0)
        {
            b = dp[n / 2] + 1;
        }
        
        c = dp[n-1] + 1;

        dp[n] = min(a, min(b, c));
    }

    cout << dp[N];

    return 0;
}
