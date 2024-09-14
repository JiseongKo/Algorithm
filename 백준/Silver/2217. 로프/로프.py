def max_weight(N, weights):
    weights.sort()

    max_weight = 0
    for i in range(N):
        current_weight = weights[i] * (N - i)
        if current_weight > max_weight:
            max_weight = current_weight

    return max_weight

N = int(input())
weights = [int(input()) for _ in range(N)]

print(max_weight(N, weights))