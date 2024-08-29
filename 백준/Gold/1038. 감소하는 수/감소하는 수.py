from itertools import combinations

def find_nth_decreasing_number(N):
    decreasing_numbers = []
    
    for length in range(1, 11):
        for comb in combinations(range(10), length):
            number = int(''.join(map(str, sorted(comb, reverse=True))))
            decreasing_numbers.append(number)
    
    decreasing_numbers.sort()
    
    if N >= len(decreasing_numbers):
        return -1
    
    return decreasing_numbers[N]

N = int(input().strip())

result = find_nth_decreasing_number(N)

print(result)
