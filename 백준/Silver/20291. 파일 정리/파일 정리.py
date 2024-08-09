import sys
input = sys.stdin.readline
N = int(input().rstrip())
d = {}
for i in range(N):
    n = input().rstrip().split('.')[1]
    if n not in d:
        d[n] = 1
    else:
        d[n] += 1
sd = sorted(d.items(), key = lambda item:item[0])
for i in sd:
    print(i[0], i[1])