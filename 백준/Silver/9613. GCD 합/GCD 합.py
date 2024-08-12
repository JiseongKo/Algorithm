import math

t = int(input())
for _ in range(t):
    l = list(map(int, input().split()))
    s = 0
    for i in range(1, len(l) - 1):
        for j in range(i + 1, len(l)):
            s += math.gcd(l[i], l[j])
    print(s)