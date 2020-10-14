//피보나치 함수
#include <iostream>
#include <vector>

using namespace std;

long long calc_fibonacci(int n, int& z, int& o)
{
    static long long cache[41]{ 0, 1 };
    static long long zero_cache[41]{ 1, 0 };
    static long long one_cache[41]{ 0, 1 };

    switch (n)
    {
    case 0:
        z = zero_cache[n];
        o = one_cache[n];
        return 0;
    case 1:
        z = zero_cache[n];
        o = one_cache[n];
        return 1;
    default:
        break;
    }
    
    if (cache[n] == 0)
    {
        for (int i{ 2 }; i <= n; ++i)
        {
            if (cache[i] == 0)
            {
                cache[i]        = cache[i - 1]      + cache[i - 2];
                zero_cache[i]   = zero_cache[i - 1] + zero_cache[i - 2];
                one_cache[i]    = one_cache[i - 1]  + one_cache[i - 2];
            }
        }
    }
    
    z = zero_cache[n];
    o = one_cache[n];

    return cache[n];
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, int>> results;
    results.reserve(N);

    for (int n{}; n < N; ++n)
    {
        int i;
        cin >> i;
        int z{}, o{};
        calc_fibonacci(i, z, o);
        results.push_back(make_pair(z, o));
    }

    for (const auto& r : results)
    {
        cout << r.first << " " << r.second << "\n";
    }

    return 0;
}
