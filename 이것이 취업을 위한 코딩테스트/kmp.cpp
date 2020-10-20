#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<int> make_table(const string& pattern)
{
	size_t pattern_size = pattern.size();
	vector<int> table(pattern_size, 0);
	int m{};

	for (int n{1}; n < pattern_size; ++n)
	{
		while (m > 0 && pattern[n] != pattern[m])
		{
			m = table[m - 1];
		}

		if (pattern[n] == pattern[m])
		{
			table[n] = ++m;
		}
	}

	return move(table);
}

void kmp(const string& parent, const string& pattern)
{
	vector<int> output;
	vector<int> table = make_table(pattern);
	int parent_size = parent.size();
	int pattern_size = pattern.size();

	int m{};
	for (int n{ 0 }; n < parent_size; ++n)
	{
		while (m > 0 && parent[n] != pattern[m])
		{
			m = table[m - 1];
		}

		if (parent[n] == pattern[m])
		{
			if (m == pattern_size - 1)
			{
				output.push_back(n - pattern_size + 2);
				m = table[m];
			}
			else
			{
				m += 1;
			}
		}
	}

	cout << output.size() << "\n";

	for (int o : output)
	{
		cout << o << " ";
	}

}

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cout.tie(0);

	string parent;
	string pattern;

	getline(cin, parent);
	getline(cin, pattern);

	kmp(parent, pattern);
	
	return 0;
}
