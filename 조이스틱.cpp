#include <string>
#include <vector>

using namespace std;

int solution(string name)
{
    string compare_name(name.size(), 'A');
    
    int answer{};
    int cursor{};

    while (compare_name != name)
    {
        // 문자 A로 바꾸기.  
        answer += min(name[cursor] - 'A', 'Z' - name[cursor] + 1);
        name[cursor] = 'A';

        // 문자열 위치 찾기. 
        for (int step{}; step <= name.size() / 2; step++)
        {
            int r = cursor + step;
            int l = cursor - step;

            if (r >= name.size())
            {
                r -= name.size();
            }

            if (l < 0)
            {
                l += name.size();
            }

            if (name[r] != 'A')
            {
                answer += step;
                cursor = r;
                break;
            }
            else if ( name[l] != 'A' )
            {
                answer += step;
                cursor = l;
                break;
            }
        }
    }

    return answer;
}

#include <iostream>
#include <cmath>

void main()
{
    cout << solution("JAZ") << endl;
    cout << solution("JAN") << endl;
    cout << solution("JEROEN") << endl;
}