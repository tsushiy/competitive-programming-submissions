n = int(input())
from collections import defaultdict
import sys
sys.setrecursionlimit(10**7)
graph = defaultdict(list)
edge = []
for i in range(n-1):
  a, b = list(map(int, input().split()))
  edge.append((a, b))
  graph[a].append(b)
  graph[b].append(a)
c = list(map(int, input().split()))
c.sort(reverse=True)
visited = [0 for i in range(n+1)]
ans = [0 for i in range(n+1)]
score = 0

def dfs(x):
  visited[x] = 1
  for next_ in graph[x]:
    if visited[next_]:
      continue
    dfs(next_)
  if all(visited[i] for i in graph[x]):
    ans[x] = c.pop()
    return
  visited[x] = 0

dfs(1)
for a, b in edge:
  score += min(ans[a], ans[b])
print(score)
print(*ans[1:])