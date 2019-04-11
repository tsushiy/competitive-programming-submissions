import sys
sys.setrecursionlimit(500*500)

h, w = map(int, input().split())
c = [[0]*h for _ in range(w)]
reached = [[0]*h for _ in range(w)]
for i in range(h):
  ct = input()
  for j in range(w):
    c[j][i] = ct[j]

for i in range(w):
  for j in range(h):
    if c[i][j] == "s":
      sx = i
      sy = j
    if c[i][j] == "g":
      gx = i
      gy = j

def dfs(x, y):
  if x<0 or x>w-1 or y<0 or y>h-1 or c[x][y] == "#":
    return
  if reached[x][y]:
    return
  
  reached[x][y] = 1
  if x==gx and y == gy:
    print("Yes")
    exit()

  dfs(x+1, y)
  dfs(x-1, y)
  dfs(x, y+1)
  dfs(x, y-1)

dfs(sx, sy)
print("No")