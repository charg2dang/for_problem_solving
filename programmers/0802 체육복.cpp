#include <vector>

using namespace std;


// �ʹ� ��ȿ�������� ¥�� �ٸ� ����� �� ����.
// �ٽ� ����.
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
        if (students[a] == 0) // ���� ���
        {
            if (students[a - 1] == 2) // �����԰� ���е� �ִ� ���.
            {                           // �볪�ֱ�
                students[a - 1] = 1;
                students[a] = 1;
                answer += 1;
            }
            else if (students[a + 1] == 2) // �����԰� ���е� �ִ� ���.
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

// ���� ���.
// �ʹ� ��ȿ�������� § �κ��� ����.
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

