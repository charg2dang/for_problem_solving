#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    deque<int> printout_dq(priorities.begin(), priorities.end());
    sort(priorities.begin(), priorities.end(), greater<int>()); // 내림차순 정렬.

    int answer{ };
    int order{ };

    while (printout_dq.empty() == false)
    {
        while (printout_dq.front() != priorities[order])
        {
            printout_dq.push_back(printout_dq.front());
            printout_dq.pop_front();

            location -= 1;
            if (location < 0)
            {
                location = printout_dq.size() - 1;
            }
        }

        if (location == 0)
        {
            return answer + 1;
        }

        printout_dq.pop_front();
        answer += 1;
        order += 1;
        location -= 1;
    }
}


#include <iostream>

void main()
{
    cout << solution({ 2, 1, 3, 2 }, 2) << endl;
    cout << solution({ 1, 1, 9, 1, 1, 1 }, 0) << endl;
    cout << solution({ 1, 1, 2, 1 }, 1) << endl;
    cout << solution({ 1, 1, 3, 2, 1, 4, 1, 1, 3, 1, 1, 1 }, 8) << endl;
    cout << solution({ 2, 3, 1, 4, 5, 9, 6, 7 }, 5) << endl;
    cout << solution({ 9, 9, 9, 9, 9 }, 0) << endl; // for 14 case
    cout << solution({ 2, 1, 2, 1, 3, 2 }, 0) << endl;
}