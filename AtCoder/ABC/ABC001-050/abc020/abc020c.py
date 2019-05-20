h, w, t = list(map(int, input().split()))
s = [list(input()) for i in range(h)]
n = h*w
for i in range(h):
  for j in range(w):
    if s[i][j]=="S":
      sx, sy = j, i
    if s[i][j]=="G":
      gx, gy = j, i

from heapq import heappop, heappush
def dijkstra(s, graph):
  prev = [-1]*n
  d = [float("INF")]*n
  d[s] = 0
  q = []
  heappush(q, [0, s])

  while q:
    dt, v = heappop(q)
    if d[v] < dt:
      continue
    for to, cost in graph[v]:
      if d[to] > dt+cost:
        d[to] = dt+cost
        prev[to] = v
        heappush(q, [d[to], to])
  return d

from collections import defaultdict
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

ok = 1
ng = t
cnt = 0
while ok+1<ng:
  if cnt==100:
    break
  cnt += 1
  d = defaultdict(list)
  mid = (ok+ng)//2
  for i in range(h):
    for j in range(w):
      for k in range(4):
        nx = j+dx[k]
        ny = i+dy[k]
        if nx<0 or nx>w-1 or ny<0 or ny>h-1:
          continue
        if s[ny][nx]=="#":
          d[i*w+j].append((ny*w+nx, mid))
        else:
          d[i*w+j].append((ny*w+nx, 1))
  c = dijkstra(sy*w+sx, d)
  if c[gy*w+gx]<=t:
    ok = mid
  else:
    ng = mid
print(ok)
