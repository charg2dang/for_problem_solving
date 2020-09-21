

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    for (int y_width{ 1 }; y_width <= yellow; ++y_width)
    {
        if ( yellow % y_width != 0) // 나머지가 0 노나 떨어지고
        {
            continue;
        }

        int y_height = yellow / y_width; 
        if (y_height > y_width)         // 가로보다 크면 다음.
        {
            continue;
        }

        int expected_brown = (y_height * 2) + ((y_width + 2) * 2);
        if ( brown != expected_brown)
        {
            continue;
        }
        
        answer.push_back(y_width + 2);
        answer.push_back(y_height + 2);

        break;
    }

    return move(answer);
}

#include <iostream>

void main()
{
    auto ret = solution(10, 2);
    for (int r : ret)
    {
        cout << r << endl;
    }
    cout << "\n\n\n\n";
}