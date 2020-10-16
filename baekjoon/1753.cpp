// 시간 초과 문제로 다익스트라 알고리즘이 문제인가 했지만 cin 입력 부분이 문제였다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int k_inf = 10e6;
int node_num{}, edge_num{}, start_node{};
vector<pair<int, int>> graph[20'001];
int d[20'001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;

    pq.push({ 0, start }); // 시작 지점까지의 비용 0
    d[start] = 0;

    while (pq.empty() == false)
    {
        int distance        = -pq.top().first;
        int current_node    = pq.top().second;
        pq.pop();


        if (d[current_node] < distance)
        {
            continue;
        }

        for (int n{}; n < graph[current_node].size(); ++n) // 연결된 노드들 순회.
        {
            int cost = distance + graph[current_node][n].second;
            if (cost < d[graph[current_node][n].first])
            {
                d[graph[current_node][n].first] = cost;
                pq.push(make_pair(-cost, graph[current_node][n].first) );
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> node_num >> edge_num >> start_node;

    // 행렬로 들어옴.
    for (int n{}; n < edge_num; ++n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    // 최단 거리 테이블을 모두 무한으로 초기화
    fill(d, d + 20001, k_inf);

    dijkstra(start_node);

    for (int n{1}; n <= node_num; ++n)
    {
        if (d[n] == k_inf)
        {
            cout << "INF\n";
        }
        else
        {
            cout << d[n] << "\n";
        }
    }
     
    
    return 0;
}
