while True:
  w, h = map(int, input().split())
  if w == 0 and h == 0:
    break
  ywalls = [[0]*w for _ in range(h)]
  xwalls = [[0]*w for _ in range(h)]
  for i in range(2*h-1):
    walls = map(int, input().split())
    if i%2==0:
      for j, ele in enumerate(walls):
        ywalls[i//2][j]=ele
    else:
      for j, ele in enumerate(walls):
        xwalls[i//2][j]=ele

  d = [[-1]*w for _ in range(h)]
  sx, sy = 0, 0
  gx, gy = w-1, h-1
  from collections import deque
  q = deque([])
  q.append((sx, sy))
  d[sx][sy] = 0

  while len(q)>0:
    cur = q.popleft()
    curx, cury = cur[0], cur[1]
    if curx==gx and cury==gy:
      break
    for dx in range(-1, 2):
      for dy in range(-1, 2):
        if (dx==0 and dy!=0) or (dx!=0 and dy==0):
          nx, ny = curx+dx, cury+dy
          if 0<=nx<w and 0<=ny<h and d[ny][nx]==-1:
            tx, ty = curx, cury
            if dx==-1:
              tx -=1
            elif dy==-1:
              ty -=1
            if dx!=0 and ywalls[ty][tx]==0:
              q.append((nx, ny))
              d[ny][nx] = d[cury][curx]+1
            elif dy!=0 and xwalls[ty][tx]==0:
              q.append((nx, ny))
              d[ny][nx] = d[cury][curx]+1

  print(d[gy][gx]+1)