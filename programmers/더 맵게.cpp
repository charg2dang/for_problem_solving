#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int counter     { 0 };
    bool completed  { false };

    while(pq.size() > 1 && pq.top() < K)
    {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        int new_scoville = first + (second * 2);
        pq.push(new_scoville);
        
        if (new_scoville >= K)
        {
            completed = true;
        }

        counter += 1;
    }

    if (completed == false)
    {
        counter = -1;
    }

    return counter;
}

#include <iostream>

void main()
{
    cout << solution({0, 0, 1}, 5) << endl;
}