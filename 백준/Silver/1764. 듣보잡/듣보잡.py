N, M = map(int, input().split())
d = {}
for i in range(N+M):
    n = input()
    if n not in d:
        d[n] = 1
    else:
        d[n] += 1
r = []
for i in d:
    if d[i] == 2:
        r.append(i)
r.sort()
print(len(r))
for i in r:
    print(i)