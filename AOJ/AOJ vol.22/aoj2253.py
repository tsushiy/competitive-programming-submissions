from collections import deque

while True:
  t, n = map(int, input().split())
  if t==0 and n==0:
      break
  else:
    d = [[-1]*200 for _ in range(200)]
    for i in range(n):
      x, y = map(int, input().split())
      d[x+100][y+100] = float("INF")
    sx, sy = map(int, input().split())
    sx, sy = sx+100, sy+100

    q = deque([])
    q.append((sx, sy))
    d[sx][sy] = 0

    while len(q)>0:
      cur = q.popleft()
      curx, cury = cur[0], cur[1]
      for dx_ in range(-1, 2):
        for dy_ in range(-1, 2):
          if (dx_*dy_==-1) or (dx_==0 and dy_==0):
            continue
          else:
            nx, ny = curx+dx_, cury+dy_
            if d[curx][cury]<t and 0<=nx<200 and 0<=ny<200 and d[nx][ny]==-1:
              q.append((nx, ny))
              d[nx][ny] = d[curx][cury]+1

    ans = 0
    for i in range(len(d)):
      for ele in d[i]:
        if 0<=ele<=t:
          ans+=1
    print(ans)