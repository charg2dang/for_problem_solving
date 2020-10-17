#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool graph[26][26];
bool visits_bfs[26][26];

int max_node{};

constexpr int ys[4]{ -1, 0, 1, 0 };
constexpr int xs[4]{ 0 , 1, 0, -1};

int do_bfs(int start_y, int start_x, int max)
{
	if ( 1 > start_y && 1 > start_x)
	{
		return -1;
	}

	if (visits_bfs[start_y][start_x] == true) // 이미 방문.
	{
		return -1;
	}
	else
	{
		visits_bfs[start_y][start_x] = true;
	}

	if (graph[start_y][start_x] == false)
	{
		return -1;
	}

	queue<pair<int, int>> q;
	q.emplace(start_y, start_x);
	int visit_count{1};

	while (q.empty() == false)
	{
		int s_y = q.front().first;
		int s_x = q.front().second;

		q.pop();

		for (int n{0}; n < 4; ++n)
		{
			int y = s_y + ys[n];
			int x = s_x + xs[n];

			if ( 1 > y || y > max )
			{
				continue;
			}

			if (1 > x || x > 26)
			{
				continue;
			}

			if (visits_bfs[y][x] == true)
			{
				continue;
			}

			if (graph[y][x] == false) // 연결
			{
				continue;
			}

			q.emplace(y, x);
			visits_bfs[y][x] = true;
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
	cin >> M;

	for (int n{1}; n <= M; ++n)
	{
		string s;
		cin >> s;

		int x{1};
		for (char c : s)
		{
			graph[n][x] = c - '0';
			x += 1;
		}
	}

	vector<int> complex_arr;
	for (int y{1}; y <= M; ++y)
	{
		for (int x{1}; x <= M; ++x)
		{
			int ret = do_bfs(y, x, M);
			if (ret >= 1)
			{
				complex_arr.push_back(ret);
			}
		}
	}

	sort(complex_arr.begin(), complex_arr.end());
	cout << complex_arr.size() << "\n";

	for (int n : complex_arr)
	{
		cout << n << "\n";
	}

	return 0;
}

/*

5
10000
00000
00000
00001
00001
*/
