
#include <string>
#include <vector>
#include <iostream>

using namespace std;




int solution(string s)
{
    int minimum_value = s.length();
    size_t s_length = s.length();
    string p_pattern = "";
    string c_pattern = "";

    for (int n{ 1 }; n < s_length; n += 1)
    {
        string str = "";
        int pattern_count{};
        int b{};
        for (; b <= s_length; b += n)
        {
            c_pattern = move(s.substr(b, n)); // ���ڿ� ����
            if (p_pattern == c_pattern)
            {
                pattern_count += 1;
            }
            else
            {
                if (pattern_count >= 1)
                {
                    str += to_string(pattern_count + 1); // �տ� ���ڶ� ���.
                }

                str += p_pattern; // �����
                pattern_count = 0;
            }

            p_pattern = move(c_pattern);
        };

        if (pattern_count >= 1)
        {
            str += to_string(pattern_count + 1);
        }

        str += p_pattern;
        p_pattern.clear();

        if (minimum_value > str.length())   // �ּ��� ���� ã�Ƽ� ����.
        {
            minimum_value = str.length();
        }
    }

    // return
    return minimum_value;
}

void main()
{
    cout << solution("aabbaccc");
    cout << "\n\n\n\n";

    cout << solution("ababcdcdababcdcd");
    cout << "\n\n\n\n";

    cout << solution("abcabcdede");
    cout << "\n\n\n\n";

    cout << solution("abcabcabcabcdededededede");
    cout << "\n\n\n\n";

    cout << solution("xababcdcdababcdcd");
    cout << "\n\n\n\n";


    cout << solution("aabbaccccccccccccccccccccccc");
    cout << "\n\n\n\n";
}