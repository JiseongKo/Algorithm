import sys
input = sys.stdin.readline

n, m = map(int, input().split())
T = list(map(int, input().split()))

start = 0
end = m
window_sums = []
current_sum = 0

for i in range(start, end):
    current_sum += T[i]
window_sums.append(current_sum)

while end < n:
    current_sum -= T[start]
    current_sum += T[end]
    window_sums.append(current_sum)
    start += 1
    end += 1

print(max(window_sums))