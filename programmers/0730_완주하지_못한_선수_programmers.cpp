#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_multiset<string> p_s{participant.begin(), participant.end()};

    for (string& p : completion)
    {
        auto it = p_s.erase(p);
        if (it > 1)
        {
            for (int n{}; n < (it - 1); ++n)
            {
                p_s.insert(p);
            }
        }
    }

   
    return *p_s.begin();
}