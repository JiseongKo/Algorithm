def BFS(graph, t, visited):
    global o
    q = deque([t])
    visited[t] = o
    while q:
        v = q.popleft()
        for i in graph[v]:
            if visited[i] == 0:
                q.append(i)
                o += 1
                visited[i] = o

import sys
from collections import deque
sys.setrecursionlimit(150000)
input = sys.stdin.readline
N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [0] * (N+1)
o = 1
for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
for i  in range(N+1):
    graph[i].sort(reverse=True)
BFS(graph, R, visited)
for i in range(1, N+1):
    print(visited[i])