n = int(input())
a = []
for i in range(1, 10):
  for j in range(1, 7):
    a.append(int(str(i)*j))
a.sort()
print(a[n-1])