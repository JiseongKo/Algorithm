l = ['a', 'e', 'i', 'o', 'u']
s = input()
c = 0
for i in s:
    if i in l:
        c += 1
print(c)