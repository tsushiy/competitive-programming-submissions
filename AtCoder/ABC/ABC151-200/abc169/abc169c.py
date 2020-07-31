a, b = input().split()
a = int(a)
b = b.replace(".", "")
b = int(b)
ans = a * b
print(ans // 100)