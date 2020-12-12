"""
문제 설명
코딩 오디션 프로그램에 해커가 침투하여 일부 참가자의 점수를 조작하였습니다. 조사관으로 투입된 당신은, 해커가 조작한 점수에 어떤 패턴이 남은 것을 발견하였고, 아래와 같은 패턴을 띄는 조작된 점수를 제거하기로 하였습니다.
인접된 등수 사이의 점수차가 k번이상 반복되어 나온다면, 해당하는 인접된 등수는 모두 조작된 점수입니다.
이 때, 조작되지 않은 점수는 몇 개인지 구하려 합니다.
조작의 기준인 반복 횟수 k, 내림차순으로 정렬된 점수가 담긴 배열 score가 매개변수로 주어집니다. 이때, 조작되지 않은 점수의 개수를 return 하도록 solution 함수를 완성해주세요. 조작되지 않은 점수가 하나도 없다면, 0을 return 합니다.
제한사항
k는 2 이상 100,000 이하인 정수입니다.
score는 길이가 1 이상 500,000 이하인 1차원 배열입니다.
score를 구성하는 원소는 0 이상 2,000,000,000 이하인 정수입니다.
score를 구성하는 원소는 내림차순으로 정렬되어 주어집니다.
score를 구성하는 원소에는 중복된 값이 없습니다.
"""
from collections import defaultdict

def so(k , score) -> int:
    #점수차를 키값으로 해시맵에 카운팅
    m = defaultdict(int);

    for i in range(1, len(score)):
        score_data = abs(score[i - 1] - score[i]);
        m[score_data] += 1;

    #해커의 손이 닿은 점수차 리스트를 뽑음
    hacked_dt_list = [];
    for key in m :
        if m[key] >= k:
            hacked_dt_list.append(key);


#
    for i in range(1, len(score)) :
        score_data = abs(abs(score[i-1]) - score[i]);
        if score_data in hacked_dt_list:
            if score[i-1] > 0 :
                #print(score_data);
                score[i-1] = -score[i-1];
            score[i] = -score[i];

    result_count = 0;
    for i in range(0, len(score)):
        if score[i] < 0 :
            result_count += 1;

    #print(result_count);
    return len(score) - result_count;
    

print(so(3, [24, 22, 20, 10, 5, 3, 2, 1]));
