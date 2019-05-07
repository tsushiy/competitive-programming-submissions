# TLE解法

from collections import defaultdict
from heapq import heappop, heappush

n, m, s, t = map(int, input().split())
c = 10**15
graph = defaultdict(list)
for _ in range(m):
  u, v, a, b = map(int, input().split())
  graph[u].append((v, a, b))
  graph[v].append((u, a, b))

def dijkstra(s, year):
  d = defaultdict(lambda:float("INF"))
  d[(s, 0)] = 0
  q = []
  heappush(q, (0, (s, 0)))

  while len(q):
    #print(q)
    cost, v = heappop(q)
    cur, m = v[0], v[1]
    used = defaultdict(bool)

    if cur==t and m==1:
      return cost
    if used[v]:
      continue
    used[v]=True

    for to, a, b in graph[cur]:
      if cur>year and m==0 and d[(cur, 1)]>cost:
        d[(cur, 1)]=cost
        heappush(q, (cost, (cur, 1)))
      if m == 0:
        if d[(to, 0)]>cost+a:
          d[(to, 0)]=cost+a
          heappush(q, (cost+a, (to, 0)))
      else:
        if d[(to, 1)]>cost+b:
          d[(to, 1)]=cost+b
          heappush(q, (cost+b, (to, 1)))
  
  return d[(t, 1)]

for i in range(n):
  tt = dijkstra(s, i)
  print(c-tt)