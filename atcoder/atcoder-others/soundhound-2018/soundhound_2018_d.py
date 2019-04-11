from collections import defaultdict
from heapq import heappop, heappush

n, m, s, t = map(int, input().split())
c = 10**15
graph = defaultdict(list)
for _ in range(m):
  u, v, a, b = map(int, input().split())
  graph[u].append((v, a, b))
  graph[v].append((u, a, b))

dyen = defaultdict(lambda:float("INF"))
dsnuuk = defaultdict(lambda:float("INF"))
dyen[s] = 0
dsnuuk[t] = 0

def dijkstra(s, m):
  used = defaultdict(bool)
  q = []
  heappush(q, (0, s))

  while len(q):
    v = heappop(q)
    cost, cur = v[0], v[1]

    if used[v]:
      continue
    used[v]=True

    for to, a, b in graph[cur]:
      if m==0 and dyen[to]>cost+a:
        dyen[to] = cost+a
        heappush(q, (cost+a, to))
      elif m==1 and dsnuuk[to]>cost+b:
        dsnuuk[to] = cost+b
        heappush(q, (cost+b, to))

dijkstra(s, 0)
dijkstra(t, 1)

costs = [float("INF")]*(n+1)
min_ = float("INF")
for i in range(n, 0, -1):
  min_ = min(min_, dyen[i]+dsnuuk[i])
  costs[i] = min_

for i in range(1, n+1):
  print(c-costs[i])