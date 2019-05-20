from collections import defaultdict, deque
n, k = list(map(int, input().split()))
color = [-1 for i in range(n+1)]
MOD = 10**9+7

graph = defaultdict(list)
for i in range(n-1):
  a, b = list(map(int, input().split()))
  graph[a].append(b)
  graph[b].append(a)

def bfs():
  que = deque([(1, 0, 0)])
  while len(que):
    x, par, sib = que.popleft()
    color[x] = k-min(2, par)-sib

    sib = 0
    for nx in graph[x]:
      if color[nx]==-1:
        que.append((nx, par+1, sib))
        sib += 1

bfs()
ans = 1
for i in range(1, n+1):
  ans = (ans*color[i])%MOD
print(ans)