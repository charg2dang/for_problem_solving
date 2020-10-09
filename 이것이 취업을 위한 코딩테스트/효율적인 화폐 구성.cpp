#include <vector>
#include <iostream>

using namespace std;

int solution()
{
    int number, m;
    cin >> number;
    cin >> m;

    //
    vector<int> arr;
    arr.reserve(number);

    for (int n{}; n < number; ++n)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    // initialize dp table.
    vector<int> dp(10'001, 10'001);

    // do dp using bottom_up
    dp[0] = 0;
    for (int a{}; a < number; ++a ) // 0 ~ n-1
    {
        for (int b{ arr[a] }; b <= m; ++b) // arr[a] ~ m
        {
            // dp[b-arr[a]] 0 1 2 3 4
            if (dp[b - arr[a]] != 10'001) // ( b - arr[a] ) 원을 만드는 방법이 존재하는 경우.
            {
                dp[b] = min(dp[b], dp[b - arr[a]] + 1); // 최솟값.
            }
        }
    }

    if (dp[m] == 10'001) // 최종적으로 M원을 만드는 방법이 없는 경우.
    {
        return -1;
    }
    else
    {
        return dp[m];
    }

}

int main()
{
    cout << solution();
    return 0;
}
