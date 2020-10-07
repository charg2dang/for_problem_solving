#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    sort(begin(routes), end(routes));

    int answer = 1;

    int end_point = routes[0][1];

    for (const auto& route : routes)
    {
        int s_p = route[0];
        int e_p = route[1];

        if (s_p > end_point) // e_p만 비교 하면됨.
        {
            answer += 1;
            end_point = e_p;
        }

        end_point = min(e_p, end_point);
    }

    return answer;
}

void main()
{

    cout << solution({ {-20, 15}, {-14, -5},{-18, -13}, { -5, -3 } }) << endl;
    cout << solution({ {-2, -1}, { 1, 2}, {-3, 0} }) << endl;
    cout << solution({ {0, 0} }) << endl;
    cout << solution({ {0, 1}, {0, 1}, {1, 2} }) << endl;
    cout << solution({ {0, 1}, {2, 3}, {4, 5}, {6, 7} }) << endl;
    cout << solution({ {-20, 15}, {-20, -15},{-14, -5},{-18, -13}, { -5, -3 } }) << endl;
}

