a = [[0]*4 for i in range(4)]
for i in range(4):
  a[i] = list(map(int, input().split()))
for dx, dy in ((0, 1), (0, -1), (-1, 0), (1, 0)):
  for i in range(4):
    for j in range(4):
      nx = i+dx
      ny = j+dy
      if 0<=nx<4 and 0<=ny<4:
        if a[i][j]==a[nx][ny]:
          print("CONTINUE")
          exit()
print("GAMEOVER")