n, m = map(int, input().split())
p = list(map(int, input().split()))
par = [i for i in range(n+1)]
rank = [0]*(n+1)
ans = 0

def find(x):
  if par[x] == x:
    return x
  else:
    par[x] = find(par[x])
    return par[x]

def union(x, y):
  par_x = find(x)
  par_y = find(y)
  if rank[par_x] < rank[par_y]:
    par[par_x] = par_y
  else:
    par[par_y] = par_x
    if rank[par_x] == rank[par_y]:
      rank[par_x] += 1

for i in range(m):
  x, y = map(int, input().split())
  union(x, y)

for i in range(n):
  ans += (find(p[i]) == find(i+1))

print(ans)