def direction(P1, P2, P3):
    x1, y1 = P1
    x2, y2 = P2
    x3, y3 = P3
    
    cross_product = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2)
    
    if cross_product > 0:
        return 1
    elif cross_product < 0:
        return -1
    else:
        return 0

x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())

result = direction((x1, y1), (x2, y2), (x3, y3))
print(result)