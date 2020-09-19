
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    unordered_map<string, int> wears;

    for (const auto& clothe : clothes)
    {
        wears[clothe[1]] += 1;
    }

    int answer{ 1 };

    for (const auto& wear : wears)
    {
        answer *= (wear.second + 1);
    }

    return answer - 1;
}

#include <iostream>

// 공식 (한 옷의 종류수 + 1(안입는경우의수))* (한 옷의 종류수 + 1(안입는경우의수)) -(아무것도 안 입는경우의수)
void main()
{
    cout << solution({ {"yellow_hat" , "headgear"}, {"blue_sunglasses", "eyewear" }, {"green_turban", "headgear" } }) << endl;
    cout << solution({ {"crow_mask", "face"}, { "blue_sunglasses", "face" }, { "smoky_makeup", "face" } }) << endl;
}