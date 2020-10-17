#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<long long, long long>> ts;
	ts.reserve(N);
	for (int n{}; n < N; ++n)
	{
		long long s, e;
		cin >> s >> e;
		ts.emplace_back(s, e);
	}
	
	sort(ts.begin(), ts.end());

	size_t ts_size{ ts.size()};

	long long cur_s_t{ ts[0].first };
	long long cur_end_t{ ts[0].second };
	int p_count{1};

	for (size_t n{1}; n < ts_size; ++n)
	{
		long long start_t	= ts[n].first;
		long long end_t		= ts[n].second;

		if (cur_end_t > end_t)
		{
			cur_s_t = start_t;
			cur_end_t = end_t;
		}
		else if (cur_end_t <= start_t)
		{
			p_count += 1;
			cur_s_t = start_t;
			cur_end_t = end_t;
		}
	}

	cout << p_count << "\n";

	return 0;
}
