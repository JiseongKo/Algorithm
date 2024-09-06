import sys
input = sys.stdin.readline

N = int(input())
x_list = list(map(int, input().split()))
sorted_list = sorted(set(x_list))
compress_dict = {value: idx for idx, value in enumerate(sorted_list)}
print(' '.join(str(compress_dict[x]) for x in x_list))