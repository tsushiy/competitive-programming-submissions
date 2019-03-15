w, h, n = map(int, input().split())
g = [[1]*h for _ in range(w)]
for _ in range(n):
  x, y, a = map(int, input().split())
  for i in range(w):
    for j in range(h):
      if (a==1 and i<x) or (a==2 and i>=x) or (a==3 and j<y) or (a==4 and j>=y):
        g[i][j] = 0

print(sum(map(sum, g)))