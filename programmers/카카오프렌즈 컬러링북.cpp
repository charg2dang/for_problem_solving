
#include <vector>

using namespace std;

int do_dfs(int symbol, int y, int x, vector<vector<int>>& picture, vector<vector<bool>>& visits) // return value -> area size
{
    static int dirs[4][2]{ { 0L, -1L }, { -1L, 0 }, { 0 , 1L }, { 1 ,0 } };//   y, x

    int area_size{};

    if (y >= visits.size() || y < 0) // y ���� üũ.
    {
        return 0;
    }

    if (x >= visits[0].size() || x < 0) // x ���� üũ.
    {
        return 0;
    }


    if (picture[y][x] != symbol) // �ٸ� ������ out
    {
        return 0;
    }

    if (visits[y][x] == true) // �̹� �湮�Ѱ��� out
    {
        return 0;
    }


    visits[y][x] = true;
    area_size += 1;

    area_size += do_dfs(symbol, y + dirs[0][0], x + dirs[0][1], picture, visits); // ��
    area_size += do_dfs(symbol, y + dirs[1][0], x + dirs[1][1], picture, visits); // ��
    area_size += do_dfs(symbol, y + dirs[2][0], x + dirs[2][1], picture, visits); // ��
    area_size += do_dfs(symbol, y + dirs[3][0], x + dirs[3][1], picture, visits); // ��

    return area_size;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    vector<vector<bool>> visits(m, vector<bool>(n, false));  // visits �ʱ�ȭ 

    int max_size_of_one_area{};
    int number_of_area{};

    for (int y{}; y < m; ++y) // ���� Ž��
    {
        for (int x{}; x < n; ++x)
        {
            if (picture[y][x] != 0 && visits[y][x] == false)  // ������� �ƴϰ� // �湮 �������� 
            {
                int symbol = picture[y][x];

                // dfs�� Ž�� 
                // visits �迭�� ǥ��
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

// ���� ��� �����¿� 0�̰ų� �� -1 or  ���� ���� �ε����ų�.

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