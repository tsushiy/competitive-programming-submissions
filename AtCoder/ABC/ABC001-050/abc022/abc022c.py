n, m = list(map(int, input().split()))

dist = [[float("INF") if i!=j else 0 for i in range(n)] for j in range(n)]
start = dict()

for i in range(m):
  a, b, c = list(map(int, input().split()))
  a, b = a-1, b-1
  if a==0:
    start[b] = c
    continue
  dist[a][b] = c
  dist[b][a] = c
for k in range(n):
  for i in range(n):
    for j in range(n):
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

ans = 1e9
for e1, c1 in start.items():
  for e2, c2 in start.items():
    if e1==e2:
      continue
    ans = min(ans, dist[e1][e2]+c1+c2)

if ans==1e9:
  print(-1)
else:
  print(ans)