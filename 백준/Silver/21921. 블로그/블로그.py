import sys
input = sys.stdin.readline

N, X = map(int, input().split())
visitors = list(map(int, input().split()))
s = 0
e = X
sum_visitors = []
total = 0
for i in range(s, e):
    total += visitors[i]
sum_visitors.append(total)

while e < N:
    total -= visitors[s]
    total += visitors[e]
    sum_visitors.append(total)
    s += 1
    e += 1

if max(sum_visitors) == 0:
    print('SAD')
else:
    print(max(sum_visitors))
    print(sum_visitors.count(max(sum_visitors)))