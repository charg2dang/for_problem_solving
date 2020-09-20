#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const string nums{ "0123456789" };
const string chars{ "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ-. " };

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    answer.reserve(files.size());

    vector<vector<string>> hnts;
    hnts.reserve(files.size());

    string head;
    string number;
    string tail;

    // parsing
    for (const auto& file : files)
    {
        int head_size = file.find_first_of(nums, 0);
        int number_size = file.find_first_of(chars, head_size); // foo 010

        head = move(file.substr(0, head_size));
        if (number_size == string::npos)
        {
            number = move(file.substr(head_size, file.size() - head_size));
            tail = "";
        }
        else
        {
            number = move(file.substr(head_size, number_size - head_size));
            tail = move(file.substr(number_size, file.size() - number_size));
        }

        cout << "h:" << head << ",n:" << number << ",t:" << tail << endl;

        hnts.emplace_back(std::move(std::vector<string>{ head, number, tail }));

    }

    // sorting
    stable_sort(begin(hnts), end(hnts),
                [](const auto& lhs, const auto& rhs)
                {
                    string l_cpy = lhs[0];
                    transform(begin(l_cpy), end(l_cpy), begin(l_cpy), (int(*)(int))toupper);

                    string r_cpy = rhs[0];
                    transform(begin(r_cpy), end(r_cpy), begin(r_cpy), (int(*)(int))toupper);

                    if (l_cpy == r_cpy) // 같은 문자열이면 number
                    {
                        return (atoi(lhs[1].c_str()) < atoi(rhs[1].c_str()));
                    }

                    return l_cpy < r_cpy;

                });

    for (const auto& hnt : hnts)
    {
        answer.emplace_back(string(hnt[0] + hnt[1] + hnt[2]));
    }

    return std::move(answer);
}


void main()
{
    auto ret = solution({ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });
    for (const auto& r : ret)
    {
        cout << r << endl;
    }

    cout << "\n\n\n\n";

    ret = solution({ "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" });
    for (const auto& r : ret)
    {
        cout << r << endl;
    }


    ret = solution({ "F-15", "foo9.txt", "foo010bar020.zip" });
    for (const auto& r : ret)
    {
        cout << r << endl;
    }
    cout << "\n\n\n\n";



    //ret = solution({ "MUZI01.zip", "muzi1.png" });
    ret = solution({ "muzi1.png", "MUZI01.zip" });
    for (const auto& r : ret)
    {
        cout << r << endl;
    }
    cout << "\n\n\n\n";

}