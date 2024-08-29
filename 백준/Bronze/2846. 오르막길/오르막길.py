N = int(input())
l = list(map(int, input().split()))
r = []
p = 0
t = []
for i in l:
    if i > p:
        t.append(i)
    else:
        r.append(max(t)-min(t))
        t = []
        t.append(i)
    p = i
if len(t) > 1:
    r.append(max(t) - min(t))
print(max(r))