#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int M;
	cin >> M;

	vector<int> as;
	vector<int> bs;

	for (int n{}; n < M; ++n)
	{
		int i;
		cin >> i;
		as.push_back(i);
	}

	for (int n{}; n < M; ++n)
	{
		int i;
		cin >> i;
		bs.push_back(i);
	}

	sort(as.begin(), as.end(), [](int a, int b) { return a < b; });
	sort(bs.begin(), bs.end(), [](int a, int b) { return a > b; });

	long long sum{};
	for (int n{}; n < M; ++n)
	{
		sum += (as[n] * bs[n]);
	}

	cout << sum;

	return 0;
}
