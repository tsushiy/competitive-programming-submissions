while True:
  n = int(input())
  if n==0:
    break

  grid = [[0 for i in range(21)] for i in range(21)]
  for i in range(n):
    x, y = list(map(int, input().split()))
    grid[x][y] = 1

  x, y = 10, 10
  grid[x][y] = 0
  m = int(input())
  for i in range(m):
    d, l = input().split()
    l = int(l)
    nx, ny = x, y
    if d=="N":
      ny += l
      for j in range(y, ny+1):
        grid[x][j] = 0
    elif d=="S":
      ny -= l
      for j in range(y, ny-1, -1):
        grid[x][j] = 0
    elif d=="E":
      nx += l
      for j in range(x, nx+1):
        grid[j][y] = 0
    else:
      nx -= l
      for j in range(x, nx-1, -1):
        grid[j][y] = 0
    x, y = nx, ny

  flag = True
  for i in range(21):
    for j in range(21):
      if grid[i][j] == 1:
        flag = False
  if flag:
    print("Yes")
  else:
    print("No")