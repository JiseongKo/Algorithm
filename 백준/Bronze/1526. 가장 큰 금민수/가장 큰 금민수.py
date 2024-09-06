N = int(input())
for i in range(N, 0, -1):
    if '0' not in str(i) and '1' not in str(i) and '2' not in str(i) and '3' not in str(i) and '5' not in str(i) and '6' not in str(i) and '8' not in str(i) and '9' not in str(i):
        print(i)
        break