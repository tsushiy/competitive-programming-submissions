n, k = list(map(int, input().split()))
d = [0 for i in range(100010)]

for i in range(n):
  a, b = list(map(int, input().split()))
  d[a] += b

for j, e in enumerate(d):
  k -= e
  if k<=0:
    print(j)
    break