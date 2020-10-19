#include <iostream>
#include <cmath>

using namespace std;

constexpr unsigned long long k_max{ 1'000'001 };

bool is_square_nums[k_max];
long long square_nums[k_max];


/* 
요약

에라토스테네스체에서 소수를 구하는 방식처럼.
제곱수를 이용해서 필터링 한다.

*제곱수는 1보다 큰 정수를 1회 제곱한 수

미리 제곱수 테이블 최대치를 만들고 
제곱수의 가까운 최소값을 구하고 거기서 제곱수의 배수로 훓어 나간다.

최종적으로 제곱수의 갯수를 구하고 전체 원소 갯수에서 빼서 돌려주면 된다.


*/

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	long long min, max;
	cin >> min >> max;

	long long maximum_square_num{ (long long)sqrt(max) };
	
	long long n{ 2 };
	for ( ; n <= maximum_square_num; ++n)
	{
		square_nums[n] = n * n;
	}

	long long square_n_counter{ -1 };
	long long max_idx = n;
	n -= 2;

	for (long long m = 2; m < max_idx; ++m)
	{
		long long divided_min = min;
		if ( divided_min % square_nums[m] != 0) // 최대한 min과 제곱수에 가깝게 맞춘다.
		{										// 30 / (2 * 2) != 0    결과는 7.??? 8로 맞춰주면 8 * 32 30보다 큰 min  32부터 시작.
			divided_min = ( (min / square_nums[m]) + 1) * square_nums[m];
		}

		// 범위 값으로 변경.
		for (long long d{divided_min}; d <= max; d += square_nums[m])
		{
			if (is_square_nums[d-min] == false) // 제곱수가 아니면
			{
				is_square_nums[d- min] = true;
				square_n_counter += 1; // 제곱인 수를 발견.
			}
		}
	}

	cout << max - min - square_n_counter;

	return 0;
}

