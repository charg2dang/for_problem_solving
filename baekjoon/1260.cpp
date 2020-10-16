#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool graph[1001][1001];
bool visits_dfs[1001];
bool visits_bfs[1001];

int max_node{};
void do_dfs(int start_node)
{
	if (0 >= start_node)
	{
		return;
	}

	stack<int> s;
	s.push(start_node);
	//visits_dfs[start_node] = true;

	while (s.empty() == false)
	{
		int t = s.top();
		s.pop();

		if (visits_dfs[t] == false)
		{
			cout << t << " ";
			visits_dfs[t] = true;
		}

		for (int n{1}; n <= max_node; ++n)
		{
			if (visits_dfs[n] == true)
			{
				continue;
			}

			if (graph[t][n] == false)
			{
				continue;
			}

			s.push(t);
			s.push(n);
			break;
		}
	}

	cout << "\n";
}

void do_bfs(int start_node)
{
	if (0 >= start_node)
	{
		return;
	}

	queue<int> q;
	q.push(start_node);
	visits_bfs[start_node] = true;

	while (q.empty() == false)
	{
		int f = q.front();
		q.pop();

		cout << f << " ";
		visits_bfs[f] = true;

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
		}
	}
	cout << "\n";
}


int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int M, V;
	cin >> max_node >> M >> V;

	for (int n{}; n < M; ++n)
	{
		int s, d;
		cin >> s >> d;
		graph[s][d] = 1;
		graph[d][s] = 1;
	}

	do_dfs(V);
	do_bfs(V);

	return 0;
}

