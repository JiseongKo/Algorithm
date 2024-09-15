def min_operations(A, B):
    operations = 0
    
    while B > A:
        if B % 10 == 1:
            B //= 10
        elif B % 2 == 0:
            B //= 2
        else:
            break
        operations += 1
    
    if B == A:
        return operations + 1
    else:
        return -1

A, B = map(int, input().split())
print(min_operations(A, B))