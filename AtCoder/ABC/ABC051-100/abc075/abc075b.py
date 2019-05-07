h, w = list(map(int, input().split()))
grid = [[0]*w for _ in range(h)]
for i in range(h):
  s = input()
  for j in range(len(s)):
    if s[j]=="#":
      grid[i][j]="#"
      for dx in range(-1, 2):
        for dy in range(-1, 2):
          if dx==0 and dy==0:
            continue
          nx, ny = j+dx, i+dy
          if 0<=nx<w and 0<=ny<h and grid[ny][nx]!="#":
            grid[ny][nx]+=1
for i in range(h):
  print("".join(map(str, grid[i])))