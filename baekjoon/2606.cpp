#include <iostream>
#include <queue>
using namespace std;

bool graph[101][101];
bool visits_bfs[101];

int max_node{};

int do_bfs(int start_node)
{
	if (0 >= start_node)
	{
		return 0;
	}

	queue<int> q;
	q.push(start_node);
	visits_bfs[start_node] = true;
	int visit_count{0};

	while (q.empty() == false)
	{
		int f = q.front();
		q.pop();

		for (int n{1}; n <= max_node; ++n)
		{
			if (visits_bfs[n] == true)
			{
				continue;
			}

			if (graph[f][n] == false)
			{
				continue;
			}

			q.push(n);
			visits_bfs[n] = true;
			visit_count += 1;
		}
	}
	
	return visit_count;
}


int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int M;
	cin >> max_node >> M;

	for (int n{}; n < M; ++n)
	{
		int s, d;
		cin >> s >> d;
		graph[s][d] = 1;
		graph[d][s] = 1;
	}

	cout << do_bfs(1);

	return 0;
}

