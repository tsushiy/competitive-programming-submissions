n = int(input())
a = [int(input()) for i in range(n)]
s = sorted(set(a))
d = dict()
for i, e in enumerate(s):
  d[e] = i
b = [d[a[i]] for i in range(n)]
for i in range(n):
  print(b[i])