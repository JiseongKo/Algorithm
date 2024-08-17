import math

N = int(input())
A = list(map(int, input().split()))

# 소수를 저장할 리스트
prime_numbers = []

# 수열에서 소수 추출
for number in A:
    is_prime = True
    # 2부터 number의 제곱근까지 나누어 떨어지는지 확인
    for divisor in range(2, math.isqrt(number) + 1):
        if number % divisor == 0:
            is_prime = False
            break
    # 소수이면 prime_numbers 리스트에 추가
    if is_prime:
        prime_numbers.append(number)

# 소수가 없으면 -1 출력
if len(prime_numbers) == 0:
    print(-1)
else:
    # 소수들의 최소공배수 계산 및 출력
    print(math.lcm(*prime_numbers))