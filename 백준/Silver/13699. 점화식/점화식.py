t = [1, 1, 2, 5]
for i in range(4, 36):
    r = 0
    for j in range(i):
        r += t[j]*t[i-j-1]
    t.append(r)
n = int(input())
print(t[n])