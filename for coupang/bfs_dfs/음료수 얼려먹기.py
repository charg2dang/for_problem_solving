from collections import deque;

dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]; # 우 하 좌 상
count = 0;
h, w = 0, 0;

def bfs(graph, y, x, visited):
    global h;
    global w;

    q = deque();
    q.append((y, x));
    visited[y][x] = True;

    while q:
        pos = q.popleft();

        yy = pos[0];
        xx = pos[1];

        # 상 하 좌우 확인.
        for dir in dirs:
            yyy = yy + dir[0];
            xxx = xx + dir[1];

            # 범위 확인
            if 0 > yyy or yyy >= h:
                continue;
            if 0 > xxx or xxx >= w:
                continue;

            # 
            if False == visited[yyy][xxx] and graph[yyy][xxx] == 0:
                print((yyy, xxx));
                q.append((yyy, xxx));
                visited[yyy][xxx] = True;



h, w = map(int, input().split());

visited = [[False for i in range(w)] for i in range(h) ];
graph = [];

for i in range(h):
    s = input();
    l = list( int(c) for c in s);
    graph.append(l);
    #graph.append(list(map(int, input())));


for y in range(h):
    for x in range(w):
        if graph[y][x] == 0 and visited[y][x] == False :
            bfs(graph, y, x, visited);
            count += 1;
            

print(count);

"""
4 5
00110
00011
11111
00000

3 3
001
010
101
"""

#n, m = map(int, input().split())

#g = [];
#for i in range(n):
#    g.append(list(map(int, input())));


#def dfs(x, y):
#    if x <= -1 or x >= n or y <= -1 or y >= m:
#        return False;

#    if g[x][y] == 0:
#        g[x][y] = 1;
#        dfs(x + 1, y);
#        dfs(x, y + 1);
#        dfs(x - 1, y);
#        dfs(x, y - 1);
#        return True;
#    return False;

#result = 0;
#for i in range(n) :
#    for j in range(m):
#        if dfs (i, j) == True:
#            result += 1;


#print(result)