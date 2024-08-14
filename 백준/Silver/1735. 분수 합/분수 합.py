A, B = list(map(int, input().split()))
X, Y = list(map(int, input().split()))

numerator = A*Y + B*X
denominator = B*Y

def gcd(a, b):
    return gcd(b, a%b) if b else a

greatest_common_divisor = gcd(numerator, denominator)
print(numerator // greatest_common_divisor, denominator // greatest_common_divisor)