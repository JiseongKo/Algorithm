def get_maximum_sum(words):
    alphabet_weight = {}

    for word in words:
        length = len(word)
        for i, char in enumerate(word):
            if char in alphabet_weight:
                alphabet_weight[char] += 10 ** (length - i - 1)
            else:
                alphabet_weight[char] = 10 ** (length - i - 1)

    sorted_alphabet = sorted(alphabet_weight.items(), key=lambda x: x[1], reverse=True)

    number_assignment = {}
    current_number = 9
    for char, _ in sorted_alphabet:
        number_assignment[char] = current_number
        current_number -= 1

    total_sum = 0
    for word in words:
        num_str = ''.join(str(number_assignment[char]) for char in word)
        total_sum += int(num_str)

    return total_sum

N = int(input())
words = [input().strip() for _ in range(N)]

result = get_maximum_sum(words)
print(result)