N = int(input())
if N < 100:
    print(N)
else:
    c = 0
    for i in range(100, N+1):
        if (int(str(i)[0])-int(str(i)[1])) == (int(str(i)[1])-int(str(i)[2])):
            c += 1
    print(99+c)