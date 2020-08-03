#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    deque<short> t_p;
    deque<short>  t_is;

    int current_total_weight{};
    int truck_index{};
    int elapsed_time{ 1 };

    for (;; elapsed_time += 1)
    {
        if (truck_weights.size() == truck_index && t_p.empty() == true)
        {
            break;
        }

        if (truck_weights.size() > truck_index && current_total_weight + truck_weights[truck_index] <= weight)
        {
            t_p.push_back(bridge_length);
            t_is.push_back(truck_index);

            current_total_weight += truck_weights[truck_index];
            truck_index += 1;
        }

        for (short& t : t_p)
        {
            t -= 1;
        }

        if (t_p.empty() == false && t_p[0] == 0)
        {
            current_total_weight -= truck_weights[t_is[0]];

            t_is.pop_front();
            t_p.pop_front();
        }
    }

    return elapsed_time;
}

