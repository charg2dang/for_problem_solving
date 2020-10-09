#include <vector>
#include <iostream>
#include <queue>

using namespace std;

constexpr int inf = int(1e9);

int node_num, edge_num; // 노드와 간선의 수.
int start_node; // 시작 노드
vector<pair<int, int>> graph[100'001]; // 각 노드에 연결된 노드에 대한 정보 배열
int distance[100'001]{};    // 최단 거리 테이블

void dijkstra(int start_node)
{
    // 시작 노드에 대한 초기화
    priority_queue<pair<int, int>> pq; // 비용 평가를 위해  < 비용, 다른 노드> 순으로 삽입.
    pq.emplace(make_pair(0, start_node));
    ::distance[start_node] = 0;

    while (pq.empty() == false) // 큐가 비어 있지 않다면?
    {
        // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기.
        int dist = -pq.top().first; // 현재 노드까지의 비용
        int current_node = pq.top().second; // 현재 노드.

        pq.pop();

        // 현재 노드가 이미 처리된적 있는 노드라면 무시.
        if (::distance[current_node] < dist )
        {
            continue;
        }

		// 현재 노드와 연결된 다른 인접한 노드들을 확인
		for (int n{}; n < graph[current_node].size(); ++n)
		{
			int cost = dist + graph[current_node][n].second;
			// 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
			if (cost < ::distance[graph[current_node][n].first])
			{
				::distance[graph[current_node][n].first] = cost;
                pq.emplace(make_pair(-cost, graph[current_node][n].first));
			}
		}
    }
}

int solution()
{
    // 노드와 간선의 수 입력
    cin >> node_num >> edge_num;

    // 시작 노드 번호 입력.
    cin >> start_node;
    
    //// 최단 거리 테이블 초기화
    fill_n(::distance, 100'001, inf);

    // 간선 정보 입력
    for (int n{}; n < edge_num; ++n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c}); // a -> b  비용은 c
    }

    dijkstra(start_node);

    // 모든 노드로 가기 위한 최단 거리 출력
    for (int n{1}; n <= node_num; ++n)
    {
        // 도달 할수 없는 경우, 무한 출력
        if (::distance[n] == inf)
        {
            cout << "INFINITY" << '\n';
        }
        // 도달할 수 있는 경우 거리를 출력
        else
        {
            cout << ::distance[n] << '\n';
        }
    }

    return 0;

}

int main()
{
    solution();
    return 0;
}

/*
노드수, 간선수
시작 노드
시작 끝 비용


6 11
1
1 2 2
1 3 5
1 4 1
2 3 3
2 4 2
3 2 3
3 6 5
4 3 3
4 5 1
5 3 1
5 6 2
*/
