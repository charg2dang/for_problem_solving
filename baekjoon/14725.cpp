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
			node_t* next = cur->nexts[c - 'A'];

			if (next != nullptr)
			{
				cur = next;
			}
			else
			{
				node_t* new_node = new node_t();
				new_node->c = c;

				cur->nexts[c - 'A'] = new_node;

				cur = cur->nexts[c - 'A'];
			}
		}

		cur->end = true;
	}

	bool contain(const string& word)
	{
		node_t* cur = root;

		for (char c : word)
		{
			node_t* next = cur->nexts[c - 'A'];
			if (next != nullptr)
			{
				cur = next;
			}
			else
			{
				return false;
			}
		}

		return cur->end;
	}

	void print_using_preorder()
	{
		node_t* cur = root;

		int end_count{};
		string str{};

		for (int n{}; n < 26; ++n)
		{
			if (cur->nexts[n] != nullptr)
			{
				do_travle(cur->nexts[n], end_count, str);
			}
		}
	}

	void do_travle(node_t* cur, int& end_count, string& str)
	{
		str.push_back(cur->c);

		// 출력하고
		if (cur->end == true)
		{
			if (end_count > 0)
			{
				string t;
				for (int n{}; n < end_count * 2; ++n)
				{
					t.push_back('-');
				}

				cout << t << str << "\n";
			}
			else
			{
				cout << str << "\n";

			}

			str.clear();
			end_count += 1;
		}


		for (int n{}; n < 26; ++n)
		{
			if (cur->nexts[n] != nullptr)
			{
				do_travle(cur->nexts[n], end_count, str);
			}
		}

		if (cur->end == true)
		{
			end_count -= 1;
		}
	}


private:
	node_t* root;
};



int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	long long  case_cnt;
	cin >> case_cnt;

	trie t;

	string total;
	for (int n{ 0 }; n < case_cnt; ++n)
	{
		int i;
		cin >> i;

		total.clear();

		for (int m{}; m < i; ++m)
		{
			string temp;
			cin >> temp;
			total += temp;
			t.push(total);
		}
	}

	t.print_using_preorder();

	
	return 0;
}
