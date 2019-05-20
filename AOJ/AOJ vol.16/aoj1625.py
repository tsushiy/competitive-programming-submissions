while True:
  n, m, t, p = list(map(int, input().split()))
  if n==0:
    break
  gx, gy = 500, 500

  paper = [[0 for i in range(1000)] for i in range(1000)]
  for i in range(n):
    for j in range(m):
      paper[500+i][500+j] = 1
  for _ in range(t):
    d, c = list(map(int, input().split()))
    if d==1:
      gx = gx+c
      for i in range(c):
        for j in range(1000):
          paper[gx+i][j] += paper[gx-i-1][j]
          paper[gx-i-1][j] = 0
    if d==2:
      gy = gy+c
      for i in range(1000):
        for j in range(c):
          paper[i][gy+j] += paper[i][gy-j-1]
          paper[i][gy-j-1] = 0

  for i in range(p):
    x, y = list(map(int, input().split()))
    print(paper[gx+x][gy+y])