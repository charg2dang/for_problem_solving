
#include <vector>

using namespace std;

int do_dfs(int symbol, int y, int x, vector<vector<int>>& picture, vector<vector<bool>>& visits) // return value -> area size
{
    static int dirs[4][2]{ { 0L, -1L }, { -1L, 0 }, { 0 , 1L }, { 1 ,0 } };//   y, x

    int area_size{};

    if (y >= visits.size() || y < 0) // y 범위 체크.
    {
        return 0;
    }

    if (x >= visits[0].size() || x < 0) // x 범위 체크.
    {
        return 0;
    }


    if (picture[y][x] != symbol) // 다른 영역도 out
    {
        return 0;
    }

    if (visits[y][x] == true) // 이미 방문한곳은 out
    {
        return 0;
    }


    visits[y][x] = true;
    area_size += 1;

    area_size += do_dfs(symbol, y + dirs[0][0], x + dirs[0][1], picture, visits); // 좌
    area_size += do_dfs(symbol, y + dirs[1][0], x + dirs[1][1], picture, visits); // 상
    area_size += do_dfs(symbol, y + dirs[2][0], x + dirs[2][1], picture, visits); // 우
    area_size += do_dfs(symbol, y + dirs[3][0], x + dirs[3][1], picture, visits); // 하

    return area_size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    vector<vector<bool>> visits(m, vector<bool>(n, false));  // visits 초기화 

    int max_size_of_one_area{};
    int number_of_area{};

    for (int y{}; y < m; ++y) // 순차 탐색
    {
        for (int x{}; x < n; ++x)
        {
            if (picture[y][x] != 0 && visits[y][x] == false)  // 빈공간이 아니고 // 방문 안했으면 
            {
                int symbol = picture[y][x];

                // dfs로 탐색 
                // visits 배열로 표시
                int area_size = do_dfs(symbol, y, x, picture, visits);
                if (max_size_of_one_area < area_size)
                {
                    max_size_of_one_area = area_size;
                }

                number_of_area += 1;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return move(answer);
}

// 영역 경게 상하좌우 0이거나 왼 -1 or  오른 범위 인덱스거나.

#include <iostream>

void main()
{
    vector<vector<int>> picture{ {1, 1, 1, 0}, {1, 2, 2, 0 }, {1,0,0,1}, {0,0,0,1}, {0,0,0,3}, {0,0,0,3} };
    auto ret = solution(6, 4, picture);
    for (int r : ret)
    {
        cout << r << endl;
    }
    cout << "\n\n\n\n";
}