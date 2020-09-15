#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    sort(begin(citations), end(citations), greater<int>());

    int n{1};

    for ( int c : citations )
    {
        if (n >= c)
        {
            if (n == c)
            {
                return n;
            }
            else  // n > c
            {
                return n - 1;
            }
        }
        
        n += 1;
    }

    return citations.size();
}

