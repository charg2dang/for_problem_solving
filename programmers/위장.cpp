
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

// ���� (�� ���� ������ + 1(���Դ°���Ǽ�))* (�� ���� ������ + 1(���Դ°���Ǽ�)) -(�ƹ��͵� �� �Դ°���Ǽ�)
void main()
{
    cout << solution({ {"yellow_hat" , "headgear"}, {"blue_sunglasses", "eyewear" }, {"green_turban", "headgear" } }) << endl;
    cout << solution({ {"crow_mask", "face"}, { "blue_sunglasses", "face" }, { "smoky_makeup", "face" } }) << endl;
}