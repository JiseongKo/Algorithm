s = 0
for i in range(5):
    n = int(input())
    if n < 40:
        s+=40
    else:
        s+=n
print(s//5)