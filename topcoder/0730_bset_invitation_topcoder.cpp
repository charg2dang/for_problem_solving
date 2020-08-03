#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int bets_invitation(vector<string> first, vector<string> second)
{
	// 공통 분모를 찾는 것.
	unordered_map<string, int> hobby_map;

	for (int n{}; n < first.size(); ++n)
	{
		hobby_map[first[n]] += 1;
		hobby_map[second[n]] += 1;
	}
	 
	int p{};
	for ( auto& it : hobby_map )
	{
		p = std::max(p, it.second);
	}

	return p;
}

