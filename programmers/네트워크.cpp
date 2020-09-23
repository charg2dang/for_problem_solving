//#include <Windows.h>
//#include <iostream>
//#include <thread>
//
//using namespace std;
//
//SRWLOCK lock;
//
//void main()
//{
//	cout << __FILE__ << endl;
//
//	SYSTEM_INFO systemInfo;
//	GetSystemInfo(&systemInfo);
//
//	systemInfo.dwProcessorType;
//
//}



#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    vector<bool> visits(n, false);
    stack<short> s;
    int answer{};

    for (int me{}; me < n; ++me)
    {
        if (visits[me] == false)
        {
            s.push(me);
            answer += 1;

            while (s.empty() == false)
            {
                short top_value = s.top();
                s.pop();

                visits[top_value] = true;

                for (int other{}; other < n; ++other)
                {
                    if (other == top_value)
                    {
                        continue;
                    }

                    if (visits[other] == false && computers[top_value][other] == 1)
                    {
                        s.push(other);
                    }
                }
            }
        }
    }

    return answer;
}

#include <iostream>

void main()
{
    cout << solution(3, { {1, 1, 0},{1, 1, 0},{0, 0, 1} });
    cout << "\n\n\n\n";
    cout << solution(3, { {1, 1, 0},{1, 1, 1},{0, 1, 1} });
    cout << "\n\n\n\n";
}