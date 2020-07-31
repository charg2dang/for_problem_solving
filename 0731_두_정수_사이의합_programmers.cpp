#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b)
{
    if (a == b)
        return a;

    long long mi = min(a, b);
    long long ma = max(a, b);

    long long answer{};
    for (; mi <= ma; ++mi)
    {
        answer += mi;
    }

    return answer;
}