
#include <iostream>

using namespace std;

constexpr long long k_inf{ (long long)1e9 };
constexpr long long k_max{ 100 + 1 };

long long graph[k_max][k_max]{};

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	long long  node_cnt, edge_cnt;
	cin >> node_cnt >> edge_cnt;

	fill_n(&graph[0][0], k_max  * k_max , k_inf);

	for (int n{}; n <= node_cnt; ++n)
	{
		graph[n][n] = 0;
	}

	for (int n{ 0 }; n < edge_cnt; ++n)
	{
		int y, x, cost;
		cin >> y >> x >> cost;
		graph[y][x] = min(graph[y][x], (long long)cost);
	}

	// 플로이드 워셜 알고리즘 수행.
	for (int n{ 1 }; n <= node_cnt; ++n)
	{
		for (int a{ 1 }; a <= node_cnt; ++a)
		{
			for (int b{ 1 }; b <= node_cnt; ++b)
			{
				if (a == 1 && b== 4)
				{
					int fd = 88;
				}
				graph[a][b] = min(graph[a][b], graph[a][n] + graph[n][b]);
			}
		}
	}

	// 수행된 결과를 출력
	for (int a{ 1 }; a <= node_cnt; ++a)
	{
		for (int b{ 1 }; b <= node_cnt; ++b)
		{
			// 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
			if (graph[a][b] == k_inf)
			{
				cout << 0 << ' ';
			}
			// 도달할 수 있는 경우 거리를 출력
			else
			{
				cout << graph[a][b] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
