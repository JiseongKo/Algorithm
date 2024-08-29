def dfs(x, depth):
    global o
    visited[x] = True
    d[x] = depth
    t[x] = o
    o += 1
    graph[x].sort(reverse=True)
    for i in graph[x]:
        if not visited[i]:
            dfs(i, depth + 1)

import sys
sys.setrecursionlimit(150000)
input = sys.stdin.readline

N, M, R = map(int, input().split())
graph = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)
d = [-1] * (N + 1)
t = [0] * (N + 1)
o = 1

for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

dfs(R, 0)

r = 0
for i in range(1, N + 1):
    r += d[i]*t[i]
print(r)