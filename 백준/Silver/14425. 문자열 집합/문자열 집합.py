N, M = map(int, input().split())
S = []
for i in range(N):
    S.append(input())
c = 0
for i in range(M):
    s = input()
    if s in S:
        c += 1
print(c)