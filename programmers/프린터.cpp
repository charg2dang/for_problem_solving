#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer{ 1 };

    deque<int> printout_dq(priorities.begin(), priorities.end());
    
    while(printout_dq.empty() != true)
    {
        int max_num{ };
        int max_idx{ };
        int counter{ };

        for (int p : printout_dq)
        {
            if (p > max_num)
            {
                max_num = p;
                max_idx = counter;
            }

            counter += 1;
        }

        for (int n{}; n < max_idx; ++n)
        {
            printout_dq.push_back(printout_dq.front());
            printout_dq.pop_front();

            location -= 1;
            if (location < 0)
            {
                location = printout_dq.size() - 1;
            }
        }

        if (location == 0) // 종료 조건
        {
            return answer;
        }
        else
        {
            printout_dq.pop_front();
            answer += 1;
            location -= 1;
        }
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
    cout << solution({ 9, 9, 9, 9, 9}, 0) << endl; // for 14 case
    cout << solution({ 2, 1, 2, 1, 3, 2 }, 0) << endl;
}
