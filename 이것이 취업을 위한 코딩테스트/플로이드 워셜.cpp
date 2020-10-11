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
	for (int y{1}; y <= N; ++ y)
	{
		for (int x{1}; x <= N; ++x)
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
		int y, x, cost; 
		cin >> y >> x >> cost;
		graph[y][x] = cost; // cost는 간선간 이동 비용 
	}

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


	// 수행된 결곽를 출력.
	for (int y{ 1 }; y <= N; ++y)
	{
		for (int x{ 1 }; x <= N; ++x)
		{
			// 도달할 수 없는 경우, 무한(k_inf)이라고 출력.
			if (graph[y][x] == k_inf)
			{
				cout << "infinity" << endl;

			}
			else // 도달 가능한 경우 거릴르 출력			
			{
				cout << graph[y][x] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}

/*
4
7
1 2 4
1 4 6
2 1 3
2 3 7
3 1 5
3 4 4
4 3 2 
*/
