from collections import defaultdict
from heapq import heappop, heappush

while True:
  n, m = map(int, input().split())
  if n==0 and m==0:
    break

  s, g = map(int, input().split())
  graph = defaultdict(list)
  for _ in range(m):
    x, y, d, c = map(int, input().split())
    graph[x].append((y, d, c))
    graph[y].append((x, d, c))

  def dijkstra(s):
    d = defaultdict(lambda:float("INF"))
    d[(s, 0, -1)] = 0
    used = defaultdict(bool)

    q = []
    heappush(q, (0, (s, 0, -1)))

    while len(q):
      elapsed, v = heappop(q)

      cur, vel1, prev1 = v[0], v[1], v[2]
      if cur==g and vel1 == 1:
        return elapsed

      if used[v]:
        continue
      used[v] = True

      for to, dist, ct in graph[cur]:
        if to==prev1:
          continue
        for vel2 in range(vel1-1, vel1+2):
          if vel2<1 or ct<vel2:
            continue

          nxt = (to, vel2, cur)
          if used[nxt]:
            continue
          elapsed2 = elapsed+dist/vel2
          if d[nxt] > elapsed2:
            d[nxt] = elapsed2
            heappush(q, (elapsed2, nxt))

    return "unreachable"
  
  print(dijkstra(s))