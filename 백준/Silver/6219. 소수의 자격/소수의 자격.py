import sys
import math
input = sys.stdin.readline

A, B, D = map(int, input().split())
r = 0
for i in range(A, B+1):
    if i == 1:
        continue
    p = True
    for j in range(2, math.isqrt(i)+1):
        if i%j == 0:
            p = False
            break
    if p == True and str(D) in str(i):
        r += 1
print(r)