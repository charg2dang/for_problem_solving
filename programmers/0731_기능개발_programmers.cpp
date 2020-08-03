#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    int elapsed_day{};
    int completed_func{};
    
    for (int n{}; n < progresses.size(); ++ n)
    {
        int p       = progresses[n];
        int speed   = speeds[n];

        if (p + ( elapsed_day * speed ) >= 100) // �̻��̸� ���� ������� �Ѿ.
        {
            completed_func += 1;

            continue;  
        }
        else // ��¥�� �ٲ�.
        {
            if (completed_func != 0)
            {
                answer.push_back(completed_func);
                completed_func = 0;
            }

            int k = 100 - p;

            elapsed_day = (k % speed) > 0 ? ( k / speed ) +1 : k / speed; // �ּ� �ϼ�.

            completed_func += 1;
        }
    }

    if (completed_func != 0)
    {
        answer.push_back(completed_func);
    }

    return answer;
}

