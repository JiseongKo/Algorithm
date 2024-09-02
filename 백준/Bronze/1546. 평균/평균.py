N = int(input())
scores = list(map(int, input().split()))

M = scores[0]
for i in scores:
    if i>M:
        M = i

for i in range(N):
    scores[i] = scores[i]/M*100

sum = 0

for i in scores:
    sum += i

print(sum/N)