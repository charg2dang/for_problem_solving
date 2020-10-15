#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int N;
    cin >> N;

    size_t sequences[2][10]{};
    for (int n{1}; n < 10; ++n)
    {
        sequences[0][n] = 1;
    }

    int cur{};
    int prev{};
    for (int n{ 1 }; n < N; ++n)
    {
        cur = n % 2;
        prev = (n - 1) % 2;

        memset(sequences[cur], 0, sizeof(sequences[cur]));

        for (int m{}; m < 10; ++m)
        {
            if (m == 0)
            {
                sequences[cur][1] += sequences[prev][0];
                sequences[cur][1] %= 1'000'000'000;
            }
            else if (m == 9)
            {
                sequences[cur][8] += sequences[prev][9];
                sequences[cur][8] %= 1'000'000'000;
            }
            else
            {
                sequences[cur][m + 1] += sequences[prev][m];
                sequences[cur][m + 1] %= 1'000'000'000;
                sequences[cur][m - 1] += sequences[prev][m];
                sequences[cur][m - 1] %= 1'000'000'000;
            }
        }
    }

    size_t total{};
    for (size_t arr : sequences[cur])
    {
        total += arr;
        total %= 1'000'000'000;
    }

    cout << total;

    return 0;
}
/*
1 9  ( 1 2 3 4 5 6 7 8 9 ) 0시작 x
2 17 ( 10 12 21 23 32 34 43 
       45 54 56 65 67 76 78 87 89 98 )
3    ( 101 121 123 210 212 232 234 321 323 343
       345 432 434 454 456 543 545 565 567 
        876 878 898 
        987 989
    2배식 증가에 마지막 자릿수가 0또는 9면 불가.

직접 계산하니간 시간이 너무 오래걸려서 마지막 자리를 배열의 인덱스로 


arr[1][0] = 1( 10 )
arr[1][1] = 1( 21 )
arr[1][2] = 2( 12 32 )
arr[1][3] = 2( 23 43 )
    .
    .
    .
arr[1][9] = 1( 89 )

원래는 arr[1][3]은 arr[2][2], arr[2][4] 양옆에 영향을 주지만
마지막 숫자인 arr[1][0]은 arr[2][1]에 영향을주고. arr[1][9]는 arr[2][8]에 밖에 영향을 못준다.
*/
