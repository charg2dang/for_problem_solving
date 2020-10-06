
#include <string>
#include <vector>
#include <iostream>

using namespace std;

constexpr size_t max_value = 8;

int solution(vector<vector<int>> triangle);

void main()
{
    cout << solution({ { 7 }, {3, 8}, {8, 1, 0} , { 2, 7 , 4, 4 }, {4, 5, 2, 6, 5} });
}


// 너무 느린 dfs
//int do_dfs(vector<vector<int>>& triangle, long long h, long long idx, long long val)
//{
//    if (h >= triangle.size())
//    {
//        return val;
//    }
//
//    if (idx >= triangle[h].size())
//    {
//        return val;
//    }
//
//    val += triangle[h][idx];
//
//    int l_max = do_dfs(triangle, h + 1, idx, val);
//    int r_max = do_dfs(triangle, h + 1, idx + 1, val);
//
//    return max(l_max, r_max);
//}

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

int solution(vector<vector<int>> triangle)
{
    short h = triangle.size();
    switch (h)
    {
    case 1:
        return triangle[0][0];
    case 2:
        return max(triangle[1][1], triangle[1][0]) + triangle[0][0];
    default:
        break;
    }

    vector<vector<int>> cache(triangle.size(), vector<int>(triangle[h - 1].size(), 0));
    cache[1][0] = triangle[1][0];
    cache[1][1] = triangle[1][1];

    for (short cur_h{ 2 }; cur_h < h; ++cur_h) // 2단 부터
    {
        for (short cur_w{ 0 }; cur_w <= cur_h; ++cur_w)
        {
            long long lt{};
            if (cur_w - 1 >= 0)
            {
                lt = cache[cur_h - 1][cur_w - 1];
            }
            long long rt{ cache[cur_h - 1][cur_w] };

            cache[cur_h][cur_w] = triangle[cur_h][cur_w] + max(lt, rt);
        }
    }


    return *max_element(cache[h - 1].begin(), cache[h - 1].end()) + triangle[0][0];
}
