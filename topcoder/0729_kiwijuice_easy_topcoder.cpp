
#include <iostream>
#include <vector>
#include <algorithm>

constexpr size_t number = 2;
constexpr size_t test_case = 1;
constexpr int capacites[number]	{20, 20};
int bottles[number]	{ 5, 8};
constexpr int from_ids[test_case]	{0};
constexpr int to_ids[test_case]		{1};

void main()
{
	for (int a{}; a < test_case; ++a)
	{
		int from_id = from_ids[a];
		int to_id = to_ids[a];
		
		if (bottles[from_id] == 0) // 병의 남은 용량이 0이면 다음 케이스로.
		{
			continue;
		}


		int empty_space = capacites[to_id] - bottles[to_id];
		if (empty_space == 0) // 목적지 병의 용량이 꽉 차있다면 pass
		{
			continue;
		}


		/*if ( bottles[from_id] <= empty_space)
		{
			bottles[to_id] += bottles[from_id];
			bottles[from_id] = 0;
		}
		else
		{
			bottles[from_id] -= empty_space;
			bottles[to_id] = capacites[to_id];
		}*/

		int sum = bottles[to_id] + bottles[from_id];
		bottles[to_id] = std::min(sum, capacites[to_id]);
		bottles[from_id] = sum - bottles[to_id];
	}


	for (int n : bottles)
	{
		printf("%d, ", n);
	}

	printf("\n");

}