#include <iostream>
#include <vector>

using namespace std;

constexpr size_t k_inf = 1e9;

int main()
{
	// 노드의 개수 및 간선의 개수를 입력받기
	int N, M;
	cin >> N >> M;

	// 2차원 리스트(그래프 표현)를 만들고, 모든 값을 무한으로 초기화.
	vector<vector<int>> graph(N + 1, vector<int>(M + 1, k_inf));

	// 자기 자신에게 자기 자신으로 가는 비용은 0으로 초기화.
	// 각 간선에 대한 정보를 입력받아, 그 값으로 초기화
	for (int y{ 1 }; y <= N; ++y)
	{
		for (int x{ 1 }; x <= N; ++x)
		{
			if (y == x)
			{
				graph[y][x] = 0;
			}
		}
	}

	// 각 간선에 대한 저보를 입력받아 그 값으로 초기화.
	for (int a{ }; a < M; ++a)
	{
		int y, x;
		cin >> y >> x;
		graph[y][x] = 1; // cost는 간선간 이동 비용 
		graph[x][y] = 1; // cost는 간선간 이동 비용 
	}

	// 최종 목적지x와 경유지k 입력.
	int x, k;
	cin >> x >> k;

	// 점화식에따라 플로이드 워셜 알고리즘을 수행.
	for (int i{ 1 }; i <= N; ++i)
	{
		for (int y{ 1 }; y <= N; ++y)
		{
			for (int x{ 1 }; x <= N; ++x)
			{
				graph[y][x] = min(graph[y][x], graph[y][i] + graph[i][x]);
			}
		}
	}

	int distance = graph[1][k] + graph[k][x];

	if (distance >= k_inf)
	{
		cout << "-1";
	}
	else
	{
		cout << distance << endl;
	}


	return 0;
}

/*
5 7
1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 5
*/
