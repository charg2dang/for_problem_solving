#INF = 9999999999;

#adjacency_matrix =[[ 0 for i in range(3)] for i in range(3)];

#print(INF)


#print(adjacency_matrix);


def dfs(graph, v, visited):
    visited[v] = True;
    print(v, end = ' ');

    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited);


graph = [
    [],
    [2, 3, 8],
    [1, 7],
    [1, 4, 5],
    [3, 5],
    [3, 4],
    [7],
    [2, 6, 8],
    [1, 7],
   ]


visited = [False for i in range(9)];

dfs(graph, 1, visited);