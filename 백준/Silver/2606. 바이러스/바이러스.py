from collections import deque

num_computers = int(input())
num_connections = int(input())
network = [[] for _ in range(num_computers + 1)]
visited = [0] * (num_computers + 1)

for _ in range(num_connections):
    a, b = map(int, input().split())
    network[a].append(b)
    network[b].append(a)

visited[1] = 1
queue = deque([1])

while queue:
    current = queue.popleft()
    for adjacent in network[current]:
        if visited[adjacent] == 0:
            queue.append(adjacent)
            visited[adjacent] = 1

print(sum(visited) - 1)