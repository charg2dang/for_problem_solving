#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(const pair<string, int>& l, const pair<string, int>& r)
    {
        return l.second < r.second;
    };
};

struct sort_cmp
{
    bool operator()(const pair<int, int>& l, const pair<int, int>& r)
    {
        return l.first < r.first;
    };
};


vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    size_t num = genres.size();

    multimap<string, pair<int, int>>        m;
    priority_queue < pair<string, int>, vector<pair<string, int>>, cmp > pq;

    for (int n{}; n < num; ++n)
    {
        m.emplace(genres[n], make_pair(plays[n], n));
    }



    for (auto it = m.begin(), end = m.end(); it != end; it = m.upper_bound(it->first))
    {
        int sum{};
        const auto& ret = m.equal_range(it->first);
        for (auto it = ret.first; it != ret.second; ++it)
        {
            sum += it->second.first;
        }

        pq.emplace(make_pair(it->first, sum));

    }


    while (pq.empty() == false)
    {
        const auto& ret = m.equal_range(pq.top().first);


        priority_queue<pair<int, int>, vector<pair<int, int>>, sort_cmp> sort_pq;
        for (auto start = ret.first, end = ret.second; start != end; start++)
        {
            sort_pq.emplace(make_pair(start->second.first, start->second.second));
        }

        int n{};
        while (n < 2 && sort_pq.empty() == false)
        {
            answer.push_back((int)sort_pq.top().second);

            sort_pq.pop();

            n += 1;
        }


        pq.pop();
    }

    return move(answer);
}

#include <iostream>

void main()
{
    auto ret = solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });
    for (const auto& r : ret)
    {
        cout << r << ", ";
    }
    cout << "\n\n\n\n";

    ret = solution({ "classic", "pop", "classic", "classic", "pop", "jpop" }, { 500, 600, 500, 500, 2500, 3000 });
    for (const auto& r : ret)
    {
        cout << r << ", ";
    }

    cout << "\n\n\n\n";
}