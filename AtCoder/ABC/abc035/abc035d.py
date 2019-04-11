from heapq import heappop, heappush
n, m, t = map(int, input().split())
A = list(map(int, input().split()))
go = [[] for _ in range(n+1)]
back = [[] for _ in range(n+1)]
for _ in range(m):
  a, b, c = map(int, input().split())
  go[a].append([b, c])
  back[b].append([a, c])

def dijkstra(s, graph):
  d = [float("INF") for _ in range(n+1)]
  d[s] = 0
  q = []
  heappush(q, [0, s])
  while q:
    dt, v = heappop(q)
    for gt, cost in graph[v]:
      if d[gt] > dt+cost:
        d[gt] = dt+cost
        heappush(q, [d[gt], gt])
  return d

c1 = dijkstra(1, go)
c2 = dijkstra(1, back)
ans = 0
for i in range(1, n+1):
  ans = max(ans, (t-c1[i]-c2[i])*A[i-1])
print(ans)