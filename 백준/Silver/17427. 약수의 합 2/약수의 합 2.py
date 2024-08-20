N = int(input())
r = 0
for i in range(1, N+1):
    r += (N//i)*i
print(r)