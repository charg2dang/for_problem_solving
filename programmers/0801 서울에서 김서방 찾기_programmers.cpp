#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul)
{
    for (int n{}; n < seoul.size(); ++n)
    {
        if (strcmp("Kim", seoul[n].c_str()) == 0)
            return  "�輭���� " + to_string(n) + "�� �ִ�";
    }

    return "�輭���� ���￡ ����";
}

