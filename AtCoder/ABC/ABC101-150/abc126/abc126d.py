import sys
sys.setrecursionlimit(10**5+1)

n = int(input())
if n==1:
  print(0)
  exit()
from collections import defaultdict
edge = defaultdict(list)
for i in range(n-1):
  u, v, w = list(map(int, input().split()))
  edge[u].append((v, w))
  edge[v].append((u, w))
graph = [-1 for i in range(n+1)]

def dfs(x, c):
  nexts = edge.get(x)
  if nexts is None:
    return
  if graph[x]!=-1:
    return
  else:
    graph[x] = c
  for y, w in nexts:
    if w%2:
      dfs(y, not c)
    else:
      dfs(y, c)

dfs(1, 0)
for i in range(1, n+1):
  print(int(graph[i]))