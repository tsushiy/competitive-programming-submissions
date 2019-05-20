from collections import defaultdict, deque
n = int(input())
a, b = list(map(int, input().split()))
a, b = a-1, b-1
m = int(input())
MOD = 10**9+7

dist = [1e9]*n
num = [0]*n
edge = defaultdict(list)

dist[a] = 0
num[a] = 1

for i in range(m):
  x, y = list(map(int, input().split()))
  x, y = x-1, y-1
  edge[x].append(y)
  edge[y].append(x)

q = deque([a])
while q:
  x = q.popleft()
  for nx in edge[x]:
    if dist[nx]==1e9:
      dist[nx] = dist[x]+1
      num[nx] = num[x]
      q.append(nx)
    elif dist[nx]==dist[x]+1:
      num[nx] = (num[nx]+num[x])%MOD

print(num[b])