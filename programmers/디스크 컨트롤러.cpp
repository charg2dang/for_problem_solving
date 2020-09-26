
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs)
{
    sort(begin(jobs), end(jobs));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    int index{};
    int current_time{};
    int working_time{};
    int job_num = jobs.size();


    while (index < job_num || pq.empty() == false)
    {
        while (index < job_num && jobs[index][0] <= current_time)
        {
            pq.emplace(make_pair(jobs[index][1], jobs[index][0]));
            index += 1;
        }

        if (pq.size() == 0)  // 수행 재개시.
        {
            current_time = jobs[index][0];

            continue;
        }


        auto& top = pq.top();
        int waiting_time = current_time - top.second;
        working_time += waiting_time;
        current_time += top.first;
        working_time += top.first;

        pq.pop();
    }

    return working_time / job_num;
}


#include <iostream>

void main()
{
    cout << solution({ {0, 3}, {1, 9}, {2, 6} });

    cout << "\n\n\n\n";


    cout << solution({ {0, 3}, {1, 9}, {500, 6} });

    cout << "\n\n\n\n";

    cout << solution({ {0, 9}, {0, 4}, {0 , 5}, {0, 7}, { 0, 3} });

    cout << "\n\n\n\n";


    cout << solution({ {0, 1}, {0, 2}, {0 , 3}, {0, 4} });

    cout << "\n\n\n\n";
}