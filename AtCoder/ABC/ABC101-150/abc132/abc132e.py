from collections import defaultdict, deque
n, m = list(map(int, input().split()))
graph = defaultdict(list)
for i in range(m):
  u, v = list(map(int, input().split()))
  graph[u].append(v+n)
  graph[u+n].append(v+2*n)
  graph[u+2*n].append(v)
s, t = list(map(int, input().split()))
dist = [-1 for i in range(3*n+10)]

def bfs():
  que = deque([s])
  dist[s] = 0
  while len(que) > 0:
    cur = que.popleft()
    for to in graph[cur]:
      if dist[to] == -1:
        dist[to] = dist[cur]+1
        que.append(to)

bfs()
print(dist[t]//3)