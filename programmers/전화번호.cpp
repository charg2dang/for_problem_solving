#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Trie
{
    struct TrieNode
    {
        TrieNode() : c{}, nexts{}
        {}

        char c;
        TrieNode* nexts[10];
    };

public:
    Trie() : root{ new TrieNode() }
    {
    }

    void push(const string& word)
    {
        TrieNode* cur = root;

        for (char c : word)
        {
            TrieNode* next = cur->nexts[c - '0'];

            if (next != nullptr)
            {
                cur = next;
            }
            else
            {
                TrieNode* new_node = new TrieNode();
                new_node->c = c;

                cur->nexts[c- '0'] = new_node;

                cur = cur->nexts[c - '0'];
            }
        }
    }
    
    bool contain(const string& word)
    {
        TrieNode* cur = root;

        for (char c : word)
        {
            TrieNode* next = cur->nexts[c - '0'];

            if (next != nullptr)
            {
                cur = next;
            }
            else
            {
                return false;
            }
        }

        return true;
    }


private:
    TrieNode* root;
};

bool solution(vector<string> phone_book)
{
    sort(begin(phone_book), end(phone_book), [](const string& lhs, const string& rhs)  
        {
            return lhs.size() > rhs.size();
        }
    );


    Trie trie;

    for (const auto& phone_number : phone_book)
    {
        if (trie.contain(phone_number) == true)
        {
            return false;
        }
        else
        {
            trie.push(phone_number);
        }
    }

    return true;
}

#include <iostream>
void main()
{
    cout << solution({ "119", "97674223", "1195524421" }) << endl;
    cout << solution({ "123", "456", "789"}) << endl;
    cout << solution({ "12", "123", "1235", "567", "88" } ) << endl;
}