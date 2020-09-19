
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;


string solution(string number, int k)
{
    string answer;
    size_t answer_length = number.size() - k;

    answer.reserve(answer_length);

    size_t position{};

    for (size_t n{ answer_length }; n > 0; --n)
    {
        auto b = begin(number) + position;
        auto e = end(number) - n + 1;

        auto max_it = max_element(b, e);

        answer += *max_it;

        *max_it = ' ';

        position += (max_it - b);
    }


    return answer;
}


#include <iostream>

void main()
{
    cout << solution("1924", 2) << endl;
    cout << solution("1231234", 3) << endl;
    cout << solution("4177252841", 4) << endl;
}