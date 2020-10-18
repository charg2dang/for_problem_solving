#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string output_in_repeated_permutation;
vector<int> elements_in_repeated_permutation = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
vector<int> differences;
int target_ch_num;
int max_digit = 6;
int min_diff_in_crp{1000000};
int min_ch_num_in_crp{1000000};

void init_crp(int max_digit_v)
{
	output_in_repeated_permutation.clear();
	differences.clear();
	min_diff_in_crp =  1000000;
	min_ch_num_in_crp = 1000000;
	max_digit = max_digit_v;
}

void calc_repeated_permutation(int cur_digit)
{
	if (cur_digit == max_digit)
	{
		int ret1 = stoi(output_in_repeated_permutation);
		int ret2 = abs(ret1 - target_ch_num);

		if (min_diff_in_crp > ret2)
		{
			min_diff_in_crp = ret2;
			min_ch_num_in_crp = output_in_repeated_permutation.size();
			differences.push_back(ret2);
		}

		return;
	}

	size_t element_size = elements_in_repeated_permutation.size();
	for (int i = 0; i < element_size; ++i)
	{
		output_in_repeated_permutation.push_back(elements_in_repeated_permutation[i] + '0');
		calc_repeated_permutation(cur_digit + 1);
		output_in_repeated_permutation.pop_back();
	}
}


int main()
{
	std::cin.tie(NULL);
	std::cin.sync_with_stdio(false);

	bool broken_button[10]{};
	string target_channel{};
	::cin >> target_channel;
	target_ch_num = stoi(target_channel);

	int N;
	::cin >> N;

	for (int y{}; y < N; ++y)
	{
		int i;
		::cin >> i;
		broken_button[i] = true;
	}

	// 0~9 10개 다 안되면 그냥 리턴. // 0빼고 다 고장.
	if (N == 10)
	{
		::cout << abs(100 - target_ch_num);
		return 0;
	}

	// 유효한 버튼 필터 
	vector<int> valid_buttons;
	for (int n{}; n < 10; ++n)
	{
		if (broken_button[n] == false)
		{
			valid_buttons.push_back(n);
		}
	}
	
	// 중복 수열 찾기 전 초기화
	elements_in_repeated_permutation = valid_buttons;

	init_crp( (target_channel.size() - 1) == 0 ? 1 : (target_channel.size() - 1)); // -1 자리 수열중 최소 차이 값
	calc_repeated_permutation(0);
	int subed_min_e = *min_element(differences.begin(), differences.end());
	int subed_click_cnt = subed_min_e + min_ch_num_in_crp;


	init_crp(target_channel.size()); 	// 같은 자리 수열중 최소 차이 값
	calc_repeated_permutation(0);
	int default_min_e = *min_element(differences.begin(), differences.end());
	int click_count = default_min_e + min_ch_num_in_crp;


	init_crp(target_channel.size() + 1); // +1 자리 수열중 최소 차이 값
	calc_repeated_permutation(0);
	int added_min_e = *min_element(differences.begin(), differences.end());
	int added_click_cnt = added_min_e + min_ch_num_in_crp;


	int diff_from_100 = abs(target_ch_num - 100);

	if ((N == 9 && broken_button[0] == false) && click_count > abs(100 - target_ch_num))
	{
		cout << abs(100 - target_ch_num);

		return 0;
	}
	else
	{
		vector<int> results;
		results.push_back(click_count);
		results.push_back(subed_click_cnt);
		results.push_back(added_click_cnt);
		results.push_back(diff_from_100);

		cout << *min_element(results.begin(), results.end());

		return 0;
	}

	return 0;
}
