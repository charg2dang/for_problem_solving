#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string N, M;
	cin >> N >> M;

	size_t N_size = N.size();
	size_t M_size = M.size();

	string nn;
	nn.reserve(N_size);

	size_t offset{};
	size_t find_pos{string::npos};
	for (int n{}; n < N_size; ++n)
	{
		nn.push_back(N[n]);
		size_t nn_size = nn.size();
		if (nn_size >= M_size)
		{
			offset = nn_size - M_size;
			find_pos = nn.find(M, offset);
			if (find_pos != string::npos)
			{
				size_t g = find_pos + M_size;
				for (size_t a{ find_pos }; a < g; ++a)
				{
					nn.pop_back();
				}
			}
		}
	}



	if (nn == "")
	{
		cout << "FRULA";
	}
	else
	{
		cout << nn;
	}
	
	return 0;
}
