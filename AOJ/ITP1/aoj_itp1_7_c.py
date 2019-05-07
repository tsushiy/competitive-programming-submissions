r, c = list(map(int, input().split()))
t = [[0]*(c+1) for i in range(r+1)]
for i in range(r):
  a = list(map(int, input().split()))
  for j in range(c):
    t[i][j] = a[j]
    t[r][j] += a[j]
  t[i][c] = sum(a)
t[r][c] = sum(t[r])
for i in range(r+1):
  print(" ".join(map(str, t[i])))