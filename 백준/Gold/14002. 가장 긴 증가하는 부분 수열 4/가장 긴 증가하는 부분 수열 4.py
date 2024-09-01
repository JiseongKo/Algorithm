N = int(input())
A = list(map(int, input().split()))

l = [1] * N
prev = [-1] * N

for i in range(1, N):
    for j in range(i):
        if A[i] > A[j] and l[j] + 1 > l[i]:
            l[i] = l[j] + 1
            prev[i] = j

max_length = max(l)
end_index = l.index(max_length)

sequence = []
while end_index != -1:
    sequence.append(A[end_index])
    end_index = prev[end_index]

print(max_length)
print(' '.join(map(str, reversed(sequence))))