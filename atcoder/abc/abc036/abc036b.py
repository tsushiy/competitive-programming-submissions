n = int(input())
a = [[0]*n for _ in range(n)]
for i in range(n):
  s = input()
  for j, ele in enumerate(s):
    a[j][n-i-1] = ele
for i in range(n):
  print("".join(a[i]))