def dfs(t, depth):
    visited[t] = depth
    graph[t].sort(reverse=True)
    for i in graph[t]:
        if visited[i] == -1:
            dfs(i, depth + 1)

import sys
sys.setrecursionlimit(150000)
input = sys.stdin.readline

N, M, R = map(int, input().split())
graph = [[] for _ in range(N + 1)]
visited = [-1] * (N + 1)

for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

dfs(R, 0)

for i in range(1, N + 1):
    print(visited[i])