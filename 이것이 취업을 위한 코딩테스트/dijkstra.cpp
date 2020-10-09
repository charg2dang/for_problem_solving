#include <vector>
#include <iostream>

using namespace std;

constexpr int inf = 1e9;

int node_num, edge_num; // 노드와 간선의 수.
int start_node; // 시작 노드
vector<pair<int, int>> graph[100'001]; // 각 노드에 연결된 노드에 대한 정보 배열
bool visited[100'001]{}; // 노드를 방문한적잇는지
int distance[100'001]{};    // 최단 거리 테이블

int get_smallest_node()
{
    int min_value = inf;
    int index = 0; // 가장 최단 거리가 짧은 노드(인덱스)
    for (int n = 1; n <= node_num; ++n)
    {
        if (::distance[n] < min_value && !visited[n])
        {
            min_value = ::distance[n];
            index = n;
        }
    }
    return index;
}

void dijkstra(int start_node)
{
    // 시작 노드에 대한 초기화
    ::distance[start_node] = 0;
    visited[start_node] = true;

    // 주변 노드 거리 비용 입력
    for (int n{}; n < graph[start_node].size(); ++n)
    {
        ::distance[graph[start_node][n].first] = graph[start_node][n].second; // 시작 위치 주변의 노드들의 비용 입력.
    }

    // 시작 노드를 제외한 n - 1개의 노드에 대해 반복
    for (int n{}; n < node_num - 1; ++n)
    {
        // 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
        int now = get_smallest_node(); 
        visited[now] = true;

        // 현재 노드와 연결된 다른 노드를 확인
        for (int m{}; m < graph[now].size(); ++m)
        {
            int cost = ::distance[now] + graph[now][m].second;
            // 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < ::distance[graph[now][m].first])
            {
                ::distance[graph[now][m].first] = cost;
            }
        }
    }
}

int solution()
{
    // 노드와 간선의 수 입력
    cin >> node_num >> edge_num;

    // 시작번호 입력.
    cin >> start_node;
    
    // 최단 거리 테이블 초기화
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
