#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer{};

    deque<short> dq;

    dq.push_front(0);

    for ( int n : numbers )
    {
        int counter = dq.size();

        while (counter != 0)
        {
            short value = dq.front();
            dq.pop_front();

            dq.push_back( value + n );
            dq.push_back( value - n );
            
            counter -= 1;
        }
    }

    for ( short value : dq ) 
    {
        if (value == target)
        {
            answer += 1;
        }
    }

    return answer;
}

// 위에는 개인적인 생각으로 너비 우선 탐색으로 판단하고 제작.


