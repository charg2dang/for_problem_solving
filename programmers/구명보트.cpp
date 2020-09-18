#include <string>
#include <vector>
#include <deque>
#include <algorithm>

#include <iostream>
using namespace std;

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit)
{
    sort(begin(people), end(people));
    int answer{};

    int front_curosr{};
    for (int back_curosr = people.size() - 1; back_curosr >= front_curosr; --back_curosr)
    {
        if (people[back_curosr] + people[front_curosr] <= limit)
        {
            front_curosr += 1;
        }

        answer += 1;
    }


    return answer;
}




void main()
{
    cout << solution({ 70, 50, 80, 50 }, 100) << endl;
    cout << solution({ 70, 80, 50 }, 100) << endl;
    cout << solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10) << endl;
}