from collections import deque

N = int(input())
s = deque(list(map(int, input().split())))
r = 0
for i in range(N-1):
    x = s.popleft()
    y = s.popleft()
    r += x*y
    s.appendleft(x+y)
print(r)