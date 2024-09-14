def minimize_expression(expression):
    parts = expression.split('-')
    first_sum = sum(map(int, parts[0].split('+')))
    rest_sum = sum(sum(map(int, part.split('+'))) for part in parts[1:])
    return first_sum - rest_sum

expression = input()
print(minimize_expression(expression))