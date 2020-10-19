#include <iostream>
#include <string>

using namespace std;


class trie
{
	struct node_t
	{
		node_t() : c{}, end{false}, nexts{}
		{}

		char c;
		bool end;
		node_t* nexts[26];
	};

public:
	trie() : root{ new node_t() }
	{}

	void push(const string& word)
	{
		node_t* cur = root;

		for (char c : word)
		{
			node_t* next = cur->nexts[c - 'a'];

			if (next != nullptr)
			{
				cur = next;
			}
			else
			{
				node_t* new_node = new node_t();
				new_node->c = c;

				cur->nexts[c - 'a'] = new_node;

				cur = cur->nexts[c - 'a'];
			}
		}

		cur->end = true;
	}

	bool contain(const string& word)
	{
		node_t* cur = root;

		for (char c : word)
		{
			node_t* next = cur->nexts[c - 'a'];
			if (next != nullptr)
			{
				cur = next;
			}
			else
			{
				return false;
			}
		}

		return cur->end == true;
	}


private:
	node_t* root;
};



int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	long long  base_cnt, test_cnt;
	cin >> base_cnt >> test_cnt;

	trie t;

	string str;
	for (int n{ 0 }; n < base_cnt; ++n)
	{
		str.clear();

		cin >> str;

		t.push(str);
	}


	int counter{};
	for (int n{ 0 }; n < test_cnt; ++n)
	{
		str.clear();

		cin >> str;

		if (t.contain(str) == true)
		{
			counter += 1;
		}
	}

	cout << counter;
	
	return 0;
}
