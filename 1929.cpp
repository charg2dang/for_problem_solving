#pragma once
#include <iostream>

using namespace std;

const long long MAX = 1'000'001;
bool is_not_prime_num[MAX];

long long eratosthenes()
{
	int local_max = MAX;
	long long prime_num_counter{1};
	is_not_prime_num[1] = true;

	for (int i = 2; i <= local_max; ++i)
	{
		if (is_not_prime_num[i] == false)
		{
			prime_num_counter += 1;
			for (int j = i + i; j <= local_max; j += i)
			{
				is_not_prime_num[j] = true;
			}
		}
	}

	return prime_num_counter;
}

auto main() -> int
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	long long ret = eratosthenes();

	for (int i = N; i <= M; ++i)
	{
		if (is_not_prime_num[i] == false)
		{
			cout << i << "\n";
		}
	}

	return 0;
}

