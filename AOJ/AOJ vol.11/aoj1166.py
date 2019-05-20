from collections import deque
while True:
  w, h = list(map(int, input().split()))
  if w==0:
    break
  visited = [[0 for i in range(w)] for i in range(h)]
  visited[0][0] = 1
  ywall = [[] for i in range(h)]
  xwall = [[] for i in range(h-1)]
  for i in range(h*2-1):
    if i%2==0:
      ywall[i//2] = list(map(int, input().split()))
    else:
      xwall[i//2] = list(map(int, input().split()))
  gx, gy = w-1, h-1
  dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
  que = deque([(0, 0)])
  while len(que):
    x, y = que.popleft()
    for dxt, dyt in zip(dx, dy):
      nx, ny = x+dxt, y+dyt
      if 0<=nx<w and 0<=ny<h:
        if visited[ny][nx]!=0:
          continue
        if (dxt==1 and ywall[y][x]!=1) or (dxt==-1 and ywall[y][x-1]!=1) or (dyt==1 and xwall[y][x]!=1) or (dyt==-1 and xwall[y-1][x]!=1):
          visited[ny][nx] = visited[y][x]+1
          que.append((nx, ny))
  print(visited[gy][gx])