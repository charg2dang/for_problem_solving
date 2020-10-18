#include <iostream>
#include <vector>
#include <string>

using namespace std;

string pos[65];

int color_counter[2];

int divide_and_conquer(int sy, int sx, int offset, string& bw)
{
	if (offset <= 1)
	{
		bw = to_string(pos[sy][sx] - '0');

		return 0;
	}

	string bws[4]{};
	int half_offset = offset / 2;

	int ret2 = divide_and_conquer(sy, sx, half_offset, bws[1]);
	int ret1 = divide_and_conquer(sy, sx + half_offset, half_offset, bws[0]);
	int ret3 = divide_and_conquer(sy + half_offset, sx, half_offset, bws[2]);
	int ret4 = divide_and_conquer(sy + half_offset, sx + half_offset, half_offset, bws[3]);

	if (ret1 + ret2 + ret3 + ret4 == 0) // 안 노나진 경우.
	{
		if (bws[0] == bws[1] && bws[1] == bws[2] && bws[2] == bws[3])
		{
			bw = bws[0];
			return 0;
		}
		else
		{
			bw = "(" + bws[1] + bws[0] + bws[2] + bws[3] + ")";

			return 1;
		}
	}
	else // 노나진 경우.
	{
		bw = "(" + bws[1] + bws[0] + bws[2] + bws[3] + ")";

		return 1;
	}
}


int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int N;
	cin >> N;

	for (int y{}; y < N; ++y)
	{
		string i;
		cin >> i;
		pos[y] = i;
	}

	string output;
	divide_and_conquer(0, 0, N, output);

	cout << output << "\n";

	return 0;
}

