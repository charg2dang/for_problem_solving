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

	vector<int> ns;
	for (int n{}; n < N; ++n)
	{
		int i;
		cin >> i;
		ns.push_back(i);
	}

	sort(ns.begin(), ns.end(), less<int>());

	size_t ns_size{ns.size()};
	int total = ns[0];
	int prev = total;
	for (int n{1}; n < ns_size; ++n)
	{
		total = ns[n] + prev + total;
		prev += ns[n];
	}

	cout << total;

	return 0;
}
