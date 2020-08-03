#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul)
{
    for (int n{}; n < seoul.size(); ++n)
    {
        if (strcmp("Kim", seoul[n].c_str()) == 0)
            return  "김서방은 " + to_string(n) + "에 있다";
    }

    return "김서방은 서울에 없다";
}

