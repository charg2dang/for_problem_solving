#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> ns(N, vector<int>(M, 0));

	for (int y{}; y < N;++y)
	{
		for (int x{}; x < M; ++x)
		{
			cin >> ns[y][x];
		}
	}

	int m{0};
	for (int n{}; n < N; ++n)
	{
		int m_e = *min_element(ns[n].begin(), ns[n].end());
		m = max(m_e, m);
	}

	cout << m;

	return 0;
}
