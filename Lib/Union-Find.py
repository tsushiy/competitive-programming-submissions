# Union-Find木

par = [i for i in range(n+1)]
rank = [0]*(n+1)

def find(x):
  if par[x] == x:
    return x
  else:
    par[x] = find(par[x])
    return par[x]

def union(x, y):
  par_x = find(x)
  par_y = find(y)
  if par_x == par_y:
    return
  if rank[par_x] < rank[par_y]:
    par[par_x] = par_y
  else:
    par[par_y] = par_x
    if rank[par_x] == rank[par_y]:
      rank[par_x] += 1

def same(x, y):
  return find(x)==find(y)