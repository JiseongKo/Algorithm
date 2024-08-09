import sys
input = sys.stdin.readline

N = int(input())
s = list(map(int, input().split()))
ds = {}
for i in s:
    ds[i] = 1

M = int(input())
o = list(map(int, input().split()))
do = {}
for i in o:
    do[i] = 1

for i in do:
    if i in ds:
        print(1, end=' ')
    else:
        print(0, end=' ')