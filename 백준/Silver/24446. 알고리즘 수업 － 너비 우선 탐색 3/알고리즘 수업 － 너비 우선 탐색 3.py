def BFS(graph, R):
    q = deque()
    depth = 0
    q.append((R, depth))
    visited[R] = True
    while q:
        current_vertex, depth = q.popleft()
        r[current_vertex] = depth
        for next_vertex in graph[current_vertex]:
            if not visited[next_vertex]:
                q.append((next_vertex, depth + 1))
                visited[next_vertex] = True

import sys
from collections import deque
input = sys.stdin.readline
N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [False for _ in range(N+1)]
r = [-1 for _ in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
for i in range(N+1):
    graph[i].sort()
BFS(graph, R)
for i in range(1, N+1):
    print(r[i])