import sys
sys.setrecursionlimit(50*50)

R, C = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
sy, sx, gy, gx = sy-1, sx-1, gy-1, gx-1
c = []
for i in range(R):
  c.append(input())
d = [[float("INF")]*C for _ in range(R)]

def bfs():
  que = [(sy, sx)]
  d[sy][sx] = 0

  while len(que) > 0:
    p = que.pop(0)

    if p[0] == gy and p[1] == gx:
      break
    
    for dy in range(-1, 2):
      for dx in range(-1, 2):
        if (dy==0 and dx==0) or (dy!=0 and dx!=0):
          continue
        else:
          ny = p[0]+dy
          nx = p[1]+dx
        
        if 0<=ny<R and 0<=nx<C and c[ny][nx]!="#" and d[ny][nx]==float("INF"):
          que.append((ny, nx))
          d[ny][nx] = d[p[0]][p[1]]+1

bfs()
print(d[gy][gx])