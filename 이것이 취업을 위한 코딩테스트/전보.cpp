#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int inf = int(1e9);
int node_num, edge_num; // 노드와 간선의 수.
int start_node; // 시작 노드
vector<pair<int, int>> graph[100'001]; // 각 노드에 연결된 노드에 대한 정보 배열   first 다른 노드, 비용
int distances[100'001]{};    // 최단 거리 테이블

void dijkstra(int start_node)
{
    // 시작 노드에 대한 초기화
    priority_queue<pair<int, int>> pq; // 비용 평가를 위해  < 비용, 다른 노드> 순으로 삽입. 기본 max heap
    pq.emplace(make_pair(0, start_node));
    distances[start_node] = 0;

    while (pq.empty() == false) // 큐가 비어 있지 않다면?
    {
        // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기.
        int dist = -pq.top().first; // 현재 노드까지의 비용
        int current_node = pq.top().second; // 현재 노드.

        pq.pop();

        // 현재 노드가 이미 처리된적 있는 노드라면 무시.
        if (distances[current_node] < dist )
        {
            continue;
        }

		// 현재 노드와 연결된 다른 인접한 노드들을 확인
        for ( auto& it : graph[current_node])
        {
            int adjacent_node = it.first;
            int cost = dist + it.second; // 비용

            // 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < distances[adjacent_node])
            {
                distances[adjacent_node] = cost; // 짧은거로 업데이트.
                pq.emplace(make_pair(-cost, adjacent_node)); // 음수로 해야 max힙을 min힙처럼 사용 가능 쌉가능.
            }
        }
    }
}

int main()
{
    // 도시(노드)와 통로(간선)의 수 입력
    cin >> node_num >> edge_num;

    // 시작 도시(노드) 번호 입력.
    cin >> start_node;

    //// 최단 거리 테이블 초기화
    fill_n(::distances, 100'001, inf);

    // 간선 정보 입력
    for (int n{}; n < edge_num; ++n)
    {
        int start, dest, cost;
        cin >> start >> dest >> cost; // a 시작 지점, b 도착 지점. c 비용
        graph[start].push_back({ dest, cost }); // a -> b  비용은 c
    }

    dijkstra(start_node);

    // 도달 가능한 노드의 개수
    int count{};

    // 도달 할 수 있는 노드 중에서, 가장 멀리 있는 노드와의 최단 거리.
    int max_distance{};
    for (int n{}; n <= node_num; ++n )
    {
        if ( distances[n] != inf )
        {
            count += 1;
            max_distance = max(max_distance, distances[n]);
        }
    }

    cout << count - 1 << " " << max_distance << endl;

	return 0;
}
