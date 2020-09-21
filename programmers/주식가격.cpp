
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    stack<pair<int, int>> stack;
    vector<int> answer(prices.size(), 0); // 시간 기록용.

    // 1번차.
    int timer { -1 };
    for (int price : prices)
    {
        timer += 1;

        while(stack.empty() == false && stack.top().first > price) // 스택이 비지 않고 가격이 떨어진 경우.
        {
            int delta_time = timer - stack.top().second; // 떨어지지 않은 시간 구하기.
            answer[stack.top().second] = delta_time;
            stack.pop();
        }

        stack.emplace( make_pair(price, timer) );
    }


    while( stack.empty() == false )
    {
        int delta_time = timer - stack.top().second; // 떨어지지 않은 시간 구하기.
        answer[stack.top().second] = delta_time;
        stack.pop();
    }
        
    return move(answer);
}

#include <iostream>

void main()
{
    auto ret = solution({1, 2, 3, 2, 3});
    for (int n : ret)
    {
        cout << n << endl;
    }

    cout << "\n\n\n\n";
}