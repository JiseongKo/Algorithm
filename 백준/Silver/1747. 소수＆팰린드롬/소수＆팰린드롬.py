import math
import sys
input = sys.stdin.readline

N = int(input())
if N == 1:
    print(2)
else:
    while True:
        p = True
        for i in range(2, math.isqrt(N) + 1):
            if N % i == 0:
                p = False
                break
        if p == True and str(N) == str(N)[::-1]:
            print(N)
            break
        N += 1