def solution(v):
    xs = {};
    ys = {};  
    answer = [];
    
    for pos in  v:
        xs[pos[0]] = 0;
        ys[pos[1]] = 0;

    for pos in  v:
        xs[pos[0]] += 1;
        ys[pos[1]] += 1;

    for x in xs:
        if xs[x] == 1:
            answer.append(x);
            
    for y in ys:
        if ys[y] == 1:
            answer.append(y);

    return answer;


print( solution([[1, 4], [3, 4], [3, 10]]) );