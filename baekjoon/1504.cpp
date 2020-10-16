#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int k_inf = 10e6;

vector<pair<long long, long long>> graph[801];
int d[801];

void dijkstra(int start)
{
	priority_queue<pair<long long, long long>> pq;

	pq.push({ 0, start }); // 시작 지점까지의 비용 0
	d[start] = 0;

	while (pq.empty() == false)
	{
		long long distance = -pq.top().first;
		long long current_node = pq.top().second;
		pq.pop();


		if (d[current_node] < distance)
		{
			continue;
		}

		for (int n{}; n < graph[current_node].size(); ++n) // 연결된 노드들 순회.
		{
			long long cost = distance + graph[current_node][n].second;
			if (cost < d[graph[current_node][n].first])
			{
				d[graph[current_node][n].first] = cost;
				pq.push(make_pair(-cost, graph[current_node][n].first));
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	long long one_to_a{}, a_to_b{}, b_to_dest{};
	long long one_to_b{}, b_to_a{}, a_to_dest{};

	long long  node_num{}, edge_num{}; // , start_node{ 1 };
	cin >> node_num >> edge_num;

	// 행렬로 들어옴.
	for (int n{}; n < edge_num; ++n)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	long long a, b;
	cin >> a >> b;

	// 최단 거리 테이블을 모두 무한으로 초기화
	fill(d, d + node_num + 1, k_inf);

	dijkstra(1);
	if (d[a] != k_inf)
	{
		one_to_a = d[a];
	}
	else
	{
		cout << -1;
		return 0;
	}

	if (d[b] != k_inf)
	{
		one_to_b = d[b];
	}
	else
	{
		cout << -1;
		return 0;
	}


	fill(d, d + node_num + 1, k_inf);
	dijkstra(a);

	if (d[b] != k_inf)
	{
		a_to_b = d[b];
	}
	else
	{
		cout << -1;
		return 0;
	}

	if (d[node_num] != k_inf)
	{
		a_to_dest = d[node_num];
	}
	else
	{
		cout << -1;
		return 0;
	}

	fill(d, d + node_num + 1, k_inf);
	dijkstra(b);

	if (d[a] != k_inf)
	{
		b_to_a = d[a];
	}
	else
	{
		cout << -1;
		return 0;
	}

	if (d[node_num] != k_inf)
	{
		b_to_dest = d[node_num];
	}
	else
	{
		cout << -1;
		return 0;
	}

	cout << min(one_to_a + a_to_b + b_to_dest, one_to_b + b_to_a + a_to_dest);

	return 0;
}

/*
4 5
1 2 3
1 3 1
1 4 1
2 3 3
3 4 4
2 3

output 7

4 5
1 2 3
1 3 1
1 4 1
2 3 3
3 4 4
2 3

output 8
*/
