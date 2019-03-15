from collections import defaultdict
n, m = list(map(int, input().split()))
graph = defaultdict(list)
e = [tuple(map(int, input().split())) for i in range(m)]
for a, b in e:
  graph[a].append(b)
  graph[b].append(a)

used_v = [False for i in range(n+1)]
used_e = [[False for i in range(n+1)] for i in range(n+1)]
ord_ = [float("INF") for i in range(n+1)]
lowlink = [float("INF") for i in range(n+1)]

def dfs(v, k):
  used_v[v] = True
  ord_[v], lowlink[v] = k, k
  k += 1
  for to in graph[v]:
    if not used_v[to]:
      used_e[v][to] = True
      dfs(to, k)
      lowlink[v] = min(lowlink[v], lowlink[to])
    elif not used_e[to][v]:
      lowlink[v] = min(lowlink[v], ord_[to])

dfs(1, 0)
ans = 0
for a, b in e:
  if ord_[a]<lowlink[b] or ord_[b]<lowlink[a]:
    ans+=1
print(ans)