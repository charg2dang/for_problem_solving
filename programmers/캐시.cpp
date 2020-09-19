
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_set>

using namespace std;


int solution(int cacheSize, vector<string> cities)
{
    if (cacheSize == 0)
    {
        return cities.size() * 5;
    }

    deque<string> city_dq;
    unordered_set<string> city_cache;
    city_cache.reserve(cacheSize);

    int answer{};

    string temp_city;
    for (const auto& city : cities)
    {
        temp_city = move(city);
        transform(begin(temp_city), end(temp_city), begin(temp_city), (int(*)(int))tolower);

        auto it = city_cache.find(temp_city);
        if (it != city_cache.end()) // 캐시에 있음.
        {
            city_dq.erase(find(begin(city_dq), end(city_dq), temp_city));
            city_dq.emplace_back(temp_city);

            answer += 1;
        }
        else // 캐시에 없음.
        {
            if (city_dq.size() >= cacheSize)
            {
                city_cache.erase(city_dq.front());
                city_dq.pop_front();
            }

            city_cache.emplace(temp_city);
            city_dq.emplace_back(temp_city);

            answer += 5;
        }

    }

    return answer;
}


#include <iostream>

void main()
{
    cout << solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" }) << endl;
    cout << solution(3, { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" }) << endl;

    cout << solution(2, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" }) << endl;
    cout << solution(5, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" }) << endl;
    cout << solution(2, { "Jeju", "Pangyo",  "NewYork", "newyork"}) << endl;
    cout << solution(0, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" }) << endl;



    //cout << solution(3, { "a", "b", "c", "a", "b", "a", "b", "a", "b", "d", "c"}) << endl;
}


