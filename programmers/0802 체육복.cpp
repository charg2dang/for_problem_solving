#include <vector>

using namespace std;


// 너무 비효율적으로 짜서 다른 사람의 해 참고.
// 다시 제작.
int solution(int n, vector<int> lost, vector<int> reserve)
{
    vector<char> students(30, 1);
    for (int a : lost)
    {
        students[a] -= 1;
    }

    for (int b : reserve)
    {
        students[b] += 1;
    }

    int answer{};

    for (int a{ 1 }; a <= n; ++a)
    {
        if (students[a] == 0) // 없는 경우
        {
            if (students[a - 1] == 2) // 가져왔고 여분도 있는 경우.
            {                           // 노나주기
                students[a - 1] = 1;
                students[a] = 1;
                answer += 1;
            }
            else if (students[a + 1] == 2) // 가져왔고 여분도 있는 경우.
            {
                students[a + 1] = 1;
                students[a] = 1;
                answer += 1;

            }
        }
        else
        {
            answer += 1;
        }

    }

    return answer;
}

// 기존 답안.
// 너무 비효율적으로 짠 부분이 많다.
//#include <algorithm>
//int solution(int n, vector<int> lost, vector<int> reserve)
//{
//    int answer = n - lost.size();
//    int recent_idx{};
//
//    for (int& a : lost)
//    {
//        for (int& b : reserve)
//        {
//            if (a == b)
//            {
//                a = 31;
//                b = 31;
//
//                break;
//            }
//        }
//    }
//
//    sort(lost.begin(), lost.end());
//    sort(reserve.begin(), reserve.end());
//
//    for (int n : lost)
//    {
//        for (; recent_idx <= reserve.size();)
//        {
//            if (n > 31)
//            {
//                break;
//            }
//
//            if ((abs(n - reserve[recent_idx])) <= 1)
//            {
//                answer += 1;
//                recent_idx += 1;
//                break;
//            }
//            else
//            {
//                if (n > reserve[recent_idx])
//                {
//                    recent_idx += 1;
//                    continue;
//                }
//                else
//                {
//                    break;
//                }
//            }
//        }
//    }
//
//    return answer;
//}
//

