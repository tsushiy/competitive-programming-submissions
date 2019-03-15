n = int(input())
ans = float("-INF")
f = [[0 for i in range(10)] for i in range(n)]
p = [[0 for i in range(11)] for i in range(n)]
for i in range(n):
  ft = list(map(int, input().split()))
  for j in range(10):
    f[i][j] = ft[j]
for i in range(n):
  pt = list(map(int, input().split()))
  for j in range(11):
    p[i][j] = pt[j]

for i in range(1, 2**10):
  t = 0
  for j in range(n):
    c = 0
    for k in range(10):
      if i>>k&1 and f[j][k]:
        c += 1
    t += p[j][c]
  ans = max(ans, t)
print(ans)