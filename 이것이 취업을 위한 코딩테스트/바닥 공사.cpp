#include <vector>
#include <iostream>

using namespace std;

int solution()
{
    int number;
    cin >> number;

    int dp[1001]{};
    dp[1] = 1;
    dp[2] = 3;

    for (int n{ 3 }; n <= number; ++n)
    {
        dp[n] = (dp[n - 1] + 2 * dp[n-2]) % 796'796;
    }

    return dp[number];
}

int main()
{
    cout << solution();
    return 0;
}
