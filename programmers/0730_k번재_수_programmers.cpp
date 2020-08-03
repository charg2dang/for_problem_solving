#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int>& array, vector<vector<int>>& commands)
{
    vector<int> answer;

    for ( vector<int>& command : commands)
    {
        int i = command[0] - 1;
        int j = command[1];
        int k = command[2] -1;

        vector<int> arr{ array.begin() + i, array.begin() + j};
        
        sort(arr.begin(), arr.end());

        for (int n : arr)
        {
            cout << n << " ";
        }
        cout << "\n";


        answer.push_back(arr[k]);
    }

    return answer;
}

