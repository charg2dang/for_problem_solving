
#include <vector>
#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    vector<vector<long long>> map(m + 1, vector<long long>(n + 1, 1));
    for (const auto& puddle : puddles)
    {
        map[puddle[0]][puddle[1]] = 0;
    }

    // 테두리 한번 해주고.
    bool has_pool_x = false;
    for (int x = 0; x < m; ++x) // x
    {
        if (map[x][0] == 0)
        {
            has_pool_x = true;
        }

        if (has_pool_x == true)
        {
            map[x][0] = 0;
        }
    }

    bool has_pool_y = false;
    for (int y = 0; y < n; ++y) // x
    {
        if (map[0][y] == 0)
        {
            has_pool_y = true;
        }

        if (has_pool_y == true)
        {
            map[0][y] = 0;
        }
    }


    int maximum = max(m, n);
    for (int i = 1; i < maximum; ++i)
    {
        const int cx = ::min(i, m - 1);
        const int cy = ::min(i, n - 1);

        int x = ::min(i, cx);
        int y = ::min(i, cy);

        for (; x < m; ++x)
        {
            if (map[x][cy] == 0) // 침수 된곳은 패스
            {
                continue;
            }

            map[x][cy] = map[x - 1][cy] + map[x][cy - 1] % 1'000'000'007;
        }

        for (; y < n; ++y)
        {
            if (map[cx][y] == 0)
            {
                continue;
            }

            map[cx][y] = map[cx - 1][y] + map[cx][y - 1] % 1'000'000'007;
        }
    }

    long long result = map[m - 1][n - 1];
    if (result == -1)
    {
        return 0;
    }
    else
    {
        return map[m - 1][n - 1];
    }
}

void main()
{
    cout << solution(4, 3, { {2, 2} });
    //cout << solution(4, 4, { {2, 2} });
}

