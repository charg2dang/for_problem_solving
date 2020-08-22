#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool custom_compare(int lhs, int rhs)
{
    string lhs_str = to_string(lhs);
    string rhs_str = to_string(rhs);
    
    size_t max_len = max(lhs_str.size(), rhs_str.size());
    size_t min_len = min(lhs_str.size(), rhs_str.size());

    int n;
    for (n = 0; n < min_len; ++n)
    {
        if (lhs_str[n] > rhs_str[n])
        {
            return true;
        }
        else if (lhs_str[n] < rhs_str[n])
        {
            return false;
        }
    }
    
    n -= 1;

    if (lhs_str.size() == max_len) // 왼쪽이 max인경우
    {
        for (int l = n + 1; l < max_len; ++l)
        {
            if (lhs_str[l] > rhs_str[n])
            {
                return true;
            }
            else if (lhs_str[l] < rhs_str[n])
            {
                return false;
            }
        }
    }
    else
    {
        for (int l = n + 1; l < max_len; ++l)
        {
            if (lhs_str[n] > rhs_str[l])
            {
                return true;
            }
            else if (lhs_str[n] < rhs_str[l])
            {
                return false;
            }
        }
    }

  /*  int l_offset{};
    int r_offset{};

    int& offset = lhs_str.size() < rhs_str.size() ? l_offset : r_offset;

    for (int n{}; n < max_len; ++n)
    {
        if (n >= min_len)
        {
            offset -= 1;
        }

        int l { n + l_offset };
        int r { n + r_offset };

        if (lhs_str[l] > rhs_str[r])
        {
            return true;
        }
        else if (lhs_str[l] < rhs_str[r])
        {
            return false;
        }
    }*/

}


bool compare(int l, int r)
{
    string case_1 = to_string(l) + to_string(r);
    string case_2 = to_string(r) + to_string(l);

    return case_1 > case_2;
}

string solution(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end(), compare);
    
    string answer = "";
    
    for (int n : numbers)
    {
        answer += to_string(n);
    }

    if (answer[0] == '0')
    {
        answer = "0";
    }

    return answer;
}


void main()
{
    cout << solution({ 30, 3, 34, 5, 9 }) << endl;
    cout << solution({ 6, 10, 2 }) << endl;
    cout << solution({ 101, 10 }) << endl;
    cout << solution({ 10, 101 }) << endl;
    cout << solution({ 40, 403 }) << endl;
    cout << solution({ 40, 404 }) << endl;
    cout << solution({ 40, 405 }) << endl;
    cout << solution({ 0, 0, 0, 0, 0} ) << endl;
}