#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int count_diferences(const string& l, const string& r)
{
    int counter{};
    int length{ (int)l.length() };

    for (int n{}; n < length; ++n)
    {
        if (l[n] != r[n])
        {
            counter += 1;
        }
    }

    return counter;
}

int solution(string begin, string target, vector<string> words)
{
    size_t begin_length = begin.length();
    size_t words_size = words.size();

    vector<vector<bool>> g(words_size + 1, vector<bool>(words_size + 1, false));
    unordered_map<string, int> km;
    stack<pair<string, short>> s;

    km.reserve(words_size);

    bool has_target{};

    int n{};
    for (; n < words_size; ++n)
    {
        km.emplace(words[n], n);

        for (int m{}; m < words_size; ++m)
        {
            if (count_diferences(words[m], words[n]) < 2) // 1  다른넘 // 0 자기 자신 // 그외엔 아예 다른 넘;
            {
                g[n][m] = true;
                g[m][n] = true;
            }
        }

        if (target == words[n])
        {
            has_target = true;
        }
    }

    km.emplace(begin, n);


    if (has_target == false)
    {
        return 0;
    }

    vector<vector<bool>> visits(words_size + 1, vector<bool>(words_size + 1, false));
    unordered_set<string> in;

    //vector<bool> visits(words_size + 1, false);
    string current = begin;
    int min = words_size;
    bool complted{ false };


    for (int n{}; n < words_size; ++n)
    {
        int answer{};

        if (count_diferences(begin, words[n]) < 2)
        {
            s.emplace(make_pair(begin, n));
            in.emplace(words[n]);
            visits[km[begin]][n] = true;
            answer += 1;
        }

        // 길이 여러개면;;
        while (s.empty() == false)
        {
            int cur = s.top().second;
            string prev = s.top().first;
            size_t stack_size = s.size();
            int key = km[prev];

            current = words[cur];

            if (current == target)
            {
                if (min > answer)
                {
                    min = answer;
                }
                complted = true;
                in.erase(current);
                answer -= 1;
                s.pop();
                continue;
            }

            // 깊이 들억가기
            for (int n{ 0 }; n < words_size; ++n)
            {
                if (visits[key][n] == true)
                {
                    continue;
                }
                if (current == words[n])
                {
                    continue;
                }
                auto r = in.find(words[n]);
                if (r != in.end()) // 존재하면 다시.
                {
                    continue;
                }
                if (count_diferences(current, words[n]) < 2)
                {
                    visits[key][n] = true;
                    s.emplace(current, n);
                    in.emplace(words[n]);
                }
            }


            if (stack_size < s.size()) // 성공
            {
                answer += 1;
                continue;
            }
            else if (stack_size == s.size())
            {
                in.erase(current);
                s.pop();
                if (s.size() >= 1 && prev == s.top().first)
                {
                    answer -= 1;
                }
            }
        }
    }

    if (complted == false)
    {
        min = 0;
    }

    return min;
}


#include <iostream>

void main()
{
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });

    cout << "\n\n\n\n";

    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" });

    cout << "\n\n\n\n";

    cout << solution("hit", "cog", { "hot", "dot", "lot", "cog" });

    cout << "\n\n\n\n";

    cout << solution("hot", "lot", { "hot", "dot", "lot", "cog" });

    cout << "\n\n\n\n";
}